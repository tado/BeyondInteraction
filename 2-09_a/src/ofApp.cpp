#include "ofApp.h"

float x[1000];
float y[1000];
float radius[1000];

//--------------------------------------------------------------
void ofApp::setup(){
    int i;
    ofBackground(0, 0, 0); //背景色の設定
    ofEnableAlphaBlending(); //透明度を使用可能に
    ofSetCircleResolution(64); //円の解像度を設定
    
    for(i=0; i<1000; i++){//1000個分の円の情報を生成し配列に記録していく
        x[i] = ofRandom(0, ofGetWidth()); //x座標
        y[i] = ofRandom(0, ofGetHeight()); //y座標
        radius[i] = ofRandom(10, 40); //半径
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    int i;
    ofSetColor(31, 63, 255, 63); //描画色の設定
    
    for(i=0; i<1000; i++){  //あらかじめ個数分生成しておいた円の情報参照し、円を描く
        ofDrawCircle(x[i], y[i], radius[i]); //円の描画
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

