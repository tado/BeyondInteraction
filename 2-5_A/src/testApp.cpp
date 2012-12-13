#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(0, 0, 0); //背景色の設定
    ofEnableAlphaBlending(); //透明度を使用可能に
    ofSetColor(31, 127, 255, 127); //塗りの色を設定
    ofSetCircleResolution(64); //円の解像度を設定
}

//--------------------------------------------------------------
void testApp::update(){
    
}

//--------------------------------------------------------------
void testApp::draw(){
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
        ofCircle(x, y, radius); //計算された中心点と半径で、円を描く
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

