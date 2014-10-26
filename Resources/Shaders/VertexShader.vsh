#version 330
layout (location = 0) in vec3 VertexCoordinate;
layout (location = 1) in vec3 Color;
layout (location = 2) in vec2 vertexUV;

uniform mat4 PVMTranslationRotationScaleMatrix;
out vec3 fragmentColor;
out vec2 UV;

void main() {
    gl_Position = PVMTranslationRotationScaleMatrix * vec4(VertexCoordinate, 1.0f);
    fragmentColor = VertexCoordinate;
    UV = vertexUV;
}
