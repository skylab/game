#include "imageloaderbmp.h"

#include <iostream>
#include <fstream>
#include <cstring>



ImageLoaderBMP::ImageLoaderBMP(const char *filename) : ImageLoaderAbs(), mFileName(filename)
{
    memset(&mHeader, 0, sizeof(mHeader));
    memset(&mInfo, 0, sizeof(mInfo));
    loadImage();
}

bool ImageLoaderBMP::loadImage(void)
{
    std::fstream file(mFileName, std::ios_base::in|std::ios_base::binary);

    if(file.is_open())
    {
        //Read Header
        file.read((char*)&mHeader, sizeof(mHeader));
        if (file.gcount() != sizeof(mHeader))
        {
            std::cerr << "ImageLoaderBMP::loadImage. Can't read mHeader" << std::endl;
            return false;
        }
        if (mHeader.bm[0] != 'B' && mHeader.bm[1] != 'M')
        {
            std::cerr << "ImageLoaderBMP::loadImage. Incorrect BMP file" << mFileName << std::endl;
            return false;
        }

        //ReadInfo
        file.read((char*)&mInfo, sizeof(mInfo));
        if (file.gcount() != sizeof(mInfo))
        {
            std::cerr << "ImageLoaderBMP::loadImage. Can't read mInfo" << std::endl;
            return false;
        }

        //Fix imageSize
        if (0 == mInfo.imageSize)
            mInfo.imageSize = mInfo.imageeWidth * mInfo.imageHeight * mInfo.bitsPerPixel;
        //Fix dataPos
        if (0 == mHeader.dataOffset)
            mHeader.dataOffset = sizeof(BITMAPFILEHEADER);

        //Allocate memory to image data.
        try
        {
            mData = new unsigned char[mInfo.imageSize];
        }
        catch(std::bad_alloc &ba)
        {
            (void)ba;
            std::cerr << "ImageLoaderBMP::loadImage. Can't alloc mData" << std::endl;
            return false;
        }

        //Read data of image
        file.read((char*)mData, mInfo.imageSize);
        if (file.gcount() != mInfo.imageSize)
        {
            std::cerr << "ImageLoaderBMP::loadImage. Can't read image fully" << std::endl;
            return false;
        }

        file.close();
    }
    else
    {
        std::cerr << "ImageLoaderBMP::loadImage. Can't open file " << mFileName << std::endl;
    }
    return false;
}

unsigned int &ImageLoaderBMP::GetImageWidth()
{
    return mInfo.imageeWidth;
}

unsigned int &ImageLoaderBMP::GetImageHeight()
{
    return mInfo.imageHeight;
}
