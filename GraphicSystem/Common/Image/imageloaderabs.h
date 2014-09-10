#ifndef IMAGELOADERABS_H
#define IMAGELOADERABS_H

class ImageLoaderAbs
{
protected:
    ImageLoaderAbs();

public:
    virtual ~ImageLoaderAbs();
    virtual bool loadImage(void) = 0;

    virtual unsigned char *GetImageData(void);
    virtual unsigned int &GetImageWidth(void) = 0;
    virtual unsigned int &GetImageHeight(void) = 0;

protected:
    unsigned char *mData;
};

#endif // IMAGELOADERABS_H
