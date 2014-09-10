#include "imageloaderabs.h"

ImageLoaderAbs::ImageLoaderAbs() : mData(nullptr)
{
    ;
}

ImageLoaderAbs::~ImageLoaderAbs()
{
    delete mData;
    mData = nullptr;
}

unsigned char *ImageLoaderAbs::GetImageData()
{
    return mData;
}
