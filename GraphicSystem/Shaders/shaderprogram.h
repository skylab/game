#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H

#include "../pregraphic.h"

#include "shader.h"

class ShaderProgram
{
public:
    ShaderProgram(const char* vertexShaderName, const char* fragmentShaderName);
    ~ShaderProgram();

    const GLuint &GetShaderProgrammID(void) const;

    GLint GetAttribute(const char *attributeName);
    GLint GetUniform(const char *uniformName);

    operator unsigned int();

    //TODO CHECK STATUS

private:
    GLint mShaderProgramID;
    Shader *mVertexShader;
    Shader *mFragmentShader;
};

#endif // SHADERPROGRAM_H
