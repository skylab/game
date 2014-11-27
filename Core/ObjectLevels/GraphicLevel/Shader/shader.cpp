#include "shader.h"

#include "../../../Infra/preinfra.h"
#include "../pregraphic.h"

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

Shader::Shader(int shaderType, const char *shaderCodeFileName) : mID(-1), mType(shaderType), mShaderCode(nullptr), mShaderCodeLength(0)
{
    try
    {
        mID = glCreateShader(mType);
    }
    catch(...)
    {
        std::cerr << __PRETTY_FUNCTION__ << ": Can't create: " << (mType == GL_VERTEX_SHADER? "Vertex" : "Fragment") << " shader." << std::endl;
        mID = -1;
        return;
    }
    if (!LoadShaderCode(shaderCodeFileName))
    {
        LoadDefaultShader();
    }
    CompileShader();
}

Shader::~Shader()
{
    if (-1 != mID)
        glDeleteShader(mID);

    if (defaultVertexShader != mShaderCode && defaultFragmentShader != mShaderCode)
    {
        delete[] mShaderCode;
    }
}

const char *Shader::GetShaderFileName() const
{
    return mShaderFileName;
}

bool Shader::LoadShaderCode(const char *shaderCodeFileName)
{
    std::fstream shaderFile(shaderCodeFileName, std::ios_base::in);
    if (shaderFile.is_open())
    {
        shaderFile.seekg(0, shaderFile.end);
        mShaderCodeLength = shaderFile.tellg();
        shaderFile.seekg(0, shaderFile.beg);

        try
        {
            mShaderCode = new char[mShaderCodeLength];
        }
        catch(std::bad_alloc &ba)
        {
            std::cerr << __PRETTY_FUNCTION__ << ":" << ba.what() << ": Can't allocate space to shader source code: " << shaderCodeFileName << std::endl;
            return false;
        }

        memset(mShaderCode, 0, mShaderCodeLength);

        shaderFile.read(mShaderCode, mShaderCodeLength);

        unsigned int readed = shaderFile.gcount();
        #ifndef __linux__
                // Linux work fine, but on windows - incorrect counter
                readed = mShaderCodeLength;
        #endif

        if (readed == mShaderCodeLength)
        {
            mShaderCode[mShaderCodeLength-1] = '\0';

            #ifdef DEBUG_SHADER
                std::cerr << mShaderCode << std::endl;
            #endif

            shaderFile.close();
            mShaderFileName = shaderCodeFileName;
            return true;
        }
        else
        {
            std::cerr << __PRETTY_FUNCTION__ << ": Can't read shader source code fully:" << shaderCodeFileName << std::endl;
        }
        shaderFile.close();
    }
    else
    {
        std::cerr << strerror(errno) << ": file: " << shaderCodeFileName << std::endl;
    }
    return false;
}

void Shader::LoadDefaultShader()
{
    switch(mType)
    {
    case GL_VERTEX_SHADER:
        std::cerr << "Loading default: VERTEX shader" << std::endl;
        mShaderCode = const_cast<char*>(defaultVertexShader);
        break;
    case GL_FRAGMENT_SHADER:
        std::cerr << "Loading default: FRAGMENT shader" << std::endl;
        mShaderCode = const_cast<char*>(defaultFragmentShader);
        break;
    default:
        std::cerr << __PRETTY_FUNCTION__ << ": Unknown shader type: " << mType << std::endl;
        break;
    }
}

bool Shader::CompileShader()
{
    glShaderSource(mID, 1, (const char**)&mShaderCode, 0);
    glCompileShader(mID);

    GLint status;
    glGetShaderiv(mID, GL_COMPILE_STATUS, &status);
    if (status != 1)
    {
        if (GL_VERTEX_SHADER == mType)
            std::cerr << "Vertex shader compile status " << status << std::endl;
        if (GL_FRAGMENT_SHADER == mType)
            std::cerr << "Fragment shader compile status " << status << std::endl;
    }

    char log[1000];
    GLint logLength = 0;
    glGetShaderInfoLog(*this, 1000, &logLength, log);

    return status;
}


Shader::operator int()
{
    return mID;
}
