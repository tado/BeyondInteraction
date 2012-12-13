#include "testApp.h"

void testApp::setup(){
    //画面の基本設定
    ofBackground(255, 255, 255);
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    //フォントデータを読みこみ
    georgia.loadFont("Georgia.ttf", 60);
    //フォントのX軸上の表示位置の初期化
    fontX = ofGetWidth();
}

void testApp::update(){
    //フォントを左に移動
    fontX -= 1;
    //フォントを取り囲む長方形を計算
    ofRectangle rect = georgia.getStringBoundingBox("Hello! I am openFrameworks.", 0,0);
    //フォントの右端が画面左端からはみ出たら、位置を右端に戻す
    if(fontX < -rect.width){
        fontX = ofGetWidth();
    }
}

void testApp::draw(){
    ofSetColor(0, 127, 255);
    georgia.drawString("Hello! I am openFrameworks.", fontX, ofGetHeight()/2);
}

void testApp::keyPressed(int key){
}

void testApp::keyReleased(int key){
}

void testApp::mouseMoved(int x, int y){
}

void testApp::mouseDragged(int x, int y, int button){
}

void testApp::mousePressed(int x, int y, int button){
}

void testApp::mouseReleased(int x, int y, int button){
}

void testApp::windowResized(int w, int h){
}