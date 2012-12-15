#include "testApp.h"

#include "ofxOpenCv.h"

#define _USE_LIVE_VIDEO

#ifdef _USE_LIVE_VIDEO
ofVideoGrabber vidGrabber;
#else
ofVideoPlayer vidPlayer;
#endif

ofxCvColorImage	src_image, acc_image;

static const int VIDEO_WIDTH = 640, VIDEO_HEIGHT = 480;
static const CvSize VIDEO_SIZE = cvSize(VIDEO_WIDTH, VIDEO_HEIGHT);

static const int BLOCK_SIZE = 40;
static ofVec2f vector_matrix[VIDEO_HEIGHT / BLOCK_SIZE + 1][VIDEO_WIDTH / BLOCK_SIZE + 1];

static bool show_grid = false;

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
        vidPlayer.loadMovie("Movie.mov");
        vidPlayer.play();
	#endif

	src_image.allocate(VIDEO_WIDTH, VIDEO_HEIGHT);
	acc_image.allocate(VIDEO_WIDTH, VIDEO_HEIGHT);
	
	for (int y = 0; y < VIDEO_HEIGHT / BLOCK_SIZE + 1; y++)
	{
		for (int x = 0; x < VIDEO_WIDTH / BLOCK_SIZE + 1; x++)
		{
			ofVec2f &p = vector_matrix[y][x];
			p.x = 0;
			p.y = 0;
		}
	}
}

//--------------------------------------------------------------

void testApp::update(){
    bool bNewFrame = false;

	#ifdef _USE_LIVE_VIDEO
       vidGrabber.update();
	   bNewFrame = vidGrabber.isFrameNew();
    #else
        vidPlayer.update();
        bNewFrame = vidPlayer.isFrameNew();
	#endif

	if (bNewFrame){
		#ifdef _USE_LIVE_VIDEO
            src_image.setFromPixels(vidGrabber.getPixels(), VIDEO_WIDTH, VIDEO_HEIGHT);
	    #else
            src_image.setFromPixels(vidPlayer.getPixels(), VIDEO_WIDTH, VIDEO_HEIGHT);
        #endif
		
		cvFlip(src_image.getCvImage(), NULL, 1);
		
		int corner_count = 200;
		static IplImage *eig = cvCreateImage(VIDEO_SIZE, IPL_DEPTH_32F, 1);
		static IplImage *temp = cvCreateImage(VIDEO_SIZE, IPL_DEPTH_32F, 1);
		static CvPoint2D32f *corners1 = (CvPoint2D32f*)cvAlloc(corner_count * sizeof(CvPoint2D32f));
		static CvPoint2D32f *corners2 = (CvPoint2D32f*)cvAlloc(corner_count * sizeof(CvPoint2D32f));
		static IplImage *prev = cvCreateImage(cvSize(VIDEO_WIDTH+8, VIDEO_HEIGHT/3), IPL_DEPTH_8U, 1);
		static IplImage *curr = cvCreateImage(cvSize(VIDEO_WIDTH+8, VIDEO_HEIGHT/3), IPL_DEPTH_8U, 1);
		static char *status = (char*)cvAlloc(corner_count);
		
		static IplImage *gray_image = cvCreateImage(VIDEO_SIZE, IPL_DEPTH_8U, 1);
		static IplImage *prev_image = cvCreateImage(VIDEO_SIZE, IPL_DEPTH_8U, 1);
		cvCvtColor(src_image.getCvImage(), gray_image, CV_RGB2GRAY);
		
		cvGoodFeaturesToTrack(gray_image, eig, temp, corners1, &corner_count, 0.001, 20, NULL);
		cvCalcOpticalFlowPyrLK(gray_image, prev_image, curr, prev, corners1, corners2, corner_count, cvSize(10,10), 4, status, NULL, cvTermCriteria(CV_TERMCRIT_EPS|CV_TERMCRIT_ITER, 64, 0.01), 0);
		
		cvCopyImage(gray_image, prev_image);
		
		for (int i = 0; i < corner_count; i++)
		{
			if (status[i])
			{
				ofVec2f from = ofVec2f(corners1[i].x, corners1[i].y);
				ofVec2f to = ofVec2f(corners2[i].x, corners2[i].y);
				
				float len = (to - from).length();
				if (len < 40)
				{
					int xx = from.x / BLOCK_SIZE;
					int yy = from.y / BLOCK_SIZE;
					
					// ブロック内の移動量を加算
					vector_matrix[yy][xx] += (from - to) * 0.5;
				}
			}
		}
		
		static IplImage *temp_acc_image = cvCreateImage(VIDEO_SIZE, IPL_DEPTH_32F, 3);
		static IplImage *temp_rgb_image = cvCreateImage(VIDEO_SIZE, IPL_DEPTH_8U, 3);
		
		// 移動平均を使ってスロシャッターのようなエフェクト
		cvRunningAvg(src_image.getCvImage(), temp_acc_image, 0.15);
		cvConvert(temp_acc_image, temp_rgb_image);
		
		// 画像をコピー
		acc_image = temp_rgb_image;
	}
	
	float delta = 0.3;
	
	// ベクトルをX軸方向に平滑化
	for (int y = 0; y < VIDEO_HEIGHT / BLOCK_SIZE + 1; y++)
	{
		for (int x = 1; x < VIDEO_WIDTH / BLOCK_SIZE; x++)
		{
			ofVec2f &pp = vector_matrix[y][x];
			ofVec2f &p1 = vector_matrix[y][x - 1];
			ofVec2f &p2 = vector_matrix[y][x + 1];
			pp = (p1 + p2) * delta * 0.5 + pp * (1 - delta);
		}
	}
	
	// ベクトルをY軸方向に平滑化
	for (int x = 0; x < VIDEO_WIDTH / BLOCK_SIZE + 1; x++)
	{
		for (int y = 1; y < VIDEO_HEIGHT / BLOCK_SIZE; y++)
		{
			ofVec2f &pp = vector_matrix[y][x];
			ofVec2f &p1 = vector_matrix[y - 1][x];
			ofVec2f &p2 = vector_matrix[y + 1][x];
			pp = (p1 + p2) * delta * 0.5 + pp * (1 - delta);
		}
	}
	
	// テクスチャがめくれてしまわないように
	for (int x = 0; x < VIDEO_WIDTH / BLOCK_SIZE + 1; x++)
		vector_matrix[0][x].y = 0;
	
	for (int y = 0; y < VIDEO_HEIGHT / BLOCK_SIZE + 1; y++)
		vector_matrix[y][0].x = 0;
}

