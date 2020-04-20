#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp {
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed  (int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void audioRequested(float * input, int bufferSize, int nChannels);
    
    ofSoundStream soundStream;
    int sampleRate; //サンプリング周波数
    int bufSize; //バッファの大きさ
    float pan; //定位
    float amp; //音量
    float phase; //位相
    float frequency; //周波数
    float lAudio[256]; //左チャンネル波形
    float rAudio[256]; //右チャンネル波形
};
