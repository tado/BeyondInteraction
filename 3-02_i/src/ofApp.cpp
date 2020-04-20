#include "ofApp.h"

void ofApp::setup(){
    //画面の基本設定
    ofBackground(255, 255, 255);
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    //フォントデータを読みこみ
    georgia.load("Georgia.ttf", 60);
    //フォントのX軸上の表示位置の初期化
    fontX = ofGetWidth();
}

void ofApp::update(){
    //フォントを左に移動
    fontX -= 1;
    //フォントを取り囲む長方形を計算
    ofRectangle rect = georgia.getStringBoundingBox("Hello! I am openFrameworks.", 0,0);
    //フォントの右端が画面左端からはみ出たら、位置を右端に戻す
    if(fontX < -rect.width){
        fontX = ofGetWidth();
    }
}

void ofApp::draw(){
    ofSetColor(0, 127, 255);
    georgia.drawString("Hello! I am openFrameworks.", fontX, ofGetHeight()/2);
}

void ofApp::keyPressed(int key){
}

void ofApp::keyReleased(int key){
}

void ofApp::mouseMoved(int x, int y){
}

void ofApp::mouseDragged(int x, int y, int button){
}

void ofApp::mousePressed(int x, int y, int button){
}

void ofApp::mouseReleased(int x, int y, int button){
}

void ofApp::windowResized(int w, int h){
}
