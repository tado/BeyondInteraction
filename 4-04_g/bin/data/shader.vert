#version 150

uniform mat4 modelViewProjectionMatrix;
in vec4 position;
out vec4 coordVarying;

void main() {
    coordVarying = position;
    gl_Position = modelViewProjectionMatrix * position;
}
