#pragma once

#include "ofMain.h"
#include "ofxBox2d.h" //ofxBox2dのアドオンを読み込み
#include "CustomCircle.h" //CustomCircleクラスを使用

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
    vector <shared_ptr<CustomCircle> > circles; //CustomCircleのインスタンスを格納するvector
    vector <shared_ptr<ofxBox2dRect> > rects; //障害物用の長方形ofxBox2dRectを格納するvector
};
