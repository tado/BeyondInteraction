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
	// 起動してからの経過時間をShaderに送信
	shader.setUniform1f("time", ofGetElapsedTimef());
	// 画面の解像度をShaderに送信
	shader.setUniform2f("resolution", ofGetWidth(), ofGetHeight());
	// 画面全体に四角形を描画
	ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
	shader.end(); // Shaderの終了
}