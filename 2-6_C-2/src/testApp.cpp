#include "testApp.h"

int red[768];
int green[768];
int blue[768];

//--------------------------------------------------------------
void testApp::setup(){
    int i;
    ofBackground(0, 0, 0);
    for(i=0; i<768; i++){
        red[i] = ofRandom(0, 31);
        green[i] = ofRandom(63, 127);
        blue[i] = ofRandom(127, 255);
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

