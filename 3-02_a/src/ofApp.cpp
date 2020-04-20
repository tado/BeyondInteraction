#include "ofApp.h"

void ofApp::setup(){
    sampleRate = 44100; //サンプリング周波数
    amp = 0.5; //音量
    pan = 0.5; //左右の定位
    phase = 0; //位相
    frequency = 440; //周波数

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

//void ::audioRequested    (float * output, int bufferSize, int nChannels){
void ofApp::audioOut(ofSoundBuffer & output){
    float sample; //出力する音のサンプル
    float phaseDiff; //位相の変化
    int bufferSize = 512;
    int nChannels = 2;
    
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
        output[i * nChannels] = sample * pan * amp;
        output[i * nChannels + 1] = sample * pan * amp;
    }
}
