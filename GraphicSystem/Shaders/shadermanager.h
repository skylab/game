#ifndef SHADERMANAGER_H
#define SHADERMANAGER_H

#include "../../Common/precommon.h"
#include "../pregraphic.h"

#include "../../Infra/singleton.h"

#include "shaderprogram.h"

#include <map>

class ShaderManager : public Singleton<ShaderManager>
{
public:
    ShaderManager();
    ShaderProgram *GetShaderProgramm(const char *vertexShaderName, const char *fragmentShaderName);

private:
    std::map<std::pair<const char*, const char*>, ShaderProgram*> mShaderProgrammList;
};

#endif // SHADERMANAGER_H
