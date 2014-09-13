#include "objectloader.h"

#include <iostream>
#include <cstring>

ObjectLoader *ObjectLoader::mInstance = nullptr;

ObjectLoader::ObjectLoader()
{    
    std::cerr << "ObjectLoader started" << std::endl;
}


bool ObjectLoader::LoadObject(ObjectAbs *object, const char *objectFile)
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
