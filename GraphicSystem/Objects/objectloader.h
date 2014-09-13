#ifndef OBJECTLOADER_H
#define OBJECTLOADER_H

class ObjectAbs;

//Loaders (in future, add new loader to private list)
#include "objectloader3ds.h"

class ObjectLoader
{
public:
    static ObjectLoader *Instance(void)
    {
        if (nullptr == mInstance)
        {
            try
            {
                mInstance = new ObjectLoader;
            }
            catch(std::bad_alloc &ba)
            {
                (void)ba;
                std::cerr << "Can't allocate ObjectLoader" << std::cerr;
            }
        }
        return mInstance;
    }

    ~ObjectLoader();

    bool LoadObject(ObjectAbs *object, const char *objectFile);

private:
    ObjectLoader();

private:
    static ObjectLoader *mInstance;

    ObjectLoader3ds m3dsLoader;
};

#endif // OBJECTLOADER_H
