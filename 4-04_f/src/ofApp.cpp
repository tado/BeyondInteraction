#include "ofApp.h"

void ofApp::setup() {
	ofSetFrameRate(60);
	shader.load("shader");
}

void ofApp::update() {
}

void ofApp::draw() {
	//画面の中心に球を描画しShaderを適用
	ofSetColor(255);
	ofEnableDepthTest();
	//カメラ開始
	cam.begin();
	//shader開始
	shader.begin();
	shader.setUniform1f("time", ofGetElapsedTimef());
	shader.setUniform2f("resolution", ofGetWidth(), ofGetHeight());
	//球の描画
	ofSetSphereResolution(64);
	ofDrawSphere(300);
	//shader終了
	shader.end();
	//カメラ終了
	cam.end();
}
