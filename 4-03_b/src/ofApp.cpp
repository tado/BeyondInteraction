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
	//頂点の数だけくりかえし
	for (int i = 0; i < mesh.getVertices().size(); i++) {
		//頂点の座標を取り出す
		glm::vec3 pos = mesh.getVertices()[i];
		//z座標のみランダムに変更
		pos.z = ofRandom(-100, 100);
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