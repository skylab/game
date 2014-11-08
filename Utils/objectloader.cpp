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
            std::cerr << ba.what() << " : Can't allocate ObjectLoader" << std::endl;
            mInstance = nullptr;
        }
    }
    return mInstance;
}

bool ObjectLoader::LoadObjectFile(const char *filename, Object *object)
{
    if (nullptr == filename || nullptr == object)
    {
        std::cerr << "Invalid " << (nullptr == filename? "file pointer" : "object pointer") << std::endl;
        return false;
    }

    //3ds file
    if (strstr(filename, ".3ds"))
    {
        // Another thread can load object separated because object in the stack.
        Loader3ds loader;
        return loader.LoadObjectFile(filename, object);
    }

    return false;
}

ObjectLoader::ObjectLoader() : mCounterOfLoadedObjects(0)
{
    ;
}
