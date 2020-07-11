#include "ofApp.h"

void ofApp::setup() {
	ofSetFrameRate(60);
	ofBackground(0);
	//球からメッシュを生成
	ofIcoSpherePrimitive sphere;
	sphere.setRadius(100);
	sphere.setResolution(4);
	mesh = sphere.getMesh();
}

void ofApp::update() {
	float div = 400.0; //ノイズの細かさ
	float size = 360.0; //ノイズのサイズ
	//頂点の数だけ繰り返し
	for (int i = 0; i < mesh.getVertices().size(); i++) {
		//頂点の位置を取得
		glm::vec3 loc = mesh.getVertices()[i];
		//perlinノイズを生成
		float noise = ofMap(ofNoise(loc.x / div, loc.y / div, loc.z / div, ofGetElapsedTimef()), 0, 1, size / 2.0, size);
		//ノイズの値で球の頂点位置の半径を変更
		glm::vec3 newLoc = glm::normalize(loc) * noise;
		mesh.setVertex(i, newLoc);
	}
}

void ofApp::draw() {
	cam.begin();
	//回転
	ofRotateXDeg(ofGetElapsedTimef() * 10.0);
	ofRotateYDeg(ofGetElapsedTimef() * 15.0);
	//ワイヤーフレームでメッシュを描画
	mesh.drawWireframe();
	cam.end();
}