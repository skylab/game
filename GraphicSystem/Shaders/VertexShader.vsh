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

    mat4 RotationMatrixX;
    RotationMatrixX[0].xyzw = vec4(1.0f, 0.0f, 0.0f, 0.0f);
    RotationMatrixX[1].xyzw = vec4(0.0f, cos(ObjectRotation.x), -sin(ObjectRotation.x), 0.0f);
    RotationMatrixX[2].xyzw = vec4(0.0f, sin(ObjectRotation.x), cos(ObjectRotation.x), 0.0f);
    RotationMatrixX[3].xyzw = vec4(0.0f, 0.0f, 0.0f, 1.0f);
    mat4 RotationMatrixY;
    RotationMatrixY[0].xyzw = vec4(cos(ObjectRotation.y), 0.0f, sin(ObjectRotation.y), 0.0f);
    RotationMatrixY[1].xyzw = vec4(0.0f, 1.0f, 0.0f, 0.0f);
    RotationMatrixY[2].xyzw = vec4(-sin(ObjectRotation.y), 0.0f, cos(ObjectRotation.y), 0.0f);
    RotationMatrixY[3].xyzw = vec4(0.0f, 0.0f, 0.0f, 1.0f);
    mat4 RotationMatrixZ;
    RotationMatrixZ[0].xyzw = vec4(cos(ObjectRotation.z), -sin(ObjectRotation.z), 0.0f, 0.0f);
    RotationMatrixZ[1].xyzw = vec4(sin(ObjectRotation.z), cos(ObjectRotation.z), 0.0f, 0.0f);
    RotationMatrixZ[2].xyzw = vec4(0.0f, 0.0f, 1.0f, 0.0f);
    RotationMatrixZ[3].xyzw = vec4(0.0f, 0.0f, 0.0f, 1.0f);

    mat4 RotationMatrix = RotationMatrixX * RotationMatrixY * RotationMatrixZ;

    mat4 TranslationMatrix;
    TranslationMatrix[0].xyzw = vec4(1.0f, 0.0f, 0.0f, 0.0f);
    TranslationMatrix[1].xyzw = vec4(0.0f, 1.0f, 0.0f, 0.0f);
    TranslationMatrix[2].xyzw = vec4(0.0f, 0.0f, 1.0f, 0.0f);
    TranslationMatrix[3].xyzw = vec4(ObjectPosition.x, ObjectPosition.y, ObjectPosition.z, 1.0f);

    gl_Position = PVM * TranslationMatrix * RotationMatrix * ScaleMatrix * vec4(VertexCoordinate, 1.0);
    fragmentColor = VertexCoordinate;
}
