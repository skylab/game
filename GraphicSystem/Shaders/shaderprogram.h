#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H

#include "../pregraphic.h"

#include "shader.h"

class ShaderProgram
{
public:
    ShaderProgram();
    ~ShaderProgram();

    GLint GetAttribute(const char *attributeName);
    GLint GetUniform(const char *uniformName);

    operator int();

    //TODO CHECK STATUS

private:
    GLint mShaderProgramID;
    Shader *mVertexShader;
    Shader *mFragmentShader;
};

#endif // SHADERPROGRAM_H
