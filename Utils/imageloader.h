#ifndef IMAGELOADER_H
#define IMAGELOADER_H

#include "../Common/precommon.h"
#include "../Infra/singleton.h"

class Texture;

class ImageLoader : public Singleton<ImageLoader>
{
public:
    ImageLoader();
    bool LoadImageFile(const char *filename, Texture *texture);
};

#endif // IMAGELOADER_H
