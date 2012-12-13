#include "testApp.h"

int red[768];
int green[768];
int blue[768];

//--------------------------------------------------------------
void testApp::setup(){
    int i;
    ofBackground(0, 0, 0); //背景色の設定
    for(i=0; i<768; i++){ //色をランダムに生成
        red[i] = ofRandom(0, 255); //レッド
        green[i] = ofRandom(0, 255); //グリーン
        blue[i] = ofRandom(0, 255); //ブルー
    }
}

//--------------------------------------------------------------
void testApp::update(){
    
}

//--------------------------------------------------------------
void testApp::draw(){
    int i;
    for(i=0; i<768; i++){ //あらかじめ個数分生成しておいた線の情報を参照
        ofSetColor(red[i],green[i],blue[i]); //描画色の設定
        ofLine(0, i, ofGetWidth(), i); //横に直線を描く
    }
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

