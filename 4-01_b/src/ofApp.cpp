#include "ofApp.h"

void ofApp::setup() {
	ofSetFrameRate(60);
}

void ofApp::update() {
}

void ofApp::draw() {
	//画面の中心に原点を移動
	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
	//X軸を中心にして回転
	ofRotateXRad(ofGetElapsedTimef() * 4.0);
	//四角形を描画
	ofSetColor(31, 127, 255);
	ofSetRectMode(OF_RECTMODE_CENTER);
	ofDrawRectangle(0, 0, 400, 400);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
