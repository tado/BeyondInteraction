#include "ofApp.h"

void ofApp::setup(){
    mySound.load("glitch_loop.wav"); //サウンドファイルの読込み
    mySound.setLoop(true); //ループ再生をONに
    mySound.play(); //サウンド再生開始
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
}

void ofApp::mousePressed(int x, int y, int button){
}

void ofApp::mouseReleased(int x, int y, int button){
}

void ofApp::windowResized(int w, int h){
}
