#ifndef LOADERABS_H
#define LOADERABS_H

#include "../../Common/objectraw.h"
#include <fstream>

class LoaderAbs
{
public:
    virtual ~LoaderAbs();

    virtual bool LoadObjectFile(const char *filename, ObjectRaw *object) = 0;

protected:
    LoaderAbs();
};

#endif // LOADERABS_H
