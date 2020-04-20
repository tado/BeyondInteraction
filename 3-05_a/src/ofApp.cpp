#include "ofApp.h"

void ofApp::setup(){
    //画面基本設定
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofBackgroundHex(0x000000);
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    
    //Box2dの初期化
    box2d.init();
    box2d.setGravity(0, 0);
    box2d.setFPS(30.0);
    
    //画像の読みこみ
    particleImage.load("emitter.png");
    dacImage.load("particle.png");
    
    //中心のパーティクルの設定
    //衝突判定をしない
    dac.fixture.filter.groupIndex = -1;
    //画面の中心に追加
    dac.setup(box2d.getWorld(), ofGetWidth()/2, ofGetHeight()/2, 1, 1);
}

void ofApp::update(){
    //Box2dの更新
    box2d.update();
    //全てのパーティクルの状態を更新
    for(int i=0; i<particles.size(); i++) {
        //座標の更新
        particles[i]->update();
        //中心の物体からの引力を計算
        particles[i]->addAttractionPoint(dac.getPosition(), 0.1);
        //全てのパーティクル同士の引力を計算
        for (int j = i + 1; j < particles.size(); j++) {
            particles[j]->addAttractionPoint(particles[i]->getPosition(), 0.001);
        }
    }
}

void ofApp::draw(){
    //パーティクル同士を結ぶ線を描く
    for(int i=0; i<particles.size(); i++) {
        //パーティクルの位置を取得
        ofVec2f p1 (particles[i]->getPosition());
        //全てのパーティクル間の距離を算出
        for (int j = i + 1; j < particles.size(); j++) {
            ofVec2f p2 (particles[j]->getPosition());
            float dist = p2.distance(p1);
            //距離が300ピクセル以内だったら、線を描く
            if (dist < 300) {
                int col = (300 - dist);
                ofSetColor(255, 255, 255, col);
                ofDrawLine(p1.x, p1.y, p2.x, p2.y);
            }
        }
    }
    //全てのパーティクルの位置へ画像を描画
    ofSetColor(255, 255, 255);
    for(int i=0; i<particles.size(); i++) {
        //半径を計算
        float radius = particles[i]->radius;
        //画像を配置
        particleImage.draw(particles[i]->getPosition() - radius / 2.0, radius, radius);
    }
    //音量の合計を算出
    float allAmp = 0;
    for (int i = 0; i < particles.size(); i++) {
        allAmp += particles[i]->amp;
    }
    //音量の合計をもとに中心の星の半径を計算
    float dacRadius = sin(ofGetElapsedTimef() * 100.0) * allAmp * 20.0 + allAmp * 40.0 + 40.0;
    ofVec2f offset(dacRadius, dacRadius);
    //中心の星を描画
    dacImage.draw(dac.getPosition() - offset, dacRadius * 2.0, dacRadius * 2.0);
}

void ofApp::keyPressed(int key){
    //もし「f」キーを入力したら、フルクスリーン化
    if (key == 'f') {
        ofToggleFullscreen();
    }
    //もし「c」キーを押したら、全てのパーティクルを消去
    if (key == 'c') {
        for (int i = 0; i < particles.size(); i++) {
            particles[i]->destroy();
        }
        particles.clear();
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
    //CustomRectクラスをインスタンス化
    auto rect = make_shared<CustomRect>(particles.size());
    //物理パラメータを適用
    rect->setPhysics(10.0, 0.1, 0.5);
    //衝突判定をしないように設定
    rect->fixture.filter.groupIndex = -1;
    //Box2dの世界に追加
    rect->setup(box2d.getWorld(), mouseX, mouseY, 10, 10);
    //パーティクルのVector配列particlesに追加
    particles.push_back(rect);
}

void ofApp::windowResized(int w, int h){
    //ウィンドウのサイズを変更したら、中心の星の位置を修正
    dac.setPosition(ofGetWidth()/2, ofGetHeight()/2);
}

void ofApp::gotMessage(ofMessage msg){
}

void ofApp::dragEvent(ofDragInfo dragInfo){ 
}
