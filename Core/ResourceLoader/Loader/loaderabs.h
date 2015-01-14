#ifndef LOADERABS_H
#define LOADERABS_H

#include "../../ObjectLevels/object.h"
#include "../../Managers/texturemanager.h"

class LoaderAbs
{
protected:
    LoaderAbs();
    virtual ~LoaderAbs();

public:
    virtual bool Load(const char *filename, Object *object) = 0;
};

#endif // LOADERABS_H
