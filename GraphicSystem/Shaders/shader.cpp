#include "shader.h"

#include <fstream>
#include <string.h>

static const char* defaultVertexShader =
        "#version 330\n"
        "layout (location = 0) in vec3 VertexCoordinate;\n"
        "layout (location = 1) in vec3 Color;\n"
        "layout (location = 2) in vec2 vertexUV;\n"
        "\n"
        "uniform mat4 PVMTranslationRotationScaleMatrix;\n"
        "out vec3 fragmentColor;\n"
        "out vec2 UV;\n"
        "\n"
        "void main() {\n"
            "gl_Position = PVMTranslationRotationScaleMatrix * vec4(VertexCoordinate, 1.0f);\n"
            "fragmentColor = VertexCoordinate;\n"
            "UV = vertexUV;\n"
        "}\n";

static const char* defaultFragmentShader =
        "#version 330 core\n"
        "in vec3 fragmentColor;\n"
        "in vec2 UV;\n"
        "out vec3 color;\n"
        "uniform sampler2D textureSampler;\n"
        "void main()\n"
        "{\n"
            "if (UV.x == 0 && UV.y == 0)\n"
                "color = fragmentColor;\n"
            "else\n"
                "color = texture2D(textureSampler, UV).rgb;\n"
        "}\n";


Shader::Shader(GLint shaderType, const char *filename): mShaderType(shaderType), mShaderID(0), mShaderSourceCode(0)
{
    try
    {
        mShaderID = glCreateShader(mShaderType);
    }
    catch(...)
    {
        std::cerr << "Unknown error on Shader" << std::endl;
        return;
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

        unsigned int readed = shaderFile.gcount();
        #ifndef __linux__
                readed = mShaderSourceCodeLength;
        #endif

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
            #endif
        }
        shaderFile.close();
    }
    else
    {
        std::cerr << strerror(errno) << ": " << filename << std::endl;

        std::cerr << "Loading default: " << (mShaderType == GL_VERTEX_SHADER? "VERTEX" : "FRAGMENT") << " shader" << std::endl;
        switch(mShaderType)
        {
        case GL_VERTEX_SHADER:
            mShaderSourceCode = const_cast<char*>(defaultVertexShader);
            return true;
            break;
        case GL_FRAGMENT_SHADER:
            mShaderSourceCode = const_cast<char*>(defaultFragmentShader);
            return true;
            break;
        default:
            std::cerr << "Unknown shader type: " << mShaderType << std::endl;
            return false;
            break;
        }
    }
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
