#version 440
layout (location = 0) in vec3 VertexCoordinate;
layout (location = 1) in vec3 Color;
uniform mat4 PVM;
uniform vec3 ObjectSize;
uniform vec3 ObjectRotation;
uniform vec3 ObjectPosition;

out vec3 fragmentColor;

void main() {
    mat4 ScaleMatrix;
    ScaleMatrix[0].xyzw = vec4(ObjectSize.x, 0.0f, 0.0f, 0.0f);
    ScaleMatrix[1].xyzw = vec4(0.0f, ObjectSize.y, 0.0f, 0.0f);
    ScaleMatrix[2].xyzw = vec4(0.0f, 0.0f, ObjectSize.z, 0.0f);
    ScaleMatrix[3].xyzw = vec4(0.0f, 0.0f, 0.0f, 1.0f);

    mat4 RotationMatrix;
    RotationMatrix[0].xyzw = vec4(1.0f, 0.0f, 0.0f, 0.0f);
    RotationMatrix[1].xyzw = vec4(0.0f, 1.0f, 0.0f, 0.0f);
    RotationMatrix[2].xyzw = vec4(0.0f, 0.0f, 1.0f, 0.0f);
    RotationMatrix[3].xyzw = vec4(0.0f, 0.0f, 0.0f, 1.0f);

    mat4 TranslationMatrix;
    TranslationMatrix[0].xyzw = vec4(1.0f, 0.0f, 0.0f, ObjectPosition.x);
    TranslationMatrix[1].xyzw = vec4(0.0f, 1.0f, 0.0f, ObjectPosition.y);
    TranslationMatrix[2].xyzw = vec4(0.0f, 0.0f, 1.0f, ObjectPosition.z);
    TranslationMatrix[3].xyzw = vec4(0.0f, 0.0f, 0.0f, 1.0f);

    //gl_Position = PVM * TranslationMatrix * RotationMatrix *ScaleMatrix * vec4(VertexCoordinate, 1.0);
    gl_Position = PVM * TranslationMatrix * RotationMatrix * ScaleMatrix * vec4(VertexCoordinate, 1.0);
    fragmentColor = VertexCoordinate;
}
