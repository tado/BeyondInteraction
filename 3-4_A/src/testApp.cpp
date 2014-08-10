#include "testApp.h"

void testApp::setup(){
    //画面設定
    ofSetVerticalSync(true);
    ofBackground(0, 0, 0);
    
    //Box2D初期設定
    box2d.init(); //Box2Dの世界を初期化
    box2d.setGravity(0,5); //重力を設定、下に5の力
    box2d.createBounds(0, 0, ofGetWidth(), ofGetHeight()); //画面を壁で囲む
    box2d.setFPS(30); //30fpsで表示
}

void testApp::update(){
    box2d.update(); //Box2Dを更新
}

void testApp::draw(){
    ofSetColor(0, 127, 255);
    //circlesに格納された全ての円を描画
    for(int i=0; i<circles.size(); i++) {
        circles[i].get()->draw();
    }
    box2d.drawGround();
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
    //画面をクリックすると、円を追加
    float r = ofRandom(10, 40); //半径を設定
    ofPtr<ofxBox2dCircle> circle = ofPtr<ofxBox2dCircle>(new ofxBox2dCircle); //ofxBox2dCircle(円)クラスをインスタンス化
    circle.get()->setPhysics(1.0, 0.8, 0.5); //物理パラメータを設定(重さ、反発力、摩擦力)
    circle.get()->setup(box2d.getWorld(), mouseX, mouseY, r); //マウスの位置に円を設定
    circles.push_back(circle); //生成した円をcirclesに追加
}

void testApp::mouseReleased(int x, int y, int button){
}

void testApp::windowResized(int w, int h){
}