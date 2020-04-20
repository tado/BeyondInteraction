#include "ofApp.h"

void ofApp::setup(){
    ofBackground(0,0,0);
    ofSetFrameRate(60);
    
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
    
    //Box2D初期設定
    box2d.init(); //Box2Dの世界を初期化
    box2d.setGravity(0, 1); //重力を設定、下に5の力
    box2d.createBounds(0, 0, colorImg.width, colorImg.height); //画面を壁で囲む
    box2d.setFPS(30); //30fpsで表示
    box2d.checkBounds(true);
    
    //CustomCircleを1000コ配置
    static const int NUM = 1000;
    for (int i = 0; i < NUM; i++) {
        auto circle = make_shared<CustomCircle>();
        circle->setPhysics(1.0, 0.8, 0.0);
        circle->setup(box2d.getWorld(), ofRandom(colorImg.width), ofRandom(colorImg.height), 3);
        circles.push_back(circle);
    }
}

void ofApp::update(){
    //box2d更新
    box2d.update();
    
    //新規にフレームを取り込んだかを判定する変数
    bool bNewFrame = false;
    //最後に取り込んだフレームから変化があったかを判定
    vidGrabber.update();
    bNewFrame = vidGrabber.isFrameNew();
    //新規のフレームの場合とりこみ実行
    if (bNewFrame){
        //OpenCVで解析するカラー画像領域に取得した映像を格納
        colorImg.setFromPixels(vidGrabber.getPixels());
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
        //二値化した差分画像から、輪郭を抽出する
        contourFinder.findContours(grayDiff, 20, (340*240)/3, 10, false);
        //境界線の円をクリア
        for (int i = 0; i < contourCircles.size(); i++) {
            contourCircles[i]->destroy();
        }
        contourCircles.clear();
        //検出された物体(Blobs)の数だけ分析
        for (int i = 0; i < contourFinder.nBlobs; i++){
            for (int j = 0; j < contourFinder.blobs[i].pts.size(); j += 4) {
                //輪郭線にそって等間隔に座標を抽出
                ofPoint pos = contourFinder.blobs[i].pts[j];
                //輪郭線に並べるofxBox2dCircleを追加
                auto circle = make_shared<ofxBox2dCircle>();
                circle->setup(box2d.getWorld(), pos.x, pos.y, 4);
                //Vector配列contourCirclesに追加
                contourCircles.push_back(circle);
            }
        }
    }
}

void ofApp::draw(){
    //画面に対する映像の比率を計算
    float ratioX = ofGetWidth()/320;
    float ratioY = ofGetHeight()/240;
    
    //検出した解析結果を表示
    ofPushMatrix();
    //画面サイズいっぱいに表示されるようリスケール
    ofScale((float)ofGetWidth() / (float)grayDiff.width, (float)ofGetHeight() / (float)grayDiff.height);
    //ソースの映像を描画
    ofSetColor(255, 255, 255);
    colorImg.draw(0, 0);
    //解析結果を描画
    contourFinder.draw();
    //境界線の円を描画
    ofNoFill();
    ofSetColor(255, 0, 0);
    for (int i = 0; i < contourCircles.size(); i++) {
        contourCircles[i]->draw();
    }
    //CustomCircle描画
    for (int i = 0; i < circles.size(); i++) {
        circles[i]->draw();
    }
    ofPopMatrix();
}

void ofApp::keyPressed(int key){
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

void ofApp::keyReleased(int key){
}

void ofApp::mouseMoved(int x, int y ){
}

void ofApp::mouseDragged(int x, int y, int button){
}

void ofApp::mousePressed(int x, int y, int button){
}

void ofApp::mouseReleased(int x, int y, int button){
}

void ofApp::windowResized(int w, int h){
}

void ofApp::gotMessage(ofMessage msg){
}

void ofApp::dragEvent(ofDragInfo dragInfo){
}
