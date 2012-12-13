#include "ofxVectorMath.h"
#include "ofxBox2d.h"

class CustomJoint : public ofxBox2dJoint {
public:
    //「ばね」を描画
    void draw();
};