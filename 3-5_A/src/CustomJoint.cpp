#include "CustomJoint.h"
void CustomJoint::draw()
{
    //バネがアクティブではなければ、なにもしない
    if(!alive) return;
    
    //接続する2つの物体の位置を取得
    b2Vec2 p1 = joint->GetAnchor1();
    b2Vec2 p2 = joint->GetAnchor2();
    p1 *= OFX_BOX2D_SCALE;
    p2 *= OFX_BOX2D_SCALE;
    
    //接続する距離に応じて透明度を調整して、線を描く
    //2つの物体の距離を算出
    float dist = ofDist(p1.x, p1.y, p2.x, p2.y);
    //スムーズに描画
    ofEnableSmoothing();
    //ぬり潰しなし
    ofNoFill();
    //線の太さ設定
    ofSetLineWidth(2);
    //透明度を距離に応じて変化させる。距離が近いほど濃くなる
    ofSetColor(255, 255, 255, 100-(dist/3.0));
    //線を描画
    ofLine(p1.x, p1.y, p2.x, p2.y);
    //スムース描画をoffに
    ofDisableSmoothing();
}