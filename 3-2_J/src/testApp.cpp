#include "testApp.h"
#include "stdio.h"

void testApp::setup(){
    //画面の基本設定
    ofBackground(0,0,0);
    ofEnableSmoothing();
    //画面の混色の設定を加算合成にする
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    //ムービーデータを読込む
    fingersMovie.loadMovie("fingers.mov");
    //ムービーの再生開始
    fingersMovie.play();
}

void testApp::update(){
    //ムービー再生を待機状態に
    fingersMovie.idleMovie();
}

void testApp::draw(){
    //色の設定
    ofSetColor(0xFFFFFF);
    //ムービーデータを画面に表示
    fingersMovie.draw(20,20);
    //ムービーのビットマップデータを解析し、配列に格納
    unsigned char * pixels = fingersMovie.getPixels();
    //画像を8ピクセルごとにスキャン
    for (int i = 0; i < fingersMovie.width; i+=8){
        for (int j = 0; j < fingersMovie.height; j+=8){
            //RGBそれぞれのピクセルの明度を取得
            unsigned char r = pixels[(j * 320 + i)*3];
            unsigned char g = pixels[(j * 320 + i)*3+1];
            unsigned char b = pixels[(j * 320 + i)*3+2];
            //取得したRGB値をもとに、円を描画
            //取得したピクセルの明るさを、円の半径に対応させている
            ofSetColor(255, 0, 0, 100);
            ofCircle(360 + i,20+j,10.0*(float)r/255.0);
            ofSetColor(0, 255, 0, 100);
            ofCircle(360 + i,20+j,10.0*(float)g/255.0);
            ofSetColor(0, 0, 255, 100);
            ofCircle(360 + i,20+j,10.0*(float)b/255.0);
        }
    }
}

void testApp::keyPressed  (int key){
    switch(key){
        case '0':
            //「0」キーを押すと、ムービーを最初のフレームに巻き戻し
            fingersMovie.firstFrame();
            break;
    }
}

void testApp::keyReleased(int key){
}

void testApp::mouseMoved(int x, int y ){
}

void testApp::mouseDragged(int x, int y, int button){
    //マウスをドラッグすると、ムービーのタイムラインを操作できる
    fingersMovie.setPosition((float)x / (float)ofGetWidth());
}

void testApp::mousePressed(int x, int y, int button){
    //マウスのプレスで、ムービーを一時停止
    fingersMovie.setPaused(true);
}

void testApp::mouseReleased(int x, int y, int button){
    //マウスのプレスで、ムービーの再生を再開
    fingersMovie.setPaused(false);
}

void testApp::windowResized(int w, int h){
}