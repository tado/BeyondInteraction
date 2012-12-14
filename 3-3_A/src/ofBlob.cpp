#include "ofBlob.h"

//メソッド：円を描く
void ofBlob::draw(){
    ofSetColor(31, 63, 255); //描画色を設定
    ofCircle(ofGetWidth()/2, ofGetHeight()/2, 100); //画面の中心に円を描く
}