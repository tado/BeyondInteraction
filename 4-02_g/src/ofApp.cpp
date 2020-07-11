#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);
	light.setSpotlight(); //スポットライトを設置
	light.setPosition(-400, 400, 800); //ライトの位置を設定
	light.enable(); //ライトを有効に
	//マテリアルを設定
	//環境色を設定
	material.setAmbientColor(ofColor(127, 63, 31));
	//拡散反射色を設定
	material.setDiffuseColor(ofColor(0, 127, 255));
	//鏡面反射色を設定
	material.setSpecularColor(ofColor(255, 255, 0, 255));
	//鏡面反射の強さを設定
	material.setShininess(120);
	//発光色を設定
	material.setEmissiveColor(ofColor(97, 0, 0));
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofEnableDepthTest(); //深度テストを有効に
	material.begin(); //マテリアル開始
	camera.begin(); //カメラ開始
	//立方体を描画
	box.set(200); //幅、高さ、奥行を200ピクセルに
	box.setPosition(-120, 0, 0); //位置を設定
	box.draw(); //ワイヤーフレームで描画
	//球を描画
	sphere.set(100, 48); //半径100ピクセル、分割数32に
	sphere.setPosition(120, 0, 0); //位置を設定
	sphere.draw(); //ワイヤーフレームで描画
	camera.end(); //カメラ終了
	material.end(); //マテリアルの終了
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
