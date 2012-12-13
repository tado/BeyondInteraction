#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(0, 0, 0); //背景色の設定
    ofEnableAlphaBlending(); //透明度を使用可能に
}

//--------------------------------------------------------------
void testApp::update(){
    
}

//--------------------------------------------------------------
void testApp::draw(){
    float x; //画面のx座標の中心点
    float y; //画面のy座標の中心点
    float w; //長方形の幅
    float h; //長方形の高さ
    int i, j; //for文のカウンタ変数
    
    x = 0; //x座標を0に
    y = 0; //y座標を0に
    w = ofGetWidth()/30.0 + 1; //長方形の幅を指定
    h = ofGetHeight()/20.0 + 1; //長方形の高さを指定
    
    for(j=0; j<20; j++){
        for(i=0; i<30; i++){
            ofSetColor(255/20 * j, 127, 255/30 * i, 127); //塗りの色を変化させる
            x = ofGetWidth() / 30.0 * i; //x座標上に等間隔に配置
            y = ofGetHeight() / 20.0 * j; //y座標上に等間隔に配置;
            ofRect(x, y, w, h); //長方形を描く
        }
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

