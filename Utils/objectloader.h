#ifndef OBJECTLOADER_H
#define OBJECTLOADER_H

//#include "precommon.h"

class ObjectRaw;

class ObjectLoader
{
public:
    static ObjectLoader *Instance(void);

    bool LoadObjectFile(const char *filename, ObjectRaw *object);

private:
    ObjectLoader();
    static ObjectLoader *mInstance;

private:
    unsigned long int mCounterOfLoadedObjects;
};

#endif // OBJECTLOADER_H
