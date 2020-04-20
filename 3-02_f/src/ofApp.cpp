#include "ofApp.h"

void ofApp::setup(){
    ofBackground(0, 0, 0);
    mySound.load("drum_loop.aif"); //サウンドファイルの読込み
    mySound.setLoop(true); //ループ再生をONに
}

void ofApp::update(){
}

void ofApp::draw(){
}

void ofApp::keyPressed(int key){
}

void ofApp::keyReleased(int key){
}

void ofApp::mouseMoved(int x, int y){
}

void ofApp::mouseDragged(int x, int y, int button){
    //パンの設定
    mySound.setPan(x / (float)ofGetWidth() * 2 - 1.0f);
    //再生スピード変更
    mySound.setSpeed( 0.5f + ((float)(ofGetHeight() - y) / (float)ofGetHeight())*1.0f);
}

void ofApp::mousePressed(int x, int y, int button){
    //パンの設定
    mySound.setPan(x / (float)ofGetWidth() * 2 - 1.0f);
    //再生スピード設定
    mySound.setSpeed( 0.5f + ((float)(ofGetHeight() - y) / (float)ofGetHeight())*1.0f);
    //サウンド再生開始
    mySound.play();
}

void ofApp::mouseReleased(int x, int y, int button){
    mySound.stop(); //サウンド再生終了
}

void ofApp::windowResized(int w, int h){
}
