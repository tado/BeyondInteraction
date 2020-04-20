#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"
#include "ofxBox2d.h"
#include "CustomCircle.h"

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
    
    // ofxBox2dに関連する変数
    ofxBox2d box2d;
    vector <shared_ptr<CustomCircle> > circles; //浮遊する円のVector配列
    vector <shared_ptr<ofxBox2dCircle> > contourCircles; //境界線に配置する円のVector配列
    
    // ofxOpenCvに関連する変数
    ofVideoGrabber vidGrabber; //ビデオ入力
    ofxCvColorImage colorImg; //OpenCVで扱うカラーイメージ
    ofxCvGrayscaleImage grayImage; //OpenCVで扱うグレースケールイメージ
    ofxCvGrayscaleImage grayBg; //背景のグレースケールイメージ
    ofxCvGrayscaleImage grayDiff; //背景との差分のグレースケールイメージ
    ofxCvContourFinder contourFinder; //輪郭抽出のためのインスタンス
    bool bLearnBakground; //背景を記録したかどうか
    int threshold; //背景の差分の閾値
};

