#include "Ball.h"

//コンストラクタ：位置と半径を指定
Ball::Ball(){
    pos = ofPoint(ofGetWidth()/2, ofGetHeight()/2); //位置の初期値
    radius = 100.0; //半径の初期値
    speed = ofPoint(0, 0); //移動スピードの初期値
}

//メソッド：円を描く
void Ball::draw(){
    //円1を描く - 外周
    ofSetColor(31, 63, 255, 100);
    ofCircle(pos.x, pos.y, radius);
    //円2を描く - 核
    ofSetColor(255, 0, 0, 200);
    ofCircle(pos.x, pos.y, radius/10.0);
    ofSetColor(31, 63, 255);
}

//円のアニメーションを定義
void Ball::update(){
    pos += speed; //座標を更新
    //画面の端に来たら跳ね返る
    if(pos.x < radius || pos.x > ofGetWidth()-radius){
        speed.x *= -1;
    }
    if(pos.y < radius || pos.y > ofGetHeight()-radius){
        speed.y *= -1;
    }
}

//posセッター
void Ball::setPos(ofPoint _pos){
    pos = _pos;
}

//posゲッター
ofPoint Ball::getPos(){
    return pos;
}

//radiusセッター
void Ball::setRadius(float _radius){
    radius = _radius;
}

//radiusゲッター
float Ball::getRadius(){
    return radius;
}

//speedセッター
void Ball::setSpeed(ofPoint _speed){
    speed = _speed;
}

//speedゲッター
ofPoint Ball::getSpeed(){
    return speed;
}