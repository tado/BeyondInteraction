#include "testApp.h"

void testApp::setup(){
    ofBackground(0,0,0);
    
    //幅320pixel、高さ240pixelでビデオ取り込み初期化
    vidGrabber.initGrabber(320,240);
    //OpenCVで解析する320pixel x 240pixelのカラー画像の領域を確保
    colorImg.allocate(320,240);
    //OpenCVで解析する320pixel x 240pixelのグレースケール画像の領域を確保
    grayImage.allocate(320,240);
    //背景画像として320pixel x 240pixelのグレースケール画像の領域を確保
    grayBg.allocate(320,240);
    //背景との差分画像として320pixel x 240pixelのグレースケール画像の領域を確保
    grayDiff.allocate(320,240);
    //背景の学習モードを真に
    bLearnBakground = true;
    //閾値を100に
    threshold = 100;
}

void testApp::update(){
    //新規にフレームを取り込んだかを判定する変数
    bool bNewFrame = false;
    //1フレーム映像を取り込み
    vidGrabber.update();
    //最後に取り込んだフレームから変化があったかを判定
    bNewFrame = vidGrabber.isFrameNew();
    //新規のフレームの場合とりこみ実行
    if (bNewFrame){
        //OpenCVで解析するカラー画像領域に取得した映像を格納
        colorImg.setFromPixels(vidGrabber.getPixels(), 320,240);
        //取り込んだカラー映像をグレースケールに変換
        grayImage = colorImg;
        //新規に背景を記録する場合
        if (bLearnBakground == true){
            //現在の取り込んだグレースケールイメージを記憶
            grayBg = grayImage;
            //背景の記録をしないモードに戻す
            bLearnBakground = false;
        }
        //背景画像と現在の画像の差分の絶対値を取得    
        grayDiff.absDiff(grayBg, grayImage);
        //差分画像を設定した閾値を境に二値化
        grayDiff.threshold(threshold);
    }
}

void testApp::draw(){
    //取り込んだ画像を(10,10)の位置に表示
    colorImg.draw(10,10);
    //グレースケールに変換した画像を(340,10)の位置に表示
    grayImage.draw(340,10);
    //学習した背景画像を(10,260)の位置に表示
    grayBg.draw(10,260);
    //背景画像と現在の画像との差分を(360,280)の位置に表示
    grayDiff.draw(340,260);
}

void testApp::keyPressed(int key){
    switch (key){
        case ' ': //スペースキーで背景を学習モードに
            bLearnBakground = true;
            break;
        case '+': //[+]キーで背景の閾値のレベルを上げる(最大255)
            threshold ++;
            if (threshold > 255) threshold = 255;
            break;
        case '-': //[-]キーで背景の閾値のレベルを下げる(最小0)
            threshold --;
            if (threshold < 0) threshold = 0;
            break;
    }
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