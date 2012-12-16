#include "testApp.h"

#include <deque>

#include "ofxOpenCv.h"

#define _USE_LIVE_VIDEO

#ifdef _USE_LIVE_VIDEO
ofVideoGrabber vidGrabber;
#else
ofVideoPlayer vidPlayer;
#endif

ofxCvColorImage	src_image;

static const int VIDEO_WIDTH = 640, VIDEO_HEIGHT = 480;
static const CvSize VIDEO_SIZE = cvSize(VIDEO_WIDTH, VIDEO_HEIGHT);

// 位置と色の状態を持った構造体
struct FlowPoint
{
	ofVec3f pos;
	ofVec3f color;
};

// 軌跡を描画するためのクラス
class FlowLine
{
public:
	ofVec3f pos; // 軌跡の先頭の位置
	ofVec3f color; // 軌跡の先頭の色
	deque<FlowPoint> points; // 軌跡を構成する点列
	
	float alpha; // アルファ値
	float rise_speed; // 上昇スピード
	
	FlowLine()
	{
		// 軌跡が上っていくスピードをランダムでちらす
		rise_speed = ofRandom(0.5, 5);
	}
	
	void update()
	{
		// 軌跡の先頭に現在のポイントを追加
		FlowPoint p;
		p.pos = (points.front().pos*0.2 + pos*0.8);
		p.color = (points.front().color*0.2 + color*0.8);
		points.push_front(p);
		
		if (points.size() > 2)
		{
			for (int i = 1; i < points.size(); i++)
			{
				// 軌跡がだんだん上っていくように
				points[i].pos.y -= rise_speed;
				// 線をなめらかに
				points[i-1].pos = points[i].pos*0.6 + points[i-1].pos*0.4;
			}
		}
		
		// 軌跡の流さを制限する
		if (points.size() > 100) points.pop_back();
		
		// アルファ値をだんだん小さくする
		alpha += -alpha * 0.05;
	}
	
	void draw()
	{
		// 軌跡の描画
		glBegin(GL_LINE_STRIP);
		for (int i = 0; i < points.size(); i++)
		{
			FlowPoint &p = points[i];
			float a = 1 - (float)i / (float)points.size(); // だんだん透明に
			glColor4f(p.color.x,p.color.y,p.color.z,a*alpha);
			glVertex2fv(p.pos.getPtr());
		}
		glEnd();
	}
	
	// アルファ値が十分に小さいときに消去するためのフラグ用の関数
	bool alive()
	{
		return alpha > 0.05;
	}
};

// 軌跡オブジェクトの配列
vector<FlowLine*> flow_lines;

// 一番近い点を持ったオブジェクトを探すためにソートをかける関数オブジェクト
struct sort_by_distance
{
	sort_by_distance(ofVec2f pos)
	{
		this->pos = pos;
	}
	
	bool operator()(const FlowLine* a, const FlowLine* b)
	{
		float len_a = (a->pos - pos).lengthSquared();
		float len_b = (b->pos - pos).lengthSquared();
		return len_a < len_b;
	}
	
	ofVec2f pos;
};

// 検出したフローに対する処理
void updateFlowPoint(ofVec2f to, ofVec2f from)
{
	// 始点と終点のベクトル距離(=移動量)を求める
	float len = (from - to).length();
	
	if (len > 1 && len < 50) // 距離がいい感じだったら...
	{
		// 終点周辺のピクセルの色を取得
		CvScalar c = cvGet2D(src_image.getCvImage(), (int)to.y, (int)to.x);
		ofVec3f color = ofVec3f(c.val[0] / 255.0f, c.val[1] / 255.0f, c.val[2] / 255.0f);
		
		// temp_linesの中のオブジェクトを始点に近い順にソート
		sort(flow_lines.begin(), flow_lines.end(), sort_by_distance(from));
		
		if (flow_lines.empty() || (flow_lines[0]->pos - from).length() > 30)
		{
			// temp_linesが空か、始点の近くにオブジェクトがない場合新しく追加
			FlowLine *line = new FlowLine();
			line->pos = to;
			line->alpha = 0;
			line->color = color;
			
			FlowPoint point;
			point.pos = to;
			point.color = color;
			line->points.push_back(point);
			
			flow_lines.push_back(line);			
		}
		else
		{
			// 近いオブジェクトがみつかったので色とか位置とかを更新
			FlowLine *line = flow_lines[0];
			line->color = color;
			line->pos = to;
			line->alpha += (1 - line->alpha) * 0.1;
		}
	}	
}

