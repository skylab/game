#version 330 core
layout (location = 0) in vec3 VertexCoordinate;
layout (location = 1) in vec3 Color;
uniform mat4 PVM;
out vec3 fragmentColor;
void main() {
    //gl_Position = PVM * TranslationMatrix * RotationMatrix * ScaleMatrix *vec4(VertexCoordinate, 1.0);
    gl_Position = PVM * vec4(VertexCoordinate, 1.0);
    //fragmentColor = Color;
    fragmentColor = VertexCoordinate;
}
