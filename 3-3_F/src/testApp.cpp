#include "testApp.h"

void testApp::setup(){
    //画面の設定
    ofBackground(0, 0, 0);
    ofSetCircleResolution(32);
    ofEnableAlphaBlending();
    ofSetFrameRate(30);
}

void testApp::update(){
    //blobsに格納されたofBlobのインスタンスの数だけupdate()をくりかえす
    for (int i=0; i<blobs.size(); i++) {
        blobs[i].update();
    }
}

void testApp::draw(){
    //blobsに格納されたofBlobのインスタンスの数だけdraw()をくりかえす
    for (int i=0; i<blobs.size(); i++) {
        blobs[i].draw();
    }
}

void testApp::keyPressed(int key){
}

void testApp::keyReleased(int key){
}

void testApp::mouseMoved(int x, int y){
}

void testApp::mouseDragged(int x, int y, int button){
}

void testApp::mousePressed(int x, int y, int button){
}

void testApp::mouseReleased(int x, int y, int button){
    //マウスをクリックした位置に、新規にofBlobsのインスタンスを生成
    ofBlob b; //ofBlobsをインスタンス化してbを生成
    b.setPos(ofPoint(mouseX,mouseY)); //位置をマウスの場所に
    b.setDim(ofRandom(10,40)); //大きさをランダムに設定
    b.setSpeed(ofPoint(ofRandom(-3,3),ofRandom(-3,3))); //スピードをランダムに
    blobs.push_back(b); //生成されたインスタンスbを動的配列blobsに追加
}

void testApp::windowResized(int w, int h){
}