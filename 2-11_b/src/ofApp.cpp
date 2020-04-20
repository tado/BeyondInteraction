#include "ofApp.h"

float loc_x; //円のx座標
float loc_y; //円のy座標
float speed_x; //x軸方向のスピード
float speed_y; //x軸方向のスピード

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0); //背景色の設定
    ofSetFrameRate(60); //フレームレートの設定
    ofSetCircleResolution(64); //円の解像度設定
    
    loc_x = 20; //円のx座標初期位置
    loc_y = 20; //円のy座標初期位置
    speed_x = 4; //x軸方向スピード初期値
    speed_y = 7; //y軸方向スピード初期値
}

//--------------------------------------------------------------
void ofApp::update(){
    
    loc_x = loc_x + speed_x; //円のx座標を更新
    loc_y = loc_y + speed_y; //円のy座標を更新
    
    //条件1：左端で跳ね返る
    if(loc_x < 0){
        speed_x = speed_x * -1;
    }
    //条件2：右端で跳ね返る
    if(loc_x > ofGetWidth()){
        speed_x = speed_x * -1;
    }
    //条件3：上端で跳ね返る
    if(loc_y < 0){
        speed_y = speed_y * -1;
    }
    //条件4：下端で跳ね返る
    if(loc_y > ofGetHeight()){
        speed_y = speed_y * -1;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(31, 63, 255); //描画色の設定
    ofCircle(loc_x, loc_y, 40); //円を描画
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
void ofApp::windowResized(int w, int h){
    
}

