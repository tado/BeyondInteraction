#include "CustomRect.h"

CustomRect::CustomRect(int _num) {
    num = _num;
    //音程の配列を生成
    float notes[] = {1.0, 5.0/4.0, 4.0/3.0, 3.0/2.0};
    float base[] = {8.0, 4.0, 2.0, 1.0, 0.5};
    //サウンドファイルの読みこみ
    mySound.loadSound("ambientSound.wav");
    //音程を決める
    soundSpeed = notes[num%4] / base[num%5];
    //設定したスピード(音程)で再生
    mySound.setSpeed(soundSpeed);
    //ループをONに
    mySound.setLoop(true);
    //音量を0に
    amp = 0;
    //再生開始
    mySound.play();
    //円の伸縮スピードをランダムに決定
    lfo = ofRandom(0.5, 2.0);
}

void CustomRect::update() {
    //半径を計算
    radius = sin(ofGetElapsedTimef() * 10.0 * lfo) * 20 + 40;
    //中心からの距離を計算
    ofVec2f pos = getPosition();
    float dist = pos.distance(ofPoint(ofGetWidth()/2, ofGetHeight()/2));
    //中心からの距離によって音量を計算
    amp = (1.0 - dist/400.0)*0.2;
    if (amp < 0) {
        amp = 0;
    }
    //音量を適用する
    mySound.setVolume(amp);
}