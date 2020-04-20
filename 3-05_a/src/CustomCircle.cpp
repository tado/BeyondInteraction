#include "CustomCircle.h"

//コンストラクタ、引数にパーティクル番号を受け取る
CustomCircle::CustomCircle(int _num){
    num = _num; //引数の_numをクラスのプロパティに代入
    radius = 0; //半径初期化
    
    //最初のパーティクルでなければ、サウンドを再生させる
    if (num > 0) {
        //音程の配列を生成
        float notes[] = {0.5, 0.75, 1, 1.5, 2.0, 3.0};
        //音程を決める
        soundSpeed = notes[((int)(ofRandom(0, 5)))];
        //サウンドファイルの読みこみ
        mySound.loadSound("ambientSound.wav");
        //ループをONに
        mySound.setLoop(true);
        //設定したスピード(音程)で再生
        mySound.setSpeed(soundSpeed);
        //画面の中心位置からの距離を計測
        float dist = ofDist(getPosition().x, getPosition().y, ofGetWidth()/2, ofGetHeight()/2);
        //再生音量を計算する
        float volume = (1.0 - dist/300.0)*0.2;
        //音量が0以下の場合は、0で固定
        if (volume < 0) {
            volume = 0;
        }
        //音量を適用する
        mySound.setVolume(volume);
        //サウンド再生開始
        mySound.play();
    }
}

void CustomCircle::update()
{
    //最初のパーティクルの時だけ、半径を全体の音量で変化させる
    if (num == 0) {
        float * vol = ofSoundGetSpectrum(1);
        radius = vol[0] * 2000;
        
    } else { //それ以外のパーティクルは音程によって伸縮せる
        //半径を算出
        radius = sin(mySound.getPosition()*TWO_PI*20)*20+5;
        //画面の中心位置からの距離を計測
        float dist = ofDist(getPosition().x, getPosition().y, ofGetWidth()/2, ofGetHeight()/2);
        //音量を計算する
        float volume = (1.0 - dist/300.0)*0.2;
        //定位(左右のバランス)を計算する
        float pan = getPosition().x / (float)ofGetWidth();
        //音量が0以下の場合は、0で固定
        if (volume < 0) {
            volume = 0;
        }
        //音量を適用する
        mySound.setVolume(volume);
        //定位を適用する
        mySound.setPan(pan);
    }
}

void CustomCircle::draw()
{
    //伸縮する円の外周
    ofFill();
    if (num == 0) { //最初のパーティクルは赤
        ofSetColor(255, 0, 0, 100);
    } else { //それ以外は青
        ofSetColor(0, 63, 255, 100);
    }
    //円を描画
    ofCircle(getPosition().x, getPosition().y, radius);
    
    //円の「核」
    if (num == 0) { //最初のパーティクルは赤
        ofSetColor(255, 0, 0);
    } else { //それ以外は青
        ofSetColor(0, 63, 255);
    }
    //円を描画
    ofCircle(getPosition().x, getPosition().y, 3);
}