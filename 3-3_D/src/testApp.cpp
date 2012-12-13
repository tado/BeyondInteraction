#include "testApp.h"

void testApp::setup(){
    //画面の設定
    ofBackground(0, 0, 0);
    ofSetCircleResolution(32);
    ofEnableAlphaBlending();
    ofSetFrameRate(30);
    
    //円の位置と場所を変更
    blob.setPos(ofPoint(300,300));
    blob.setDim(100);
    blob.setSpeed(ofPoint(3, 5));
}

void testApp::update(){
    blob.update(); //blobクラスのupdate()を実行
}

void testApp::draw(){
    blob.draw(); //blobクラスのdraw()を実行
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