#include "Ball.h"

//コンストラクタ：位置と半径を指定
Ball::Ball()
{
    pos = ofPoint(400, 300); //位置の指定
    radius = 80.0; //半径の指定
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