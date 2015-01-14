#ifndef BMPINFOHEADERV3_H
#define BMPINFOHEADERV3_H

#include "bmpinfoheaderabs.h"

#define BMP_INFO_HEADER_V3 40

class BmpInfoHeaderV3 : public BmpInfoHeaderAbs
{
public:
    BmpInfoHeaderV3();
    virtual ~BmpInfoHeaderV3() override;

    virtual unsigned int GetWidth(void) override;
    virtual unsigned int GetHeight(void) override;

protected:
    virtual void ReadStream(std::istream &stream) override;

protected:
    INT32 mInfoHeaderSize;
    INT32 mImageWidth;
    INT32 mImageHeight;
    INT16 mPlanes; // Should be 1
    INT16 mBitPerPixel;
    INT32 mImageCompression;
    INT32 mImageSize;
    INT32 mXPixelsPerMeter;
    INT32 mYPixelsPerMeter;
    INT32 mUsed;
    INT32 mImportant;
};

#endif // BMPINFOHEADERV3_H
