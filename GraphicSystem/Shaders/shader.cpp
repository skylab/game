#include "shader.h"

#include <fstream>

#include <string.h>

Shader::Shader(GLint shaderType, const char *filename): mShaderType(shaderType), mShaderID(0), mShaderSourceCode(0)
{
    try
    {
        mShaderID = glCreateShader(mShaderType);
    }
    catch(...)
    {
        std::cerr << "Unknown error on Shader" << std::endl;
    }

    LoadFromFile(filename);
}

Shader::~Shader()
{
    glDeleteShader(mShaderID);
}

bool Shader::LoadFromFile(const char *filename)
{
    std::fstream shaderFile(filename, std::ios_base::in);
    if (shaderFile.is_open())
    {
        shaderFile.seekg(0, shaderFile.end);
        mShaderSourceCodeLength = shaderFile.tellg();
        shaderFile.seekg(0, shaderFile.beg);

        mShaderSourceCode = new (std::nothrow) char[mShaderSourceCodeLength];
        if (NULL == mShaderSourceCode)
        {
#ifdef DEBUG_SHADER
            std::cerr << "Can't allocate shader source code space:" << filename << std::endl;
#endif
            return false;
        }

        memset(mShaderSourceCode, 0, mShaderSourceCodeLength);

        shaderFile.read(mShaderSourceCode, mShaderSourceCodeLength);
        int readed = shaderFile.gcount();
        if (readed == mShaderSourceCodeLength)
        {
            mShaderSourceCode[mShaderSourceCodeLength-1] = '\0';
#ifdef DEBUG_SHADER
            std::cerr << mShaderSourceCode << std::endl;
#endif
            shaderFile.close();
            return true;
        }
        else
        {
#ifdef DEBUG_SHADER
            std::cerr << "Can't read shader source code fully:" << filename << std::endl;

            // TODO WHY on windows this sheet.
            shaderFile.close();
            return true;
#endif
        }
        shaderFile.close();
    }
#ifdef DEBUG_SHADER
    std::cerr << "Can't open shader source code:" << filename << std::endl;
#endif
    return false;
}

bool Shader::CompileShader()
{
    glShaderSource(mShaderID, 1, (const char**)&mShaderSourceCode, 0);
    glCompileShader(mShaderID);

    GLint status;
    glGetShaderiv(mShaderID, GL_COMPILE_STATUS, &status);
    if (status != 1)
    {
#ifdef DEBUG_SHADER
        if (GL_VERTEX_SHADER == mShaderType)
            std::cerr << "Vertex shader compile status " << status << std::endl;
        if (GL_FRAGMENT_SHADER == mShaderType)
            std::cerr << "Fragment shader compile status " << status << std::endl;
#endif
    }

#ifdef DEBUG_SHADER
    std::cerr << "##LOG_BEGIN##" << std::endl;
    char log[1000];
    GLint logLength = 0;
    glGetShaderInfoLog(*this, 1000, &logLength, log);
    std::cerr << "##LOG_END##" << std::endl;
#endif

    return status;
}

Shader::operator int()
{
    return mShaderID;
}
