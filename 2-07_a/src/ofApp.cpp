#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(47, 47, 47); //背景色の設定
    ofEnableAlphaBlending(); //透明度(アルファチャンネル)を有効にする
    ofSetCircleResolution(64); //円の解像度を設定
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(31, 127, 255, 127); //描画色の設定
    ofDrawCircle(1024/2, 768/2, 100); //円を描く
    ofDrawCircle(1024/2, 768/2, 100+40); //半径を40増加させて円を描く
    ofDrawCircle(1024/2, 768/2, 100+80); //半径を80増加させて円を描く
    ofDrawCircle(1024/2, 768/2, 100+120); //半径を120増加させて円を描く
    ofDrawCircle(1024/2, 768/2, 100+160); //半径を160増加させて円を描く
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
