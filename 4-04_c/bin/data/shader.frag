#version 150

out vec4 outputColor;
uniform float time;
uniform vec2 resolution;

void main(){
	float red = gl_FragCoord.x / resolution.x;
	float green = 0.5;
	float blue = gl_FragCoord.y / resolution.y;
	outputColor	= vec4(red,	green, blue, 1.0);
}