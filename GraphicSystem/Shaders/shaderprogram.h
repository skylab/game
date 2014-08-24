#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H

#include "../pregraphic.h"

#include "shader.h"

class ShaderProgram
{
public:
    ShaderProgram() throw();
    ~ShaderProgram() throw();

    GLint GetAttribute(const char *attributeName) throw();
    GLint GetUniform(const char *uniformName) throw();

    operator int() throw();

    //TODO CHECK STATUS

private:
    GLint mShaderProgramID;
    Shader *mVertexShader;
    Shader *mFragmentShader;
};

#endif // SHADERPROGRAM_H
