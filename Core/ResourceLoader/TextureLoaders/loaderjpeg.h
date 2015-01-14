#ifndef LOADERJPEG_H
#define LOADERJPEG_H

#include "textureloaderabs.h"

class LoaderJpeg : public TextureLoaderAbs
{
public:
    LoaderJpeg();
    virtual ~LoaderJpeg() override;

    virtual bool Load(const char *filename, Texture *texture) override;
};

#endif // LOADERJPEG_H
