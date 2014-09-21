#ifndef OBJECTLOADERS_H
#define OBJECTLOADERS_H

class ObjectAbs;

//Loaders (in future, add new loader to private list)
#include "objectloader3ds.h"

class ObjectLoaders
{
public:
    static ObjectLoaders *Instance(void);
    ~ObjectLoaders();

    bool LoadObject(ObjectAbs *object, const char *objectFile);

private:
    ObjectLoaders(); // singleton
    static ObjectLoaders *mInstance;

private:
    ObjectLoader3ds m3dsLoader;
};

#endif // OBJECTLOADERS_H
