#ifndef SHADERMANAGER_H
#define SHADERMANAGER_H

#include "../Infra/singleton.h"

#include "../ObjectLevels/GraphicLevel/Shader/shaderprogramm.h"

class Shader;

class ShaderManager : public Singleton<ShaderManager>
{
public:
    ShaderManager();
    virtual ~ShaderManager();

    const char *GetName(void) const override;

    ShaderProgramm *GetShaderProgramm(const char *vertex, const char *fragment);

private:
    std::list<ShaderProgramm*> mShaderProgrammList;
    std::mutex mListOperations;
};

#endif // SHADERMANAGER_H
