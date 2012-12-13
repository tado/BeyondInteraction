#include "testApp.h"

void testApp::setup(){
    sampleRate = 44100; //サンプリング周波数
    bufSize = 256;
    amp = 0.5; //音量
    pan = 0.5; //左右の定位
    phase = 0; //位相
    frequency = 440; //周波数
    ofSetFrameRate(30);
    ofBackground(32, 32, 32);
    ofSoundStreamSetup(2, 0, this); //サウンドストリームの準備、左右2ch
}

void testApp::update(){
}

void testApp::draw(){
    float audioHeight = ofGetHeight()/2.0f;
    float phaseDiff = ofGetWidth()/float(bufSize);
    
    ofSetColor(0,0,255);
    
    //左チャンネル波形を描画
    for (int i = 0; i < bufSize; i++){
        ofLine(i*phaseDiff, audioHeight/2, i*phaseDiff, audioHeight/2+lAudio[i]*audioHeight);
    }
    
    //右チャンネル波形を描画
    for (int i = 0; i < bufSize; i++){
        ofLine(i*phaseDiff, audioHeight/2*3, i*phaseDiff, audioHeight/2*3+lAudio[i]*audioHeight);
    }
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

void testApp::audioRequested(float * output, int bufferSize, int nChannels){
    float sample; //出力する音のサンプル
    float phaseDiff; //位相の変化
    
    //1サンプルあたりの位相の変化を計算
    phaseDiff = TWO_PI * frequency / sampleRate;
    
    //バッファのサイズ分の波形を生成
    for (int i = 0; i < bufferSize; i++){
        //位相を更新
        phase += phaseDiff;
        while (phase > TWO_PI){
            phase -= TWO_PI;
        }
        //Sin波を生成
        sample = sin(phase);
        // オーディオアウト、左右2ch
        lAudio[i] = output[i * nChannels] = sample * pan * amp;
        rAudio[i] = output[i * nChannels + 1] = sample * pan * amp;
    }
}