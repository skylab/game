#ifndef LOADERABS_H
#define LOADERABS_H

#include "../../Main/object.h"
#include <fstream>

class LoaderAbs
{
public:
    virtual ~LoaderAbs();

    virtual bool LoadObjectFile(const char *filename, Object *object) = 0;

protected:
    LoaderAbs();
};

#endif // LOADERABS_H
