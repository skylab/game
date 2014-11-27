#ifndef LOADER3DS_H
#define LOADER3DS_H

#include "loaderabs.h"

class Loader3ds : public LoaderAbs
{
public:
    Loader3ds();
    virtual ~Loader3ds() override;

    virtual bool Load(const char *filename, Object *object) override;
};

#endif // LOADER3DS_H
