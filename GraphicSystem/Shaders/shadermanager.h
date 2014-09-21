#ifndef SHADERMANAGER_H
#define SHADERMANAGER_H

#include "../../Common/precommon.h"
#include "../pregraphic.h"

#include "shaderprogram.h"

#include <map>

class ShaderManager
{
public:
    static ShaderManager *Instance();

    ShaderProgram *GetShaderProgramm(const char *vertexShaderName, const char *fragmentShaderName);

private:
    ShaderManager();

private:
    static ShaderManager *mInstance;

    std::map<std::pair<const char*, const char*>, ShaderProgram*> mShaderProgrammList;
};

#endif // SHADERMANAGER_H
