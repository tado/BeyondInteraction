#include "ofApp.h"

void ofApp::setup() {
	ofSetFrameRate(60);
	ofBackground(0);
	//板の生成
	ofPlanePrimitive plane;
	plane.set(1000, 1000, 100, 100);
	//板のメッシュの抽出
	mesh = plane.getMesh();
}

void ofApp::update() {

}

void ofApp::draw() {
	cam.begin();
	ofRotateXDeg(-45);
	//ワイヤーフレームでメッシュを描画
	mesh.drawWireframe();
	cam.end();
}