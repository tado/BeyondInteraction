#include "testApp.h"

void testApp::setup(){
    //画面の書き換えタイミングと同期
    ofSetVerticalSync(true);
    //背景色
    ofBackground(0, 0, 0);
    //円の解像度
    ofSetCircleResolution(64);
    //フレームレートの設定
    ofSetFrameRate(30);
    
    //毎回異なる乱数を発生させる
    ofSeedRandom();
    
    //ofxBox2dの初期設定
    //物理エンジンを初期化
    box2d.init();
    //重力は使用しない
    box2d.setGravity(0,0);
    //Box2D側のフレームレートを設定
    box2d.setFPS(30.0);
    
    //画面の中心に1つめのパーティクルを生成
    //CustomCircleクラスをインスタンス化
    CustomCircle *c =new CustomCircle(circles.size());
    //物理パラメータを設定
    c->setPhysics(1.0, 0, 0);
    //ワールドに追加
    c->setup(box2d.getWorld(), ofGetWidth()/2, ofGetHeight()/2, 10);
    //衝突判定はしない
    //c->disableCollistion();
    //ベクターcirclesに追加
    circles.push_back(c);
}

void testApp::update(){
    //全てのパーティクルの座標を更新
    for(int i=0; i<circles.size(); i++){
        circles[i]->update();
    }
    
    //Box2Dの座標を更新
    box2d.update();
}

void testApp::draw(){
    //全ての「ばね」を描画
    for(int i=0; i<joints.size(); i++){
        joints[i]->draw();
    }
    
    //全てのパーティクルを描画
    for(int i=0; i<circles.size(); i++){
        circles[i]->draw();
    }
}

void testApp::keyReleased(int key){
}

void testApp::keyPressed(int key){
    //もし「f」キーを入力したら、フルクスリーン化
    switch (key) {
        case 'f':
            ofToggleFullscreen();
            break;
    }
}

void testApp::mouseMoved(int x, int y){
}

void testApp::mouseDragged(int x, int y, int button){
}

//マウスをクリックすると新規にパーティクルを追加
void testApp::mousePressed(int x, int y, int button){
    //CustomCircleクラスをインスタンス化、引数は現在のパーティクルの数
    CustomCircle *c = new CustomCircle(circles.size());
    //物理パラメータを設定
    c->setPhysics(1.0, 0, 0);
    //ワールドにパーティクル追加
    c->setup(box2d.getWorld(), ofGetWidth()/2+200, ofGetHeight()/2, 10);
    //衝突判定はしない
    c->fixture.filter.groupIndex = -1;
    //ベクターcirclesに追加
    circles.push_back(c);
    //自分以外の全てのパーティクルと「ばね」で接続
    for (int i = 0; i<circles.size(); i++) {
        //CustomJointクラスをインスタンス化
        CustomJoint *joint = new CustomJoint();
        //生成した｢ばね｣をワールドに追加
        joint->setup(box2d.getWorld(), circles[i]->body, circles[circles.size()-1]->body);
        joint->setLength(40);
        joint->setFrequency(0.1);
        joint->setDamping(2.0);
        //ベクターjointsに追加
        joints.push_back(joint);
    }
    //パーティクルの位置をマウスの座標に移動
    circles[circles.size()-1]->setPosition(mouseX, mouseY);
}

void testApp::mouseReleased(int x, int y, int button){
}

void testApp::windowResized(int w, int h){
    //ウィンドウをリサイズした際に、最初のパーティクルを画面の中心に移動する
    if (circles.size() > 0) {
        circles[0]->setPosition(ofGetWidth()/2, ofGetHeight()/2);
    }
}