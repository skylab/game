#include "imageloaderabs.h"

ImageLoaderAbs::ImageLoaderAbs()
{
    ;
}

ImageLoaderAbs::~ImageLoaderAbs()
{
    ;
}

bool ImageLoaderAbs::LoadImageFile(const char *filename, Texture *texture)
{
    // To disable warnings
    (void)filename;
    (void)texture;

    std::cerr << "ImageLoaderAbs. Call pure virtual function" << std::endl;
    return false;
}
