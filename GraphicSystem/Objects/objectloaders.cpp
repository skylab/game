#include "objectloaders.h"

/*
#include <iostream>
#include <cstring>

ObjectLoaders *ObjectLoaders::mInstance = nullptr;

ObjectLoaders::ObjectLoaders()
{
    ;
}

ObjectLoaders *ObjectLoaders::Instance(void)
{
    if (nullptr == mInstance)
    {
        try
        {
            mInstance = new ObjectLoaders;
        }
        catch(std::bad_alloc &ba)
        {
            (void)ba;
            std::cerr << "Can't allocate ObjectLoader" << std::cerr;
        }
    }
    return mInstance;
}

bool ObjectLoaders::LoadObject(ObjectAbs *object, const char *objectFile)
{
    if (nullptr == objectFile || nullptr == object)
    {
        std::cerr << "Invalid " << (nullptr == objectFile? "file pointer" : "object pointer") << std::endl;
        return false;
    }

    //3ds file
    if (strstr(objectFile, ".3ds"))
    {
        return m3dsLoader.LoadObject(object, objectFile);
    }

    return false;
}
*/
