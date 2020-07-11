#version 150

out vec4 outputColor;
uniform float time;
uniform vec2 resolution;

void main(){
	float red = sin(gl_FragCoord.x / 60.0 + time * 20.0);
	float green = sin(gl_FragCoord.x / 50.0 + time * 30.0);
	float blue = sin(gl_FragCoord.x / 40.0 + time * -20.0);
	outputColor	= vec4(red,	green, blue, 1.0);
}