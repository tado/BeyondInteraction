#include "testApp.h"

float loc_x, loc_y;
int red, green, blue;

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(0, 0, 0); //背景色の設定
    ofSetFrameRate(60); //フレームレートの設定
    ofSetCircleResolution(64); //円の解像度設定
    
    //円の初期位置
    loc_x = ofGetWidth() / 2;
    loc_y = ofGetHeight() / 2;
    
    //円の色、初期値
    red = 31;
    green = 63;
    blue = 255;
}

//--------------------------------------------------------------
void testApp::update(){
    
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(red, green, blue); //描画色の設定
    ofCircle(loc_x, loc_y, 40); //マウスの現在位置を中心に円を描く
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){
    //円の色をグレーに
    red = 127;
    green = 127;
    blue = 127;
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    //円の中心位置をマウスの位置に
    loc_x = x;
    loc_y = y;
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    //円の中心位置をマウスの位置に
    loc_x = x;
    loc_y = y;
    
    //円の色を赤に
    red = 255;
    green = 63;
    blue = 31;
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    //円の色を青に
    red = 31;
    green = 63;
    blue = 255;
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    
}

