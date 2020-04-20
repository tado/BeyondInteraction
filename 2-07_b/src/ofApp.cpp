#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0); //背景色の設定
    ofEnableAlphaBlending(); //透明度を使用可能に
    ofSetColor(31, 127, 255, 127); //塗りの色を設定
    ofSetCircleResolution(64); //円の解像度を設定
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    float x; //円のx座標
    float y; //円のy座標
    float radius; //円の半径
    x = 1024/2; //x座標を画面の中心に
    y = 768/2; //y座標を画面の中心に
    radius = 30; //半径の初期値を設定
    radius = radius + 40; //半径を40増加させる
    ofDrawCircle(x, y, radius); //1つ目の円を描く
    radius = radius + 40; //半径を40増加させる
    ofDrawCircle(x, y, radius); //2つ目の円を描く
    radius = radius + 40; //半径を40増加させる
    ofDrawCircle(x, y, radius); //3つ目の円を描く
    radius = radius + 40; //半径を40増加させる
    ofDrawCircle(x, y, radius); //4つ目の円を描く
    radius = radius + 40; //半径を40増加させる
    ofDrawCircle(x, y, radius); //5つ目の円を描く
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

