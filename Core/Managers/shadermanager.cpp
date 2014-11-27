#include "shadermanager.h"

#include "../ObjectLevels/GraphicLevel/Shader/shaderprogramm.h"
#include "../Infra/preinfra.h"

ShaderManager::ShaderManager()
{
    ;
}

ShaderManager::~ShaderManager()
{
    mListOperations.lock();
    while (mShaderProgrammList.size() != 0)
    {
        ShaderProgramm *program = mShaderProgrammList.back();
        if (nullptr != program)
        {
            delete program;
        }
        mShaderProgrammList.remove(program);
    }
    mListOperations.unlock();
}

ShaderProgramm *ShaderManager::GetShaderProgramm(const char *vertex, const char *fragment)
{
    mListOperations.lock();
    for (auto i : mShaderProgrammList)
    {
        ShaderProgramm *program = i;
        if (nullptr != program)
        {
            if (!strcmp(program->GetVertexShaderName(), vertex) && !strcmp(program->GetFragmentShaderName(), fragment))
            {
                mListOperations.unlock();
                return program;
            }
        }
    }

    ShaderProgramm *program = nullptr;
    try
    {
        program = new ShaderProgramm(vertex, fragment);

        mShaderProgrammList.push_back(program);
    }
    catch(std::bad_alloc &ba)
    {
        std::cerr << __PRETTY_FUNCTION__ << ba.what() << ": Can't allocate shader programm" << std::endl;
        program = nullptr;
    }

    mListOperations.unlock();
    return program;
}
