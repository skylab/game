#include "shaderprogram.h"

ShaderProgram::ShaderProgram(const char *vertexShaderName, const char *fragmentShaderName) : mShaderProgramID(0), mVertexShader(NULL), mFragmentShader(NULL)
{
    try
    {
        mVertexShader = new Shader(GL_VERTEX_SHADER, vertexShaderName);
    }
    catch(std::bad_alloc &ba)
    {
        (void)ba;
        std::cerr << "Can't allocate vertex shader" << std::endl;
        return;
    }

    if (NULL == mVertexShader)
    {
        std::cerr << "Can't allocate vertex shader" << std::endl;
        return;
    }

    try
    {
        mFragmentShader = new Shader(GL_FRAGMENT_SHADER, fragmentShaderName);
    }
    catch(std::bad_alloc &ba)
    {
        (void)ba;
        std::cerr << "Can't allocate fragment shader" << std::endl;
        return;
    }

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
    mVertexShader = nullptr;
    delete mFragmentShader;
    mFragmentShader = nullptr;
    glDeleteProgram(mShaderProgramID);
}

const GLuint &ShaderProgram::GetShaderProgrammID() const
{
    return mShaderProgramID;
}

GLint ShaderProgram::GetUniform(const char *uniformName)
{
    GLint uniformLocation = glGetUniformLocation(*this, uniformName);
    if (-1 == uniformLocation)
    {
        std::cerr << "Can't take uniform " << uniformName << std::endl;
    }
    return uniformLocation;
}

GLint ShaderProgram::GetAttribute(const char *attributeName)
{
    GLint attributeLocation = glGetAttribLocation(*this, attributeName);
    if (-1 == attributeLocation)
    {
        std::cerr << "Can't take attribute " << attributeName << std::endl;
    }
    return attributeLocation;
}

ShaderProgram::operator unsigned int()
{
    return mShaderProgramID;
}
