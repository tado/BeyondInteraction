#pragma once

#include "ofMain.h"

class Ball {

private:
    ofPoint pos; //円の位置
    float radius; //円の半径
    
public:
    Ball(); //コンストラクタ
    void draw(); //円を描く
    void setRadius(float radius); //radiusセッター
    float getRadius(); //radiusゲッター
    void setPos(ofPoint pos); //posセッター
    ofPoint getPos(); //posゲッター
};