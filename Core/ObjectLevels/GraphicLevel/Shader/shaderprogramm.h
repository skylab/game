#ifndef SHADERPROGRAMM_H
#define SHADERPROGRAMM_H

class Shader;

class ShaderProgramm
{
public:
    ShaderProgramm(const char *vertex, const char *fragment);
    ~ShaderProgramm();

    operator int();
    int &ID(void);

    int GetUniform(const char *uniformName);

    const char *GetVertexShaderName(void) const;
    const char *GetFragmentShaderName(void) const;

private:
    int mID;

    Shader *mVertexShader;
    Shader *mFragmentShader;
};

#endif // SHADERPROGRAMM_H
