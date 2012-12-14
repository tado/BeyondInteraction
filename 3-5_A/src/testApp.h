#pragma once

#include "ofMain.h"
#include "ofxBox2d.h"
#include "CustomCircle.h"
#include "CustomJoint.h"

class testApp : public ofBaseApp {
    
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
    
    //物理エンジンofxBox2dのインスタンス化
    ofxBox2d box2d;
    //ofxBox2dCircleを拡張して円形のパーティクルを生成、ベクターcirclesに格納
    vector <CustomCircle*> circles;
    //物体同士を結ぶ「ばね」のクラスofxBox2dJointを拡張、ベクターjointsに格納
    vector <CustomJoint*> joints;
};