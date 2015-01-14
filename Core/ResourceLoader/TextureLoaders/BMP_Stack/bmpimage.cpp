#include "bmpimage.h"

BmpImage::BmpImage() : mData(nullptr)
{
    ;
}

BmpImage::~BmpImage()
{
    if (nullptr != mData)
    {
        delete[] mData;
    }
}

unsigned char *BmpImage::GetData()
{
    return mData;
}

unsigned int BmpImage::GetWidth() const
{
    return mInfoHeader.GetWidth();
}

unsigned int BmpImage::GetHeight() const
{
    return mInfoHeader.GetHeight();
}
