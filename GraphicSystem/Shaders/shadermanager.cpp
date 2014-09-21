#include "shadermanager.h"

ShaderManager *ShaderManager::mInstance = nullptr;

ShaderManager *ShaderManager::Instance()
{
    if (nullptr == mInstance)
    {
        try
        {
            mInstance = new ShaderManager();
        }
        catch(std::bad_alloc &ba)
        {
            (void)ba;
        }
    }
    return mInstance;
}

ShaderProgram *ShaderManager::GetShaderProgramm(const char *vertexShaderName, const char *fragmentShaderName)
{
    if (nullptr == vertexShaderName || nullptr == fragmentShaderName)
    {
        //TODO
        return nullptr;
    }

    /*
    //Try found shader
    try
    {
        mShaderProgrammList.at( std::pair<const char*,const char*>(vertexShaderName, fragmentShaderName) );
        return mShaderProgrammList[std::pair<const char*,const char*>(vertexShaderName, fragmentShaderName)];
    }
    catch(std::out_of_range &out)
    {
        //So, need create this shader programm;
    }*/

    ShaderProgram *programm = nullptr;
    try
    {
        programm = new ShaderProgram(vertexShaderName, fragmentShaderName);
    }
    catch(std::bad_alloc &ba)
    {
        //TODO
        (void)ba;
    }

    mShaderProgrammList[std::pair<const char*,const char*>(vertexShaderName, fragmentShaderName)] = programm;
    return mShaderProgrammList[std::pair<const char*,const char*>(vertexShaderName, fragmentShaderName)];
}

ShaderManager::ShaderManager()
{
}
