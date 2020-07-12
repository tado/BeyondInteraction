#version 150

// 座標の変換行列
uniform mat4 modelViewProjectionMatrix;
// openFrameworksから入力された頂点の座標
in vec4 position;

void main(){
    // GLSLの座標とスクリーン上の座標を一致させる
    gl_Position = modelViewProjectionMatrix * position;
}
