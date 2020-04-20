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
    //void audioRequested(float * input, int bufferSize, int nChannels);
    void audioOut(ofSoundBuffer & buffer);
    
    ofSoundStream soundStream;
    int sampleRate; //サンプリング周波数
    float pan; //定位
    float amp; //音量
    float phase; //位相
    float frequency; //周波数
};
