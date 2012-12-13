#include "testApp.h"

void testApp::setup(){
    mySound.loadSound("glitch_loop.wav"); //サウンドファイルの読込み
    mySound.setLoop(true); //ループ再生をONに
    mySound.play(); //サウンド再生開始
}

void testApp::update(){
}

void testApp::draw(){
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