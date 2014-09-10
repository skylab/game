#include "image.h"

#include <iostream>
#include <new>
#include <string>
#include <cstring>

//LOADER SECTION
#include "imageloaderabs.h"
#include "imageloaderbmp.h"

Image::Image(const char *filename) : mFileName(nullptr), mImageLoader(nullptr)
{
    if (nullptr == filename)
    {
        std::cerr << "Image::Image. filename is nullptr" << std::endl;
        return;
    }

    try
    {
        mFileName = new char[ std::char_traits<char>::length(filename) ];
        std::char_traits<char>::copy(mFileName, filename, std::char_traits<char>::length(filename));
    }
    catch(std::bad_alloc &ba)
    {
        (void)ba;
        std::cerr << "Can't alloc filename" << std::endl;
        return;
    }

    if (strstr(mFileName, ".bmp"))
    {
        try
        {
            mImageLoader = new ImageLoaderBMP(mFileName);
        }
        catch(std::bad_alloc &ba)
        {
            (void)ba;
            std::cerr << "Image::Image. Can't allocate ImageLoaderBMP" << std::endl;
        }
    }
}

Image::~Image()
{
    delete mFileName;
    mFileName = nullptr;
    delete mImageLoader;
    mImageLoader = nullptr;
}

unsigned char *Image::GetImageData()
{
    return mImageLoader->GetImageData();
}

unsigned int &Image::GetImageWidth()
{
    return mImageLoader->GetImageWidth();
}

unsigned int &Image::GetImageHeight()
{
    return mImageLoader->GetImageHeight();
}
