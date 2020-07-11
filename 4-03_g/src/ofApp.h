#pragma once
#include "ofMain.h"

class ofApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();

	ofEasyCam cam;
	ofMesh mesh;
	ofLight light; //ライト
	ofMaterial material; //マテリアル
	ofVideoGrabber grabber; //カメラ入力
};
