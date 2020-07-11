#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);
	light.setSpotlight(); //スポットライトを設置
	light.setPosition(-400, 400, 800); //ライトの位置を設定
	light.enable(); //ライトを有効に
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofEnableDepthTest(); //深度テストを有効に
	camera.begin(); //カメラ開始
	//立方体を描画
	box.set(200); //幅、高さ、奥行を200ピクセルに
	box.setPosition(-120, 0, 0); //位置を設定
	box.draw(); //ワイヤーフレームで描画
	//球を描画
	sphere.set(100, 32); //半径100ピクセル、分割数32に
	sphere.setPosition(120, 0, 0); //位置を設定
	sphere.draw(); //ワイヤーフレームで描画
	camera.end(); //カメラ終了
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
