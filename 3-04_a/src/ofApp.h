#pragma once

#include "ofMain.h"
#include "ofxBox2d.h" //ofxBox2dのアドオンを読み込み

class ofApp : public ofBaseApp{
    
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
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    ofxBox2d box2d; //Box2Dのインスタンス
    vector <shared_ptr<ofxBox2dCircle> > circles; //Box2D内での円を格納するVector配列
};
