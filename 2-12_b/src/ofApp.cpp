#include "ofApp.h"
#define NUM 100 //円の数を表す定数NUMを100と定義

float loc_x[NUM]; //円のx座標
float loc_y[NUM]; //円のy座標
float speed_x[NUM]; //x軸方向のスピード
float speed_y[NUM]; //y軸方向のスピード2

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0); //背景色の設定
    ofSetFrameRate(60); //フレームレートの設定
    ofSetCircleResolution(64); //円の解像度設定
    ofEnableAlphaBlending(); //アルファチャンネルを有効に
    
    //NUMの数だけ初期値の生成を繰り返す
    for(int i = 0; i < NUM; i++){
        loc_x[i] = ofRandom(0, ofGetWidth()); //円のx座標初期位置
        loc_y[i] = ofRandom(0, ofGetHeight()); //円のy座標初期位置
        speed_x[i] = ofRandom(-10, 10); //x軸方向スピード初期値
        speed_y[i] = ofRandom(-10, 10); //y軸方向スピード初期値
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    //NUMの数だけ座標の更新を繰り返す
    for(int i = 0; i < NUM; i++){
        loc_x[i] = loc_x[i] + speed_x[i]; //円のx座標を更新
        loc_y[i] = loc_y[i] + speed_y[i]; //円のy座標を更新
        
        //円の跳ね返り条件
        if(loc_x[i] < 0){
            speed_x[i] = speed_x[i] * -1;
        }
        if(loc_x[i] > ofGetWidth()){
            speed_x[i] = speed_x[i] * -1;
        }
        if(loc_y[i] < 0){
            speed_y[i] = speed_y[i] * -1;
        }
        if(loc_y[i] > ofGetHeight()){
            speed_y[i] = speed_y[i] * -1;
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(31, 63, 255, 127); //描画色の設定
    
    //NUMの数だけ円を描画する
    for(int i = 0; i < NUM; i++){
        ofCircle(loc_x[i], loc_y[i], 40); //円1を描画
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

