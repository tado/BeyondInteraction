#version 150

// 座標の変換行列
uniform mat4 modelViewProjectionMatrix;
// openFrameworksから入力された頂点の3D座標
in vec4 position;
// フラグメントシェーダーにわたす頂点の3D座標
out vec4 coordVarying;

void main() {
    //モデルの頂点の3D座標をフラグメントシェーダーへ
    coordVarying = position;
    gl_Position = modelViewProjectionMatrix * position;
}