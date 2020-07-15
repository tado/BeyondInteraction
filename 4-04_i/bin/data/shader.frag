#version 150

uniform vec2 resolution;
uniform float time;
in vec4 coordVarying;
out vec4 outputColor;

void main() {
    //RGBでカラーのグラデーションを生成
    float r = cos(coordVarying.z / 80.0) * 0.5 + 1.0;
    float g = cos(coordVarying.z / 60.0) * 0.5 + 1.0;
    float b = cos(coordVarying.z / 40.0) * 0.5 + 1.0;
    //アルファ値で横向きの透明ストライプに
    float a = sin(coordVarying.y / 4.0 + time * 2.0) * 2.0;
    //色と透明度を適用して出力
    outputColor = vec4 (r, g, b, a);
}