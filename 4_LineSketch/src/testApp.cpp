#include "testApp.h"

#include <deque>

class Particle
{
public:
	float mass; // 質量
	ofVec3f pos; // 位置
	ofVec3f velocity; // 加速度
	ofVec3f factor; // 因子
	deque<ofVec3f> line_strip; // 軌跡の配列
	
	Particle()
	{
		mass = 1;
	}
	
	void update()
	{
		// 軌跡を追加
		if ((line_strip.front() - pos).lengthSquared() > 60)
		{
			line_strip.push_front(pos);
		}
		
		// 長くなりすぎた軌跡を削除
		if (line_strip.size() > 300) line_strip.pop_back();
	}
	
	void draw()
	{
		// 軌跡を描画
		glBegin(GL_LINE_STRIP);
		for (int i = 0; i < line_strip.size(); i++)
		{
			float a = 1 - (float)i / (float)line_strip.size();
			glColor4f(1, 1, 1, a * 0.3);
			glVertex3fv(line_strip[i].getPtr());
		}
		glEnd();
		
	}
};

vector<Particle> particles; // Particleの配列
ofVec3f center;

//--------------------------------------------------------------
void testApp::setup(){
	ofBackground(0, 0, 0);
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	
	ofEnableAlphaBlending();
	ofEnableSmoothing();
	
	// パーティクルの初期化
	for (int i = 0; i < 500; i++)
	{
		Particle p;
		p.mass = ofRandom(0.1, 3);

		p.pos.set(ofRandom(-100, 100),
					  ofRandom(-100, 100),
					  ofRandom(-100, 100));
		
		p.velocity.set(ofRandom(-100, 100),
				  ofRandom(-100, 100),
				  ofRandom(-100, 100));
		
		particles.push_back(p);
	}
}

//--------------------------------------------------------------
void testApp::update(){
	for (int i = 0; i < particles.size(); i++)
	{
		Particle &p = particles[i];
		
		// 空気抵抗?
		p.factor = -p.velocity * 0.1;
		
		// 中心点に集まるように
		p.factor += (center - p.pos) * 0.1;
		
		// 万有引力めいたものの計算
		for (int k = 0; k < particles.size(); k++)
		{
			if (i == k) continue;
			Particle &pp = particles[k];
			
			p.factor += (pp.pos - p.pos) / pp.mass * 0.001;
		}
	}
	
	for (int i = 0; i < particles.size(); i++)
	{
		Particle &p = particles[i];
		
		// 加速度の計算
		p.velocity += p.factor/p.mass * 0.1;
		
		// 位置の更新
		p.pos += p.velocity * 0.1;

		p.update();
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	glTranslatef(ofGetWidth()/2, ofGetHeight()/2, 0);
	
	static float rot = 0;
	glRotatef(rot, 0, 1, 0); rot += 0.1;
	
	// パーティクルを描画
	for (int i = 0; i < particles.size(); i++)
	{
		Particle &p = particles[i];
		p.draw();
	}
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	// マウスドラッグで中心点の位置を更新
	center.x = x-ofGetWidth()/2;
	center.y = y-ofGetHeight()/2;
	center.z = ofRandom(-300, 300);
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

