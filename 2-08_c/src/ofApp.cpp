#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0); //背景色の設定
    ofEnableAlphaBlending(); //透明度を使用可能に
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    float x; //画面のx座標の中心点
    float y; //画面のy座標の中心点
    float w; //長方形の幅
    float h; //長方形の高さ
    int i; //for文のカウンタ変数
    
    w = ofGetWidth()/30.0 + 1; //長方形の幅を指定
    h = ofGetHeight()/20.0 + 1; //長方形の高さを指定
    x = 0; //x座標を0に
    y = ofGetHeight()/2 - h/2; //y座標を0に
    
    //30回繰り返す
    for(i=0; i<30; i++){
        ofSetColor(31, 127, 255/30 * i, 127); //塗りの色を変化させる
        x = ofGetWidth() / 30.0 * i; //x座標上に等間隔に配置
        ofDrawRectangle(x, y, w, h); //長方形を描く
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

