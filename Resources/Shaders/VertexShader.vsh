#version 330
layout (location = 0) in vec3 VertexCoordinate;
layout (location = 1) in vec3 Color;

uniform mat4 PVMTranslationRotationScaleMatrix;
out vec3 fragmentColor;

void main() {
    gl_Position = PVMTranslationRotationScaleMatrix * vec4(VertexCoordinate, 1.0f);
    fragmentColor = VertexCoordinate;
}