//--------------------------------------------------------------
void testApp::setup(){
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	ofEnableAlphaBlending();
	ofEnableSmoothing();
	
	ofBackground(0,0,0);
	
	#ifdef _USE_LIVE_VIDEO
        vidGrabber.setVerbose(true);
        vidGrabber.initGrabber(VIDEO_WIDTH, VIDEO_HEIGHT);
	#else
        vidPlayer.loadMovie("test.mov");
        vidPlayer.play();
	#endif

	src_image.allocate(VIDEO_WIDTH, VIDEO_HEIGHT);
}

//--------------------------------------------------------------
void testApp::update(){
    bool bNewFrame = false;

	#ifdef _USE_LIVE_VIDEO
       vidGrabber.grabFrame();
	   bNewFrame = vidGrabber.isFrameNew();
    #else
        vidPlayer.idleMovie();
        bNewFrame = vidPlayer.isFrameNew();
	#endif

	if (bNewFrame){
		#ifdef _USE_LIVE_VIDEO
            src_image.setFromPixels(vidGrabber.getPixels(), VIDEO_WIDTH, VIDEO_HEIGHT);
	    #else
            src_image.setFromPixels(vidPlayer.getPixels(), VIDEO_WIDTH, VIDEO_HEIGHT);
        #endif
		
		// オプティカルフロー処理
		// ほぼ http://opencv.jp/sample/optical_flow.html からコピペ
		int count = 150; // 検出するポイントの最大数
		
		static IplImage *eig = cvCreateImage(VIDEO_SIZE, IPL_DEPTH_32F, 1);
		static IplImage *temp = cvCreateImage(VIDEO_SIZE, IPL_DEPTH_32F, 1);
		static CvPoint2D32f *corners1 = (CvPoint2D32f*)cvAlloc(count * sizeof(CvPoint2D32f));
		static CvPoint2D32f *corners2 = (CvPoint2D32f*)cvAlloc(count * sizeof(CvPoint2D32f));
		static IplImage *prev_pyramid = cvCreateImage(cvSize(VIDEO_WIDTH+8, VIDEO_HEIGHT/3), IPL_DEPTH_8U, 1);
		static IplImage *curr_pyramid = cvCreateImage(cvSize(VIDEO_WIDTH+8, VIDEO_HEIGHT/3), IPL_DEPTH_8U, 1);
		static char *status = (char*)cvAlloc(count);
		
		static IplImage *curr_image = cvCreateImage(VIDEO_SIZE, IPL_DEPTH_8U, 1);
		static IplImage *prev_image = cvCreateImage(VIDEO_SIZE, IPL_DEPTH_8U, 1);
		
		// src_imageの中身をグレイスケールに変換しつつ curr_image にコピー
		cvCvtColor(src_image.getCvImage(), curr_image, CV_RGB2GRAY);
		
		// 特徴点を抽出
		float block_size = 10; // 検出するポイント間の最小距離
		cvGoodFeaturesToTrack(curr_image, eig, temp, corners1, &count, 0.001, block_size, NULL);
		
		// curr_image と prev_image についてオプティカルフローを計算
		cvCalcOpticalFlowPyrLK(curr_image, prev_image, curr_pyramid, prev_pyramid, corners1, corners2, count, cvSize(10,10), 4, status, NULL, cvTermCriteria(CV_TERMCRIT_EPS|CV_TERMCRIT_ITER, 64, 0.01), 0);
		
		// curr_image を prev_image にコピー
		cvCopyImage(curr_image, prev_image);
		
		// 検出できたフローに対するループ
		for (int i = 0; i < count; i++)
		{
			if (status[i])
			{
				ofVec2f to = ofVec2f(corners1[i].x, corners1[i].y); // 始点
				ofVec2f from = ofVec2f(corners2[i].x, corners2[i].y); // 終点
				
				// 取得したフローに対して何かしらの処理をする
				updateFlowPoint(to, from);
			}
		}
		
		// FlowLineの更新、削除
		vector<FlowLine*>::iterator it = flow_lines.begin();
		while (it != flow_lines.end())	
		{
			FlowLine *line = (*it);
			
			// 更新
			line->update();
			
			// オブジェクトの生存をチェックして、falseだった場合は消去する
			if (line->alive() == false)
			{
				it = flow_lines.erase(it);
				delete line;
			}
			else
			{
				it++;
			}
		}
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	// ウィンドウのサイズを変更しても動画が全画面で表示されるように
	glScalef((float)ofGetWidth()/(float)VIDEO_WIDTH, (float)ofGetHeight()/(float)VIDEO_HEIGHT, 1);
	
	ofSetColor(127,127,127);
	src_image.draw(0, 0);
	
	// 軌跡の描画
	for (int i = 0; i < flow_lines.size(); i++)
	{
		FlowLine *line = flow_lines[i];
		line->draw();
	}
}


//--------------------------------------------------------------
void testApp::keyPressed  (int key){
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

