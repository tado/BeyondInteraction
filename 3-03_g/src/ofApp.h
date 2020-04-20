#pragma once //インクルードガード

#include "ofMain.h"
#include "Ball.h" //Blob.hをインクルード
class ofApp : public ofBaseApp {
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed  (int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void gotMessage(ofMessage msg);
    void dragEvent(ofDragInfo dragInfo);
    
    //Ballのインスタンスを格納するvector(動的配列)balls
    vector <Ball> balls;
};
