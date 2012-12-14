#include "ofBlob.h"

//コンストラクタ：位置と半径を指定
ofBlob::ofBlob(){
    pos = ofPoint(ofGetWidth()/2, ofGetHeight()/2); //位置の初期値
    dim = 100.0; //半径の初期値
    speed = ofPoint(0, 0); //移動スピードの初期値
    phaseSpeed = ofRandom(0.1, 0.5); //伸縮スピード
    phase = 0;
}

//メソッド：円を描く
void ofBlob::draw(){
    //円1を描く - 外周
    ofSetColor(31, 63, 255, 100);
    ofCircle(pos.x, pos.y, movedDim); //伸縮運動した半径を適用する
    //円2を描く - 核
    ofSetColor(255, 0, 0, 200);
    ofCircle(pos.x, pos.y, dim/10.0);
    ofSetColor(31, 63, 255);
}

//円のアニメーションを定義
void ofBlob::update(){
    //円の伸縮運動
    movedDim = dim + sin(phase)*dim/4;
    phase += phaseSpeed;
    if(phase > TWO_PI){
        phase -= TWO_PI;
    }
    
    //座標を更新
    pos += speed; 
    //画面の端に来たら跳ね返る
    if(pos.x < dim || pos.x > ofGetWidth()-dim){
        speed.x *= -1;
    }
    if(pos.y < dim || pos.y > ofGetHeight()-dim){
        speed.y *= -1;
    }
}

//posセッター
void ofBlob::setPos(ofPoint _pos){
    pos = _pos; 
}

//posゲッター
ofPoint ofBlob::getPos(){
    return pos;
}

//dimセッター
void ofBlob::setDim(float _dim){
    dim = _dim;
}

//dimゲッター
float ofBlob::getDim(){
    return dim;
}

//speedセッター
void ofBlob::setSpeed(ofPoint _speed){
    speed = _speed;
}

//speedゲッター
ofPoint ofBlob::getSpeed(){
    return speed;
}