#ifndef IMAGE_H
#define IMAGE_H

class ImageLoaderAbs;

class Image
{
public:
    Image(const char *filename);
    ~Image();

    unsigned char *GetImageData(void);
    unsigned int &GetImageWidth(void);
    unsigned int &GetImageHeight(void);

private:
    char *mFileName;

    ImageLoaderAbs *mImageLoader;
};

#endif // IMAGE_H
