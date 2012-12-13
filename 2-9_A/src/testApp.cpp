#include "testApp.h"

float loc_x1; //円1のx座標
float loc_y1; //円1のy座標
float speed_x1; //x軸方向のスピード1
float speed_y1; //x軸方向のスピード1

float loc_x2; //円2のx座標
float loc_y2; //円2のy座標
float speed_x2; //x軸方向のスピード2
float speed_y2; //x軸方向のスピード2

float loc_x3; //円3のx座標
float loc_y3; //円3のy座標
float speed_x3; //x軸方向のスピード3
float speed_y3; //x軸方向のスピード3

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(0, 0, 0); //背景色の設定
    ofSetFrameRate(60); //フレームレートの設定
    ofSetCircleResolution(64); //円の解像度設定
    ofEnableAlphaBlending(); //アルファチャンネルを有効に
    
    loc_x1 = ofRandom(0, ofGetWidth()); //円1のx座標初期位置
    loc_y1 = ofRandom(0, ofGetHeight()); //円1のy座標初期位置
    speed_x1 = ofRandom(-10, 10); //x軸方向スピード初期値1
    speed_y1 = ofRandom(-10, 10); //y軸方向スピード初期値1
    
    loc_x2 = ofRandom(0, ofGetWidth()); //円2のx座標初期位置
    loc_y2 = ofRandom(0, ofGetHeight()); //円2のy座標初期位置
    speed_x2 = ofRandom(-10, 10); //x軸方向スピード初期値2
    speed_y2 = ofRandom(-10, 10); //y軸方向スピード初期値2
    
    loc_x3 = ofRandom(0, ofGetWidth()); //円3のx座標初期位置
    loc_y3 = ofRandom(0, ofGetHeight()); //円3のy座標初期位置
    speed_x3 = ofRandom(-10, 10); //x軸方向スピード初期値3
    speed_y3 = ofRandom(-10, 10); //y軸方向スピード初期値3
}

//--------------------------------------------------------------
void testApp::update(){
    
    loc_x1 = loc_x1 + speed_x1; //円1のx座標を更新
    loc_y1 = loc_y1 + speed_y1; //円1のy座標を更新
    //円1の跳ね返り条件
    if(loc_x1 < 0){
        speed_x1 = speed_x1 * -1;
    }
    if(loc_x1 > ofGetWidth()){
        speed_x1 = speed_x1 * -1;
    }
    if(loc_y1 < 0){
        speed_y1 = speed_y1 * -1;
    }
    if(loc_y1 > ofGetHeight()){
        speed_y1 = speed_y1 * -1;
    }
    
    loc_x2 = loc_x2 + speed_x2; //円2のx座標を更新
    loc_y2 = loc_y2 + speed_y2; //円2のy座標を更新
    //円2の跳ね返り条件
    if(loc_x2 < 0){
        speed_x2 = speed_x2 * -1;
    }
    if(loc_x2 > ofGetWidth()){
        speed_x2 = speed_x2 * -1;
    }
    if(loc_y2 < 0){
        speed_y2 = speed_y2 * -1;
    }
    if(loc_y2 > ofGetHeight()){
        speed_y2 = speed_y2 * -1;
    }
    
    loc_x3 = loc_x3 + speed_x3; //円3のx座標を更新
    loc_y3 = loc_y3 + speed_y3; //円3のy座標を更新
    //円3の跳ね返り条件
    if(loc_x3 < 0){
        speed_x3 = speed_x3 * -1;
    }
    if(loc_x3 > ofGetWidth()){
        speed_x3 = speed_x3 * -1;
    }
    if(loc_y3 < 0){
        speed_y3 = speed_y3 * -1;
    }
    if(loc_y3 > ofGetHeight()){
        speed_y3 = speed_y3 * -1;
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(31, 63, 255, 127); //描画色の設定
    ofCircle(loc_x1, loc_y1, 40); //円1を描画
    ofCircle(loc_x2, loc_y2, 40); //円2を描画
    ofCircle(loc_x3, loc_y3, 40); //円3を描画
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    
}

