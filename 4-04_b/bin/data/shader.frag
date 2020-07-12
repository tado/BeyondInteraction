#version 150

out vec4 outputColor;
uniform float time;

void main(){
    float red = sin(time * 12.0); //赤の点滅
    float green = sin(time * 13.0); //緑の点滅
    float blue = sin(time * 14.0); //青の点滅
    // 画面に出力
    outputColor	= vec4(red,	green, blue, 1.0);
}
