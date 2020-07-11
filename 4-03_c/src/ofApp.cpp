#include "ofApp.h"

void ofApp::setup() {
	ofSetFrameRate(60);
	ofBackground(0);
	//板の生成
	ofPlanePrimitive plane;
	plane.set(1000, 1000, 100, 100);
	//板のメッシュの抽出
	mesh = plane.getMesh();
}

void ofApp::update() {
	float scale = 100.0; //波の高さ
	float freq = 0.01; //波の周波数
	float speed = 0.4;
	//頂点の数だけくりかえし
	for (int i = 0; i < mesh.getVertices().size(); i++) {
		//頂点の座標を取り出す
		glm::vec3 pos = mesh.getVertices()[i];
		//z座標をsin波で変形する
		//x軸方向
		float zx = sin(pos.x * freq + ofGetElapsedTimef() * speed) * scale;
		//y軸方向
		float zy = sin(pos.y * freq + ofGetElapsedTimef() * speed) * scale;
		//x軸方向y軸方向の2つの波を足しあわせる
		pos.z = zx + zy;
		//座標の位置を再設定する
		mesh.setVertex(i, pos);
	}
}

void ofApp::draw() {
	cam.begin();
	ofRotateXDeg(-45);
	//ワイヤーフレームでメッシュを描画
	mesh.drawWireframe();
	cam.end();
}