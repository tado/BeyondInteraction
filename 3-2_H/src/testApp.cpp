#include "testApp.h"

void testApp::setup(){
    //画面の基本設定
    ofBackground(0,0,0);
    ofEnableSmoothing();
    //画面の混色の設定を加算合成にする
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    //画像データの読込み
    myImage.loadImage("MonaLisa.jpg");
}

void testApp::update(){
}

void testApp::draw(){
    //色の設定
    ofSetColor(255, 255, 255);
    //読み込んだ画像データを画面に描画
    myImage.draw(20,20);
    //画像データのビットマップ情報を配列に格納
    unsigned char * pixels = myImage.getPixels();
    //画像の幅と高さを所得
    int w = myImage.width;
    int h = myImage.height;
    //画像を8ピクセル間隔でスキャン
    for (int i = 0; i < w; i+=8){
        for (int j = 0; j < h; j+=8){
            //ピクセルのRGBの値を取得
            int valueR = pixels[j*3 * w + i*3];
            int valueG = pixels[j*3 * w + i*3+1];
            int valueB = pixels[j*3 * w + i*3+2];
            //取得したRGB値をもとに、円を描画
            //取得したピクセルの明るさを、円の半径に対応させている
            ofSetColor(255, 0, 0, 63);
            ofCircle(440+i, 20+j, 10*valueR/255.0);
            ofSetColor(0, 255, 0, 63);
            ofCircle(440+i, 20+j, 10*valueG/255.0);
            ofSetColor(0, 0, 255, 63);
            ofCircle(440+i, 20+j, 10*valueB/255.0);
        }
    }
}

void testApp::keyPressed(int key){
    //「x」キーを押すと、画面をキャプチャーする
    if(key == 'x'){
        //位置とサイズを指定して、画面をキャプチャー
        grabbedImage.grabScreen(430,10,420,642);
        //キャプチャーした画像データを「grabbedImage.png」で保存
        grabbedImage.saveImage("grabbedImage.png");
    }
}

void testApp::keyReleased(int key){
}

void testApp::mouseMoved(int x, int y){
}

void testApp::mouseDragged(int x, int y, int button){
}

void testApp::mousePressed(int x, int y, int button){
}

void testApp::mouseReleased(int x, int y, int button){
}

void testApp::windowResized(int w, int h){
}