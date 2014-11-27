#include "shaderprogramm.h"

#include "shader.h"
#include "../../../Infra/preinfra.h"
#include "../pregraphic.h"

ShaderProgramm::ShaderProgramm(const char *vertex, const char *fragment) : mID(0), mVertexShader(nullptr), mFragmentShader(nullptr)
{
    try
    {
        mVertexShader = new Shader(GL_VERTEX_SHADER, vertex);
    }
    catch(std::bad_alloc &ba)
    {
        (void)ba;
        std::cerr << __PRETTY_FUNCTION__ << ba.what() << ": Can't allocate vertex shader" << std::endl;
        return;
    }

    try
    {
        mFragmentShader = new Shader(GL_FRAGMENT_SHADER, fragment);
    }
    catch(std::bad_alloc &ba)
    {
        (void)ba;
        std::cerr << __PRETTY_FUNCTION__ << ba.what() << ": Can't allocate fragment shader" << std::endl;
        return;
    }

    mID = glCreateProgram();

    mVertexShader->CompileShader();
    mFragmentShader->CompileShader();

    glAttachShader(mID, *mVertexShader);
    glAttachShader(mID, *mFragmentShader);

    glLinkProgram(mID);

    char log[1000];
    GLint logLength = 0;
    glGetProgramInfoLog(*this, 1000, &logLength, log);

    int link_ok;
    glGetProgramiv(mID, GL_LINK_STATUS, &link_ok);
    if(!link_ok)
    {
        std::cerr << __PRETTY_FUNCTION__ << ": Can't link shaders" << std::endl;
      return;
    }
}

ShaderProgramm::~ShaderProgramm()
{
    mID = 0;
    glDeleteProgram(mID);
}

int ShaderProgramm::GetUniform(const char *uniformName)
{
    int uniformLocation = glGetUniformLocation(*this, uniformName);
    if (-1 == uniformLocation)
    {
        std::cerr << __PRETTY_FUNCTION__ << " :Can't take uniform: " << uniformName << std::endl;
    }
    return uniformLocation;
}

const char *ShaderProgramm::GetVertexShaderName() const
{
    return mVertexShader->GetShaderFileName();
}

const char *ShaderProgramm::GetFragmentShaderName() const
{
    return mFragmentShader->GetShaderFileName();
}

ShaderProgramm::operator int()
{
    return mID;
}
