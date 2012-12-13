#include "testApp.h"

void testApp::setup(){
    ofBackground(0,0,0);
    
    //幅320pixel、高さ240pixelでビデオ取り込み初期化
    vidGrabber.initGrabber(320,240);
    //OpenCVで解析する320pixel x 240pixelのカラー画像の領域を確保
    colorImg.allocate(320,240);
    //OpenCVで解析する320pixel x 240pixelのグレースケール画像の領域を確保
    grayImage.allocate(320,240);
}

void testApp::update(){
    //新規にフレームを取り込んだかを判定する変数
    bool bNewFrame = false;
    //1フレーム映像を取り込み
    vidGrabber.grabFrame();
    //最後に取り込んだフレームから変化があったかを判定
    bNewFrame = vidGrabber.isFrameNew();
    //新規のフレームの場合とりこみ実行
    if (bNewFrame){
        //OpenCVで解析するカラー画像領域に取得した映像を格納
        colorImg.setFromPixels(vidGrabber.getPixels(), 320,240);
        //取り込んだカラー映像をグレースケールに変換
        grayImage = colorImg;
    }
}

void testApp::draw(){
    //取り込んだ画像を(10,10)の位置に表示
    colorImg.draw(10,10);
    //グレースケールに変換した画像を(340,10)の位置に表示
    grayImage.draw(340,10);
}

void testApp::keyPressed(int key){
}

void testApp::keyReleased(int key){
}

void testApp::mouseMoved(int x, int y ){
}

void testApp::mouseDragged(int x, int y, int button){
}

void testApp::mousePressed(int x, int y, int button){
}

void testApp::mouseReleased(int x, int y, int button){
}

void testApp::windowResized(int w, int h){
}