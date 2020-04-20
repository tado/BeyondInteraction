#pragma once

#include "ofMain.h"

class Ball {

private:
    ofPoint pos; //円の位置
    float radius; //円の半径

public:
    Ball(); //コンストラクタ
    void draw(); //円を描く
};