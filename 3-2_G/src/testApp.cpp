#include "testApp.h"

void testApp::setup(){
    ofBackground(0, 0, 0);
    ofSetVerticalSync(true);
    ofSetCircleResolution(64);
    ofEnableAlphaBlending();
    
    radius = 0; //円の半径
    mySound.loadSound("drum_loop.aif"); //サウンドファイルの読込み
    mySound.setLoop(true); //ループ再生をONに
}

void testApp::update(){
    float * val = ofSoundGetSpectrum(1); //再生中のサウンドの音量を取得
    radius = val[0] * 800.0; //円の半径に適用
}

void testApp::draw(){
    ofSetColor(0, 63, 255, 180);
    ofCircle(mouseX, mouseY, radius);
}

void testApp::keyPressed(int key){
}

void testApp::keyReleased(int key){
}

void testApp::mouseMoved(int x, int y){
}

void testApp::mouseDragged(int x, int y, int button){
    //パンの設定
    mySound.setPan(x / (float)ofGetWidth() * 2 - 1.0f);
    //再生スピード変更
    mySound.setSpeed( 0.5f + ((float)(ofGetHeight() - y) / (float)ofGetHeight())*1.0f);
}

void testApp::mousePressed(int x, int y, int button){
    //パンの設定
    mySound.setPan(x / (float)ofGetWidth() * 2 - 1.0f);
    //再生スピード設定
    mySound.setSpeed( 0.5f + ((float)(ofGetHeight() - y) / (float)ofGetHeight())*1.0f);
    //サウンド再生開始
    mySound.play();
}

void testApp::mouseReleased(int x, int y, int button){
    mySound.stop(); //サウンド再生終了
}

void testApp::windowResized(int w, int h){
}