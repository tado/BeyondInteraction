#ifndef _OF_BLOB
#define _OF_BLOB

#include "ofMain.h"

class ofBlob {
private:
    ofPoint pos; //円の位置
    float dim; //円の半径
    ofPoint speed; //円の移動スピード
    
public:
    ofBlob(); //コンストラクタ
    void draw(); //円を描く
    void update(); //円の移動
    void setDim(float dim); //dimセッター
    float getDim(); //dimゲッター
    void setPos(ofPoint pos); //posセッター
    ofPoint getPos(); //posゲッター
    void setSpeed(ofPoint speed); //speedセッター
    ofPoint getSpeed(); //speedゲッター
};

#endif