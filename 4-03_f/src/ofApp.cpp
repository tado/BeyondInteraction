#include "ofApp.h"

void ofApp::setup() {
	ofSetFrameRate(60);
	ofBackground(0);
	//球からメッシュを生成
	ofIcoSpherePrimitive sphere;
	sphere.setRadius(100);
	sphere.setResolution(5);
	mesh = sphere.getMesh();
	//ライトを設定
	light.setPosition(-400, 400, 800); //ライトの位置を設定
	light.enable(); //ライトを有効に
	//マテリアルを設定
	//環境色を設定
	material.setAmbientColor(ofColor(127, 127, 255));
	//拡散反射色を設定
	material.setDiffuseColor(ofColor(0, 127, 255));
	//鏡面反射色を設定
	material.setSpecularColor(ofColor(255, 255, 0, 127));
	//鏡面反射の強さを設定
	material.setShininess(120);
}

void ofApp::update() {
	float div = 400.0; //ノイズの細かさ
	float size = 340.0; //ノイズのサイズ
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
	ofEnableDepthTest(); //深度テストを有効に
	material.begin(); //マテリアル開始
	cam.begin();
	//回転
	ofRotateXDeg(ofGetElapsedTimef() * 10.0);
	ofRotateYDeg(ofGetElapsedTimef() * 15.0);
	//メッシュを描画
	mesh.draw();
	cam.end();
	material.end(); //マテリアルの終了
	ofDisableDepthTest();
}