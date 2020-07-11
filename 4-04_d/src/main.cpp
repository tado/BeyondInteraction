#include "ofMain.h"
#include "ofApp.h"

int main() {
	// 表示するWindowの設定を格納する
	ofGLFWWindowSettings settings;
	// OpenGLのバージョンを3.2に設定
	settings.setGLVersion(3, 2);
	// ウィンドウのサイズを設定
	settings.setSize(1024, 768);
	// 設定した内容でウィンドウを表示
	ofCreateWindow(settings);
	ofRunApp(new ofApp());
}
