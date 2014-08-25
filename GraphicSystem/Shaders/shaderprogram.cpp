#include "shaderprogram.h"

ShaderProgram::ShaderProgram(const char *vertexShaderName, const char *fragmentShaderName) : mShaderProgramID(0), mVertexShader(NULL), mFragmentShader(NULL)
{
    mVertexShader = new (std::nothrow) Shader(GL_VERTEX_SHADER, vertexShaderName);
    if (NULL == mVertexShader)
    {
        std::cerr << "Can't allocate vertex shader" << std::endl;
        return;
    }

    mFragmentShader = new (std::nothrow) Shader(GL_FRAGMENT_SHADER, fragmentShaderName);
    if (NULL == mVertexShader)
    {
        std::cerr << "Can't allocate fragment shader" << std::endl;
        return;
    }

    mShaderProgramID = glCreateProgram();

    mVertexShader->CompileShader();
    mFragmentShader->CompileShader();

    glAttachShader(mShaderProgramID, *mVertexShader);
    glAttachShader(mShaderProgramID, *mFragmentShader);

    glLinkProgram(mShaderProgramID);

#ifdef DEBUG_SHADER_PROGRAMM
    std::cerr << "##LOG_BEGIN##" << std::endl;
    char log[1000];
    GLint logLength = 0;
    glGetProgramInfoLog(*this, 1000, &logLength, log);
    std::cerr << "##LOG_END##" << std::endl;
#endif

    int link_ok;
    glGetProgramiv(mShaderProgramID, GL_LINK_STATUS, &link_ok);
    if(!link_ok)
    {
        std::cerr << "Can't link shaders" << std::endl;
      return;
    }
}

ShaderProgram::~ShaderProgram()
{
    delete mVertexShader;
    delete mFragmentShader;
    glDeleteProgram(mShaderProgramID);
}

GLint ShaderProgram::GetUniform(const char *uniformName)
{
    GLint uniformLocation = glGetUniformLocation(*this, uniformName);
    if (-1 == uniformLocation)
        std::cerr << "Can't take uniform " << uniformName << std::endl;
    return uniformLocation;
}

GLint ShaderProgram::GetAttribute(const char *attributeName)
{
    GLint attributeLocation = glGetAttribLocation(*this, attributeName);
    if (-1 == attributeLocation)
        std::cerr << "Can't take attribute " << attributeName << std::endl;
    return attributeLocation;
}

ShaderProgram::operator int()
{
    return mShaderProgramID;
}
