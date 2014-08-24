#ifndef SHADER_H
#define SHADER_H

#include "../pregraphic.h"

class Shader
{
public:
    Shader(GLint shaderType, const char *filename) throw();
    ~Shader() throw();

    bool LoadFromFile(const char *) throw();

    bool CompileShader() throw();

    operator int();

    //TODO check status;

private:
    GLint mShaderType;
    GLuint mShaderID;
    char *mShaderSourceCode;
    unsigned int mShaderSourceCodeLength;
};

#endif // SHADER_H
