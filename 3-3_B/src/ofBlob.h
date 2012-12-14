#pragma once

#include "ofMain.h"

class ofBlob {
private:
    ofPoint pos; //円の位置
    float dim; //円の半径
    
public:
    ofBlob(); //コンストラクタ
    void draw(); //円を描く
};