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
    float x; //円のx座標
    float y; //円のy座標
    float radius; //円の半径
    x = 1024/2; //x座標を画面の中心に
    y = 768/2; //y座標を画面の中心に
    radius = 100; //半径を設定
    ofCircle(x, y, radius); //1つ目の円を描く
    x = x + 20; //x座標を20増加させる
    y = y + 30; //y座標を20増加させる
    radius = radius + 40; //半径を40増加させる
    ofCircle(x, y, radius); //2つ目の円を描く
    x = x + 20; //x座標を20増加させる
    y = y + 30; //y座標を20増加させる
    radius = radius + 40; //半径を40増加させる
    ofCircle(x, y, radius); //3つ目の円を描く
    x = x + 20; //x座標を20増加させる
    y = y + 30; //y座標を20増加させる
    radius = radius + 40; //半径を40増加させる
    ofCircle(x, y, radius); //4つ目の円を描く
    x = x + 20; //x座標を20増加させる
    y = y + 30; //y座標を20増加させる
    radius = radius + 40; //半径を40増加させる
    ofCircle(x, y, radius); //5つ目の円を描く
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

