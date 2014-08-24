#ifndef SHADER_H
#define SHADER_H

#include "../pregraphic.h"

class Shader
{
public:
    Shader(GLint shaderType, const char *filename);
    ~Shader();

    bool LoadFromFile(const char *);

    bool CompileShader();

    operator int();

    //TODO check status;

private:
    GLint mShaderType;
    GLuint mShaderID;
    char *mShaderSourceCode;
    unsigned int mShaderSourceCodeLength;
};

#endif // SHADER_H
