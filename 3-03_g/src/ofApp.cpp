#include "ofApp.h"

void ofApp::setup(){
    //画面の設定
    ofBackground(0, 0, 0);
    ofSetCircleResolution(32);
    ofEnableAlphaBlending();
    ofSetFrameRate(30);
}

void ofApp::update(){
    //ballsに格納されたBallのインスタンスの数だけupdate()をくりかえす
    for (int i = 0; i < balls.size(); i++) {
        balls[i].update();
    }
}

void ofApp::draw(){
    //ballsに格納されたBallのインスタンスの数だけdraw()をくりかえす
    for (int i = 0; i < balls.size(); i++) {
        balls[i].draw();
    }
}

void ofApp::keyPressed(int key){
}

void ofApp::keyReleased(int key){
    switch (key) { //タイプしたキーを判定
        case 'f': //入力したキーが「f」なら、フルスクリーン表示に切り替える
            ofToggleFullscreen();
            break;
        case 'r': //入力したキーが「r」なら、全ての円をクリア
            balls.clear();
    }
}

void ofApp::mouseMoved(int x, int y){
}

void ofApp::mouseDragged(int x, int y, int button){
}

void ofApp::mousePressed(int x, int y, int button){
}

void ofApp::mouseReleased(int x, int y, int button){
    int bSize = balls.size(); //ballsの要素数をbSizeに格納
    if (bSize < 1) { //もしまだ一つもなければ、新規にBallを追加
        Ball b = Ball(); //インスタンス化
        float radius = ofGetHeight()/3; //大きさを画面サイズの1/3に
        b.setRadius(radius); //大きさを設定
        b.setSpeed(ofPoint(0,0)); //スピードは0で設定
        b.setPos(ofPoint(mouseX, mouseY)); //位置は画面の中心に設定
        balls.push_back(b); //動的配列ballsにBallのインスタンスbを追加
    }
    
    //もし画面に1つでも円が表示されていたら、クリックした円を4つに分裂させる
    for (int i=0; i<bSize; i++) { //要素の数だけくりかえし
        ofPoint pos = balls[i].getPos(); //円の位置を取得してposに代入
        float radius = balls[i].getRadius(); //円の大きさを取得してradiusに代入
        float dist = ofDist(pos.x, pos.y, mouseX, mouseY); //マウスの位置と円の位置の距離を測定
        if(dist < radius){ //もしクリックした場所が円の内部だったら、分裂させる
            //円1：自分自身を縮小し、左に移動
            balls[i].setRadius(radius*0.6);
            balls[i].setPos(ofPoint(pos.x-radius*0.7,pos.y));
            balls[i].setSpeed(ofPoint(ofRandom(-radius/150,radius/150), ofRandom(-radius/150,radius/150)));
            
            //円2：新規にBallを生成し、右に配置
            Ball b1 = Ball();
            b1.setRadius(radius*0.6);
            b1.setPos(ofPoint(pos.x+radius*0.7,pos.y));
            b1.setSpeed(ofPoint(ofRandom(-radius/150,radius/150), ofRandom(-radius/150,radius/150)));
            balls.push_back(b1);
            
            //円3：新規にBallを生成し、上に配置
            Ball b2 = Ball();
            b2.setRadius(radius*0.6);
            b2.setPos(ofPoint(pos.x,pos.y-radius*0.7));
            b2.setSpeed(ofPoint(ofRandom(-radius/150,radius/150), ofRandom(-radius/150,radius/150)));
            balls.push_back(b2);
            
            //円4：新規にBallを生成し、下に配置
            Ball b3 = Ball();
            b3.setRadius(radius*0.6);
            b3.setPos(ofPoint(pos.x,pos.y+radius*0.7));
            b3.setSpeed(ofPoint(ofRandom(-radius/150,radius/150), ofRandom(-radius/150,radius/150)));
            balls.push_back(b3);
        }
    }
}


void ofApp::windowResized(int w, int h){
    
}

void ofApp::gotMessage(ofMessage msg){
    
}

void ofApp::dragEvent(ofDragInfo dragInfo){ 
    
}
