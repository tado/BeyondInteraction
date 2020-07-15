#version 150

out vec4 outputColor;
uniform float time;
uniform vec2 resolution;

void main(){
    vec2 uv = gl_FragCoord.xy / resolution.xy;
    float red = sin(uv.x * 10.0 + time * 20.0);
    float green = sin(uv.x * 10.0 + time * 30.0);
    float blue = sin(uv.x * 10.0 + time * -20.0);
    outputColor	= vec4(red,	green, blue, 1.0);
}
