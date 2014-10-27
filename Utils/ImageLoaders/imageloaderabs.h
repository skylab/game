#ifndef IMAGELOADERABS_H
#define IMAGELOADERABS_H

#include "../../GraphicSystem/Testure/texture.h"

class ImageLoaderAbs
{
protected:
    ImageLoaderAbs();
    virtual ~ImageLoaderAbs();

    virtual bool LoadImageFile(const char *filename, Texture *texture) = 0;
};

#endif // IMAGELOADERABS_H
