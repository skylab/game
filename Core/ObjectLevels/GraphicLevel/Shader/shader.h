#ifndef SHADER_H
#define SHADER_H

class Shader
{
public:
    Shader(int shaderType, const char *shaderCodeFileName);
    ~Shader();

    operator int();
    const char *GetShaderFileName(void) const;

private:
    bool LoadShaderCode(const char *shaderCodeFileName);
    void LoadDefaultShader(void);

public:
    bool CompileShader(void);

private:
    int mID;
    int mType;
    const char *mShaderFileName;
    char *mShaderCode;
    int mShaderCodeLength;
};

#endif // SHADER_H
