#include "ofApp.h"

void ofApp::setup(){
    //画面設定
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofBackground(0, 0, 0);
    ofEnableAlphaBlending();
    
    //Box2D初期設定
    box2d.init(); //Box2Dの世界を初期化
    box2d.setGravity(0,5); //重力を設定、下に5の力
    box2d.createBounds(0, 0, ofGetWidth(), ofGetHeight()); //画面を壁で囲む
    box2d.setFPS(30); //30fpsで表示
    
    //障害物を追加
    for (int i=0; i<100; i++) { //100個の配置する
        auto r = make_shared<ofxBox2dRect>();
        float w = 2; //幅2
        float h = 2; //高さ2
        float x = ofRandom(50, ofGetWidth()-50); //ランダムにx座標の位置を指定
        float y = ofRandom(50, ofGetHeight()-50); //ランダムにy座標の位置を指定
        r->setup(box2d.getWorld(), x, y, w, h); //固定した状態で画面に追加
        rects.push_back(r); //rectsに生成した長方形を追加
    }
}

void ofApp::update(){
    box2d.update(); //Box2Dを更新
}

void ofApp::draw(){
    //circles配列に格納された全ての円を描画
    for(int i=0; i<circles.size(); i++) {
        ofFill(); //塗りつぶしあり
        circles[i]->draw(); //全ての円を描画
    }
    //rectsに格納された全ての図形を描画
    for(int i=0; i<rects.size(); i++) {
        ofSetColor(255, 63, 63);
        rects[i]->draw();
    }
}

void ofApp::keyPressed(int key){
    //「c」をタイプすると、マウスの位置に円を追加
    if (key == 'c') {
        float r = ofRandom(5, 20); //半径を設定
        auto c = make_shared<CustomCircle>();
        c->setPhysics(1.0, 0.8, 0.5); //物理パラメータを設定
        c->setup(box2d.getWorld(), mouseX, mouseY, r); //マウスの位置に円を設定
        circles.push_back(c); //生成した円をcirclesに追加
    }
    // 「r」をタイプすると、全ての円を消去
    if (key == 'r') {
        for(int i=0; i<circles.size(); i++) {
            circles[i]->destroy();
        }
        circles.clear();
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
