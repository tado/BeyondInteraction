#ifndef _TEST_APP
#define _TEST_APP

#include "ofMain.h"
#include "ofxOpenCv.h"
#include "ofxBox2d.h"
#include "ofxVectorMath.h"
#include "CustomCircle.h"
#include "ofxContourAnalysis.h"

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
    
    ofVideoGrabber vidGrabber; //ビデオ入力
    ofxCvColorImage colorImg; //OpenCVで扱うカラーイメージ
    ofxCvGrayscaleImage grayImage; //OpenCVで扱うグレースケールイメージ
    ofxCvGrayscaleImage grayBg; //背景のグレースケールイメージ
    ofxCvGrayscaleImage grayDiff; //背景との差分のグレースケールイメージ
    ofxCvContourFinder contourFinder; //輪郭抽出のためのインスタンス
    ofxContourAnalysis contourAnalysis; //輪郭線を解析するクラスのインスタンス
    //vector <ofPoint> simpleCountour; //単純化された輪郭線の座標の配列
    
    bool bLearnBakground; //背景を学習したかどうか
    int threshold; //背景の差分の閾値
    float simpleAmount; //単純化した輪郭線
    bool bReversePoints; //輪郭線を繋ぐ方向
    
    ofxBox2d box2d; //box2dのインスタンス
    //ofxBox2dLine lineStrip;	//直線の連なり
    vector <ofxBox2dLine> lineStrips; //直線の連なり
    vector <CustomCircle> circles; //独自に作成した円形のパーティクル
    
};

#endif