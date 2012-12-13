#include "testApp.h"

void testApp::setup(){
    //画面設定
    ofSetVerticalSync(true);
    ofEnableAlphaBlending();
    ofSetCircleResolution(64);
    ofBackground(0, 0, 0);
    
    //Box2D初期設定
    box2d.init(); //Box2Dの世界を初期化
    box2d.setGravity(0,5); //重力を設定、下に5の力
    box2d.createBounds(0, 0, ofGetWidth(), ofGetHeight()); //四隅に壁を追加
    box2d.setFPS(30); //30fpsで表示
}

void testApp::update(){
    box2d.update(); //Box2Dを更新
}

void testApp::draw(){
    //circlesに格納された全ての図形を描画
    for(int i=0; i<circles.size(); i++) {
        circles[i].draw();
    }
    
    //Box2Dで生成された図形を描画
    box2d.draw();
}

void testApp::keyPressed(int key){
    //「c」をタイプすると、マウスの位置に円を追加
    if (key == 'c') {
        float r = ofRandom(5, 20); //半径を設定
        CustomCircle c; //CustomCircleクラスをインスタンス化
        c.setPhysics(1.0, 0.8, 0.5); //物理パラメータを設定
        c.setup(box2d.getWorld(), mouseX, mouseY, r); //マウスの位置に円を設定
        circles.push_back(c); //生成した円をcirclesに追加
    }
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
}

void testApp::windowResized(int w, int h){
}