//--------------------------------------------------------------
void testApp::draw(){
	ofSetColor(255, 255, 255);

	// ウィンドウのサイズが変っても画面いっぱいに表示されるようにスケーリング
	glScalef((float)ofGetWidth()/(float)VIDEO_WIDTH, (float)ofGetHeight()/(float)VIDEO_HEIGHT, 1);

	// 移動平均の画像をアルファ値0でカラ描画。後にテクスチャをバインドする時にこれがないとアップデートされなかったので
	glColor4f(1, 1, 1, 0);
	acc_image.draw(0, 0);
	
	// アルファ値を元に戻す
	glColor4f(1, 1, 1, 1);
	
	// テクスチャをバインド
	acc_image.getTextureReference().bind();
	
	for (int y = 0; y < VIDEO_HEIGHT / BLOCK_SIZE; y++)
	{
		// ポリゴンの描画
		glBegin(GL_QUAD_STRIP);
		for (int x = 0; x < VIDEO_WIDTH / BLOCK_SIZE + 1; x++)
		{
			ofVec2f t1 = ofVec2f(x * BLOCK_SIZE, y * BLOCK_SIZE);
			ofVec2f t2 = ofVec2f(x * BLOCK_SIZE, (y + 1) * BLOCK_SIZE);
			
			ofVec2f v1 = t1 + vector_matrix[y][x];
			ofVec2f v2 = t2 + vector_matrix[y + 1][x];
			
			glTexCoord2fv(t1.getPtr()); glVertex2fv(v1.getPtr());
			glTexCoord2fv(t2.getPtr()); glVertex2fv(v2.getPtr());
		}
		glEnd();
	}
	
	// テクスチャをアンバインド
	acc_image.getTextureReference().unbind();
	
	// デバッグ用にグリッドを表示
	if (show_grid)
	{
		glColor4f(1, 1, 1, 1);
		for (int y = 0; y < VIDEO_HEIGHT / BLOCK_SIZE + 1; y++)
		{
			for (int x = 0; x < VIDEO_WIDTH / BLOCK_SIZE + 1; x++)
			{
				ofVec2f p = vector_matrix[y][x];
				p += ofVec2f(x * BLOCK_SIZE, y * BLOCK_SIZE);
				
				glBegin(GL_LINES);
				glVertex2f(p.x + 2, p.y);
				glVertex2f(p.x - 2, p.y);
				glVertex2f(p.x, p.y - 2);
				glVertex2f(p.x, p.y + 2);
				glEnd();
			}
		}
	}
}


//--------------------------------------------------------------
void testApp::keyPressed  (int key){
	
	if (key == ' ')
	{
		show_grid = show_grid ? false : true;
	}
	
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

