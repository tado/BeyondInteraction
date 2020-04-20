#include "ofApp.h"

void ofApp::setup(){
	ofSetFrameRate(60);
}

void ofApp::update(){

}

void ofApp::draw(){
	//画面の中心に原点を移動
	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
	//立方体を描画
	box.set(200); //幅、高さ、奥行を200ピクセルに
	box.setPosition(-120, 0, 0); //位置を設定
	box.drawWireframe(); //ワイヤーフレームで描画
	//球を描画
	sphere.set(100, 8); //半径100ピクセル、分割数8に
	sphere.setPosition(120, 0, 0); //位置を設定
	sphere.drawWireframe(); //ワイヤーフレームで描画
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
