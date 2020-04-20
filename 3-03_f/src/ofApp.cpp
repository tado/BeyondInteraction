#include "ofApp.h"

void ofApp::setup(){
    //画面の設定
    ofBackground(0, 0, 0);
    ofSetCircleResolution(32);
    ofEnableAlphaBlending();
    ofSetFrameRate(30);
}

void ofApp::update(){
    //ballsに格納されたBallのインスタンスの数だけupdate()をくりかえす
    for (int i = 0; i < balls.size(); i++) {
        balls[i].update();
    }
}

void ofApp::draw(){
    //ballsに格納されたBallのインスタンスの数だけdraw()をくりかえす
    for (int i = 0; i < balls.size(); i++) {
        balls[i].draw();
    }
}

void ofApp::keyPressed(int key){
    
}

void ofApp::keyReleased(int key){
    
}

void ofApp::mouseMoved(int x, int y){
    
}

void ofApp::mouseDragged(int x, int y, int button){
    
}

void ofApp::mousePressed(int x, int y, int button){
    
}

void ofApp::mouseReleased(int x, int y, int button){
    //マウスをクリックした位置に、新規にBallsのインスタンスを生成
    Ball b; //Ballsをインスタンス化してbを生成
    b.setPos(ofPoint(mouseX,mouseY)); //位置をマウスの場所に
    b.setRadius(ofRandom(10,40)); //大きさをランダムに設定
    b.setSpeed(ofPoint(ofRandom(-3,3),ofRandom(-3,3))); //スピードをランダムに
    balls.push_back(b); //生成されたインスタンスbを動的配列ballsに追加
}


void ofApp::windowResized(int w, int h){
    
}

void ofApp::gotMessage(ofMessage msg){
    
}

void ofApp::dragEvent(ofDragInfo dragInfo){ 
    
}
