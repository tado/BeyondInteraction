#version 150

uniform vec2 resolution;
uniform float time;
//頂点シェーダから渡された頂点の3D座標
in vec4 coordVarying;
out vec4 outputColor;

void main() {
    //x, y, z軸方向にそれぞれsin波でストライプ模様を描く
	float val_r = abs(sin(coordVarying.x * 10.0 + time * 8.0));
	float val_g = abs(sin(coordVarying.y * 10.0 + time * 8.0));
	float val_b = abs(sin(coordVarying.z * 10.0 + time * 8.0));
	outputColor = vec4 (val_r, val_g, val_b, 1.0);
}