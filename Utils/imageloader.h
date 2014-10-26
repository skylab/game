#ifndef IMAGELOADER_H
#define IMAGELOADER_H

#include "../Common/precommon.h"

class Texture;

class ImageLoader
{
public:
    static ImageLoader *Instance(void);

    bool LoadImageFile(const char *filename, Texture *texture);

private:
    ImageLoader();
    static ImageLoader *mInstance;
};

#endif // IMAGELOADER_H
