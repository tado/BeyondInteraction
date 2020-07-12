#version 150

out vec4 outputColor;
uniform float time;
uniform vec2 resolution;

void main(){
    //スクリーンの座標を0.0〜1.0の範囲に正規化
    vec2 uv = gl_FragCoord.xy / resolution.xy;
    //RGBそれぞれでsin波のアニメションを生成
    float red = sin(uv.x * 10.0 + time * 20.0);
    float green = sin(uv.x * 10.0 + time * 30.0);
    float blue = sin(uv.x * 10.0 + time * -20.0);
    //ピクセルに出力
    outputColor	= vec4(red,	green, blue, 1.0);
}
