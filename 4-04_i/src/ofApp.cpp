#include "ofApp.h"

void ofApp::setup() {
	ofSetFrameRate(60);
	ofBackground(0);
	//板の生成
	ofPlanePrimitive plane;
	plane.set(2500, 2500, 200, 200);
	//板のメッシュの抽出
	mesh = plane.getMesh();
	//shaderのロード
	shader.load("shader");
}

void ofApp::update() {
	float div = 400.0; //ノイズの細かさ
	float scale = 400.0; //ノイズの大きさ
	float speed = 0.5; //ノイズの速度
	for (int i = 0; i < mesh.getVertices().size(); i++) {
		//頂点の座標を取得
		glm::vec3 pos = mesh.getVertices()[i];
		//Perlinノイズで波を生成
		pos.z = ofNoise(pos.x / div, pos.y / div, ofGetElapsedTimef() * speed) * scale;
		mesh.setVertex(i, pos);
	}
}

void ofApp::draw() {
	//画面の中心に球を描画しShaderを適用
	ofSetColor(255);
	ofEnableDepthTest();
	//カメラ開始
	cam.begin();
	//shader開始
	shader.begin();
	shader.setUniform1f("time", ofGetElapsedTimef());
	shader.setUniform2f("resolution", ofGetWidth(), ofGetHeight());
	//回転
	ofRotateXDeg(150);
	//メッシュの描画
	mesh.draw();
	//shader終了
	shader.end();
	//カメラ終了
	cam.end();
}
