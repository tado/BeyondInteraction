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
	float div = 400.0; //ノイズの細かさ
	float scale = 300.0; //ノイズの大きさ
	float speed = 0.25; //ノイズの速度
	for (int i = 0; i < mesh.getVertices().size(); i++) {
		//頂点の座標を取得
		glm::vec3 pos = mesh.getVertices()[i];
		//Perlinノイズで波を生成
		pos.z = ofNoise(pos.x / div, pos.y / div, ofGetElapsedTimef() * speed) * scale;
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