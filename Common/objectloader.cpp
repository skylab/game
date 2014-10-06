#include "objectloader.h"

/// LOADERS LIST BEGIN
#include "ObjectLoaders/loader3ds.h"
/// LOADERS LIST END

ObjectLoader *ObjectLoader::mInstance = nullptr;

ObjectLoader *ObjectLoader::Instance()
{
    if (nullptr == mInstance)
    {
        try
        {
            mInstance = new ObjectLoader();
        }
        catch(std::bad_alloc &ba)
        {
            //TODO;
            (void)ba;
            mInstance = nullptr;
        }
    }
    return mInstance;
}

bool ObjectLoader::LoadObjectFile(const char *filename, ObjectRaw *object)
{
    if (nullptr == filename || nullptr == object)
    {
        std::cerr << "Invalid " << (nullptr == filename? "file pointer" : "object pointer") << std::endl;
        return false;
    }

    //3ds file
    if (strstr(filename, ".3ds"))
    {
        Loader3ds loader;
        return loader.LoadObjectFile(filename, object);
    }

    return false;
}

ObjectLoader::ObjectLoader() : mCounterOfLoadedObjects(0)
{
    ;
}
