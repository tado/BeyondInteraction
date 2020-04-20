#pragma once
#include "ofxBox2d.h"

class CustomRect : public ofxBox2dRect {
public:
	CustomRect(int _num); //コンストラクター
	void update(); //更新

	int num; //パーティクルの番号
    ofSoundPlayer mySound; //音の再生クラスofSoundPlayerをインスタンス化
    float soundSpeed; //音の再生スピード(ピッチ)
	float amp; //音量
    float lfo; //パーティクルの伸縮スピード
	float radius; //パーティクルの半径
};