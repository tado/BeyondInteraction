#include "ofApp.h"
#include "stdio.h"

void ofApp::setup(){
    //画面の基本設定
    ofBackground(0,0,0);
    ofEnableSmoothing();
    //画面の混色の設定を加算合成にする
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    //ムービーデータを読込む
    fingersMovie.load("fingers.mov");
    //ムービーの再生開始
    fingersMovie.play();
}

void ofApp::update(){
    //ムービー再生を待機状態に
    fingersMovie.update();
}

void ofApp::draw(){
    //色の設定
    ofSetColor(0xFFFFFF);
    //ムービーデータを画面に表示
    fingersMovie.draw(20,20);
    //ムービーのビットマップデータを解析し、配列に格納
    ofPixels pixels = fingersMovie.getPixels();
    //画像を8ピクセルごとにスキャン
    for (int i = 0; i < fingersMovie.getWidth(); i+=8){
        for (int j = 0; j < fingersMovie.getHeight(); j+=8){
            //RGBそれぞれのピクセルの明度を取得
            unsigned char r = pixels[(j * 320 + i)*3];
            unsigned char g = pixels[(j * 320 + i)*3+1];
            unsigned char b = pixels[(j * 320 + i)*3+2];
            //取得したRGB値をもとに、円を描画
            //取得したピクセルの明るさを、円の半径に対応させている
            ofSetColor(255, 0, 0, 100);
            ofDrawCircle(360 + i,20+j,10.0*(float)r/255.0);
            ofSetColor(0, 255, 0, 100);
            ofDrawCircle(360 + i,20+j,10.0*(float)g/255.0);
            ofSetColor(0, 0, 255, 100);
            ofDrawCircle(360 + i,20+j,10.0*(float)b/255.0);
        }
    }
}

void ofApp::keyPressed  (int key){
    switch(key){
        case '0':
            //「0」キーを押すと、ムービーを最初のフレームに巻き戻し
            fingersMovie.firstFrame();
            break;
    }
}

void ofApp::keyReleased(int key){
}

void ofApp::mouseMoved(int x, int y ){
}

void ofApp::mouseDragged(int x, int y, int button){
    //マウスをドラッグすると、ムービーのタイムラインを操作できる
    fingersMovie.setPosition((float)x / (float)ofGetWidth());
}

void ofApp::mousePressed(int x, int y, int button){
    //マウスのプレスで、ムービーを一時停止
    fingersMovie.setPaused(true);
}

void ofApp::mouseReleased(int x, int y, int button){
    //マウスのプレスで、ムービーの再生を再開
    fingersMovie.setPaused(false);
}

void ofApp::windowResized(int w, int h){
}
