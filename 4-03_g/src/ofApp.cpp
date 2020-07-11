#include "ofApp.h"

void ofApp::setup() {
	ofSetFrameRate(60);
	ofBackground(0);
	//球からメッシュを生成
	ofIcoSpherePrimitive sphere;
	sphere.setRadius(100);
	sphere.setResolution(5);
	mesh = sphere.getMesh();
	//ライトとマテリアルの設定
	light.setPosition(0, 0, 800);
	light.enable();
	material.setAmbientColor(ofColor(255));
	material.setDiffuseColor(ofColor(255));
	material.setSpecularColor(ofColor(255));
	material.setShininess(60);
	//テクスチャーのフォーマットを設定
	ofDisableArbTex();
	//カメラ入力をセットアップ
	grabber.setup(640, 480);
}

void ofApp::update() {
	//ノイズで球を変形
	float div = 300.0;
	float size = 340.0;
	for (int i = 0; i < mesh.getVertices().size(); i++) {
		glm::vec3 loc = mesh.getVertices()[i];
		float noise = ofMap(ofNoise(loc.x / div, loc.y / div, loc.z / div, ofGetElapsedTimef()), 0, 1, size / 2.0, size);
		glm::vec3 newLoc = glm::normalize(loc) * noise;
		mesh.setVertex(i, newLoc);
	}
	//カメラの入力を更新
	grabber.update();
}

void ofApp::draw() {
	grabber.getTexture().bind(); //カメラ入力をテクスチャーにバインド
	ofEnableDepthTest(); //深度テストを有効に
	material.begin(); //マテリアル開始
	cam.begin();
	mesh.draw(); //メッシュの描画
	cam.end();
	material.end(); //マテリアルの終了
	ofDisableDepthTest();
	grabber.getTexture().unbind(); //バインドしていたテクチャーを無効化
}