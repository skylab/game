#ifndef IMAGELOADERBMP_H
#define IMAGELOADERBMP_H

#include "imageloaderabs.h"

class ImageLoaderBMP : public ImageLoaderAbs
{    
    struct BITMAPFILEHEADER
    {
        char bm[2];
        unsigned int fileSize;
        char reserved[2][2];
        unsigned int dataOffset;
    };

    struct BITMAPINFO
    {
        unsigned int sizeOfInfo;
        unsigned int imageeWidth;
        unsigned int imageHeight;
        unsigned short planesQuantity;
        unsigned short bitsPerPixel;
        unsigned int compressionType;
        unsigned int imageSize;
        unsigned int horizontalResolution;
        unsigned int verticalResolution;
        unsigned int usedColorsQuantity;
        unsigned int importantColorsQuantity;
    };

public:
    ImageLoaderBMP(const char *filename);

    bool loadImage(void);

    virtual unsigned int &GetImageWidth(void);
    virtual unsigned int &GetImageHeight(void);

private:
    const char *mFileName;
    BITMAPFILEHEADER mHeader;
    BITMAPINFO mInfo;
};

#endif // IMAGELOADERBMP_H
