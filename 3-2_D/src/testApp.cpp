#include "testApp.h"
#include "stdio.h"

void testApp::setup(){
    //バッファーのサイズを指定
    bufSize = 256;
    //画面の基本設定
    ofBackground(0,0,0);
    ofSetColor(0,0,255);
    //サウンドストリームの初期化
    ofSoundStreamSetup(0,2,this, 44100, bufSize, 4);	
    //左右チャンネル音声の波形を格納する配列
    left = new float[bufSize];
    right = new float[bufSize];
}

void testApp::draw(){
    float audioHeight = ofGetHeight()/2.0f;
    float phaseDiff = ofGetWidth()/float(bufSize);
    //左チャンネル波形を描画
    for (int i = 0; i < bufSize; i++){
        ofLine(i*phaseDiff, audioHeight/2, i*phaseDiff, audioHeight/2+left[i]*audioHeight);
    }
    //右チャンネル波形を描画
    for (int i = 0; i < bufSize; i++){
        ofLine(i*phaseDiff, audioHeight/2*3, i*phaseDiff, audioHeight/2*3+right[i]*audioHeight);
    }
}

void testApp::audioReceived(float * input, int bufferSize, int nChannels){	
    //音声入力を配列に格納
    for (int i = 0; i < bufferSize; i++){
        left[i] = input[i*2];
        right[i] = input[i*2+1];
    }
}

void testApp::keyPressed  (int key){ 
}

void testApp::keyReleased(int key){ 
}

void testApp::mouseMoved(int x, int y ){
}

void testApp::mouseDragged(int x, int y, int button){
}

void testApp::mousePressed(int x, int y, int button){
}

void testApp::mouseReleased(int x, int y, int button){
}

void testApp::windowResized(int w, int h){
}