#include "ofApp.h"

float start_x[1000];
float start_y[1000];
float end_x[1000];
float end_y[1000];

//--------------------------------------------------------------
void ofApp::setup(){
    int i;
    ofBackground(0, 0, 0); //背景色の設定
    ofEnableAlphaBlending(); //透明度を使用可能に
    ofSetLineWidth(2); //線の太さの設定
    ofEnableSmoothing(); //線の描画をスムースに
    for(i=0; i<1000; i++){ //線の始点と終点の座標をランダムに決定
        start_x[i] = ofRandom(0, ofGetWidth());
        start_y[i] = ofRandom(0, ofGetHeight());
        end_x[i] = ofRandom(0, ofGetWidth());
        end_y[i] = ofRandom(0, ofGetHeight());
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    int i;
    ofSetColor(31, 127, 255, 63); //描画色の設定
    for(i=0; i<1000; i++){ //あらかじめ個数分生成しておいた線の情報を参照
        ofDrawLine(start_x[i], start_y[i], end_x[i], end_y[i]); //直線の描画
    }
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

