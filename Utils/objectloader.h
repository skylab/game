#ifndef OBJECTLOADER_H
#define OBJECTLOADER_H

class Object;

class ObjectLoader
{
public:
    static ObjectLoader *Instance(void);

    bool LoadObjectFile(const char *filename, Object *object);

private:
    ObjectLoader();
    static ObjectLoader *mInstance;

private:
    unsigned long int mCounterOfLoadedObjects;
};

#endif // OBJECTLOADER_H
