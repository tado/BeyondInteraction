#include "ofApp.h"

void ofApp::setup(){
    //画面の設定
    ofBackground(0, 0, 0);
    ofSetCircleResolution(32);
    ofEnableAlphaBlending();
    ofSetFrameRate(30);
    
    //円の位置と場所を変更
    myBall.setPos(ofPoint(300,300));
    myBall.setRadius(100);
    myBall.setSpeed(ofPoint(3, 5));
}

void ofApp::update(){
    myBall.update(); //Ballクラスのupdate()を実行
}

void ofApp::draw(){
    myBall.draw(); //Ballクラスのdraw()を実行
}

void ofApp::keyPressed(int key){
    
}

void ofApp::keyReleased(int key){
    
}

void ofApp::mouseMoved(int x, int y ){
    
}

void ofApp::mouseDragged(int x, int y, int button){
    
}

void ofApp::mousePressed(int x, int y, int button){
    
}

void ofApp::mouseReleased(int x, int y, int button){
    
}

void ofApp::windowResized(int w, int h){
    
}

void ofApp::gotMessage(ofMessage msg){
    
}

void ofApp::dragEvent(ofDragInfo dragInfo){ 
    
}
