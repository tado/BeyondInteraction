#version 150

out vec4 outputColor;
uniform float time;
//openFrameworks側の画面の解像度 (幅, 高さ)
uniform vec2 resolution;

void main(){
    //赤: x座標方向に0.0〜1.0の範囲で変化するように値を調整
    float red = gl_FragCoord.x / resolution.x;
    //緑: 0.5に固定
    float green = 0.5;
    //青: y座標方向に0.0〜1.0の範囲で変化するように値を調整
    float blue = gl_FragCoord.y / resolution.y;
    //計算したグラデーションの値をピクセルの色に設定
    outputColor	= vec4(red,	green, blue, 1.0);
}
