#include "CustomCircle.h"

void CustomCircle::draw()
{
    float radius = getRadius(); //半径を取得
    glPushMatrix(); //座標を変更
    glTranslatef(getPosition().x, getPosition().y, 0); //物体の位置に座標を移動
    ofFill(); //色を塗り潰す
    ofSetColor(31,127,255,100); //円1の色を設定
    ofCircle(0, 0, radius);     //円1を描画
    ofSetColor(31,127,255,200); //円2の色を設定
    ofCircle(0, 0, radius*0.7); //円2を描画
    glPopMatrix(); //座標を元に戻す
}