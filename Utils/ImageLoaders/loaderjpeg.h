#ifndef LOADERJPEG_H
#define LOADERJPEG_H

#include "imageloaderabs.h"

class LoaderJPEG : public ImageLoaderAbs
{
public:
    LoaderJPEG();

    bool LoadImageFile(const char *filename, Texture *texture) override;
};

#endif // IMAGELOADERJPEG_H
