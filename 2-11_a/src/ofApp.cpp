#include "ofApp.h"

float loc_x; //円のx座標
float loc_y; //円のy座標

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0); //背景色の設定
    ofSetFrameRate(60); //フレームレートの設定
    ofSetCircleResolution(64); //円の解像度設定
    
    loc_x = 20; //円のx座標初期位置
    loc_y = 20; //円のy座標初期位置
}

//--------------------------------------------------------------
void ofApp::update(){
    loc_x = loc_x + 3; //円のx座標を3ピクセル移動
    loc_y = loc_y + 2; //円のy座標を2ピクセル移動
    
    //条件1：左端→右端
    if(loc_x < 0){
        loc_x = ofGetWidth();
    }
    //条件2：右端→左端
    if(loc_x > ofGetWidth()){
        loc_x = 0;
    }
    //条件3：上端→下端
    if(loc_y < 0){
        loc_y = ofGetHeight();
    }
    //条件3：上端→下端
    if(loc_y > ofGetHeight()){
        loc_y = 0;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(31, 63, 255); //描画色の設定
    ofDrawCircle(loc_x, loc_y, 40); //円を描画
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

