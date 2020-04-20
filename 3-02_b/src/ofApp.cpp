#include "ofApp.h"

void ofApp::setup(){
    sampleRate = 44100; //サンプリング周波数
    bufSize = 256;
    amp = 0.5; //音量
    pan = 0.5; //左右の定位
    phase = 0; //位相
    frequency = 440; //周波数
    ofSetFrameRate(30);
    ofBackground(32, 32, 32);

    ofSoundStreamSettings settings;
    settings.setOutListener(this);
    settings.sampleRate = sampleRate;
    settings.numOutputChannels = 2;
    settings.numInputChannels = 0;
    settings.bufferSize = 512;
    soundStream.setup(settings);
}

void ofApp::update(){
}

void ofApp::draw(){
    float audioHeight = ofGetHeight()/2.0f;
    float phaseDiff = ofGetWidth()/float(bufSize);
    
    ofSetColor(0,0,255); //波形を描く色
    ofNoFill(); //塗り潰しをしない
    ofSetLineWidth(2); //線の太さを2pixで
    
    //左チャンネル波形を描画
    ofBeginShape();
    for (int i = 0; i < bufSize; i++){
        ofVertex(i * phaseDiff, audioHeight/2 + lAudio[i] * audioHeight);
    }
    ofEndShape();
    
    //右チャンネル波形を描画
    ofBeginShape();
    for (int i = 0; i < bufSize; i++){
        ofVertex(i * phaseDiff, audioHeight / 2 * 3 + rAudio[i] * audioHeight);
    }
    ofEndShape();
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

void ofApp::audioRequested(float * output, int bufferSize, int nChannels){
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
