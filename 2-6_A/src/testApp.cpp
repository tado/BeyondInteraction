#include "testApp.h"

float x[1000];
float y[1000];
float radius[1000];

//--------------------------------------------------------------
void testApp::setup(){
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
void testApp::update(){
    
}

//--------------------------------------------------------------
void testApp::draw(){
    int i;
    ofSetColor(31, 63, 255, 63); //描画色の設定
    
    for(i=0; i<1000; i++){  //あらかじめ個数分生成しておいた円の情報参照し、円を描く
        ofCircle(x[i], y[i], radius[i]); //円の描画
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

