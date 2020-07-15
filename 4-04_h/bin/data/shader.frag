#version 150

uniform vec2 resolution;
uniform float time;
//頂点シェーダから渡された頂点の3D座標
in vec4 coordVarying;
out vec4 outputColor;

void main() {
    //x, y, z軸方向にそれぞれsin波でストライプ模様を描く
	float val_r = abs(sin(coordVarying.z * 0.16 + time * 12.0)) * 1.5;
	float val_g = abs(sin(coordVarying.z * 0.14 + time * 14.0)) * 1.5;
	float val_b = abs(sin(coordVarying.z * 0.12 + time * 16.0)) * 1.5;
	float val_a = abs(sin(coordVarying.z * 0.08 + time * 10.0));
	outputColor = vec4 (val_r, val_g, val_b, val_a);
}