#include "ofApp.h"

void ofApp::setup() {
	ofSetFrameRate(60);
	shader.load("shader"); // Shaderファイルを読み込み
}

void ofApp::update() {
}

void ofApp::draw() {
	ofSetColor(255);
	shader.begin(); // Shaderの開始
	//画面全体に四角形を描画
	ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
	shader.end(); //Shaderの終了
}