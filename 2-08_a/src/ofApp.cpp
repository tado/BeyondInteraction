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
    float x; //画面のx座標の中心点
    float y; //画面のy座標の中心点
    float radius; //円の半径
    int i; //for文のカウンタ変数
    
    x = ofGetWidth()/2; //x座標を画面の中心に
    y = ofGetHeight()/2; //y座標を画面の中心に
    radius = 30; //半径を設定
    
    //5回くりかえし
    for(i=0; i<5; i++){
        x = x + 20; //x座標を20ピクセル右へ
        y = y + 30; //y座標を30ピクセル下ヘ
        radius = radius + 40; //半径を40ピクセル増加させる
        ofDrawCircle(x, y, radius); //計算された中心点と半径で、円を描く
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

