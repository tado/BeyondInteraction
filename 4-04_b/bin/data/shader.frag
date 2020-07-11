#version 150

out vec4 outputColor;
uniform float time;

void main(){
	float red = sin(time * 4.0);
	float green = sin(time * 5.0);
	float blue = sin(time * 6.0);
	outputColor	= vec4(red,	green, blue, 1.0);
}