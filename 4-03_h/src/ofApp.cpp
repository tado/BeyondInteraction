#include "ofApp.h"

void ofApp::setup() {
	ofSetFrameRate(60);
	ofBackground(0);
	//板からメッシュを生成
	ofPlanePrimitive plane;
	plane.set(1000, 1000, 100, 100);
	mesh = plane.getMesh();
	//カメラ入力のセットアップ
	grabber.setDeviceID(1);
	grabber.setup(640, 480);
}

void ofApp::update() {
	int meshWidth = grabber.getWidth();
	int meshHeight = grabber.getHeight();
	//カメラの入力を更新
	grabber.update();
	if (grabber.isFrameNew()) { // もしカメラのフレームが更新されていたら
		mesh.clear(); // メッシュを初期化
		// カメラの映像のピクセル情報を抽出
		ofPixels pixels = grabber.getPixels();
		// ピクセルごとに処理
		for (int i = 0; i < meshWidth; i++) {
			for (int j = 0; j < meshHeight; j++) {
				// ピクセルノRGB値を取得
				float r = (float)pixels[j * meshWidth * 3 + i * 3] / 255.0;
				float g = (float)pixels[j * meshWidth * 3 + i * 3 + 1] / 255.0;
				float b = (float)pixels[j * meshWidth * 3 + i * 3 + 2] / 255.0;
				// RGBから明度を算出
				float brightness = (r + g + b) / 3.0f;
				// 明度から頂点の位置を設定
				glm::vec3 vert = glm::vec3(i - meshWidth / 2, j - meshHeight / 2, brightness * 255.0);
				mesh.addVertex(vert);
				// 頂点の色はカメラのピクセルの値をそのまま使用
				ofFloatColor color = ofFloatColor(r, g, b, 0.8);
				mesh.addColor(color);
			}
		}
	}
}

void ofApp::draw() {
	ofEnableDepthTest(); //深度テストを有効に
	cam.begin();
	ofRotateZDeg(180); //上下反転
	glPointSize(3); //点の大きさを設定
	mesh.setMode(OF_PRIMITIVE_POINTS); //メッシュを点で描く
	mesh.draw(); //メッシュの描画
	cam.end();
	ofDisableDepthTest();
}