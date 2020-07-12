#version 150

out vec4 outputColor;
uniform float time;
uniform vec2 resolution;

void main(void) {
    //画面の中心から(-1.0, -1.0)から(1.0, 1.0)の範囲の座標に変換し縦横の比率を揃える
    vec2 uv = (gl_FragCoord.xy * 2.0 - resolution) / vec2(resolution.x, resolution.x);
    //画面中心からの距離を算出
    float r = length(uv);
    //画面中心からの距離でsin波を生成し同心円状の波に
    float red = sin(r * 60.0 - time * 40.0);
    float green = sin(r * 60.0 - time * 40.0 - 1.0);
    float blue = sin(r * 60.0 - time * 40.0 - 2.0);
    //ピクセルを書き出し
    outputColor    = vec4(red,    green, blue, 1.0);
}
