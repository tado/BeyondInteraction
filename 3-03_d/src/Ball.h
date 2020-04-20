#pragma once

#include "ofMain.h"

class Ball {
    
private:
    ofPoint pos; //円の位置
    float radius; //円の半径
    ofPoint speed; //円の移動スピード
    
public:
    Ball(); //コンストラクタ
    void draw(); //円を描く
    void update(); //円の移動
    void setRadius(float radius); //radiusセッター
    float getRadius(); //radiusゲッター
    void setPos(ofPoint pos); //posセッター
    ofPoint getPos(); //posゲッター
    void setSpeed(ofPoint speed); //speedセッター
    ofPoint getSpeed(); //speedゲッター
};