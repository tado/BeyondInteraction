#version 150

out vec4 outputColor;
uniform float time;
uniform vec2 resolution;

void main(void) {   
    vec2 uv = gl_FragCoord.xy / resolution;
    float r = length(vec2(0.5) - uv);
    float red = sin(r * 140.0 - time * 40.0);
    float green = sin(r * 144.0 - time * 40.0 - 1.0);
    float blue = sin(r * 146.0 - time * 40.0 - 2.0);
	outputColor	= vec4(red,	green, blue, 1.0);
}