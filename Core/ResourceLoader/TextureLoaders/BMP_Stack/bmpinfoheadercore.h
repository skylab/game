#ifndef BMPINFOHEADERCORE_H
#define BMPINFOHEADERCORE_H

#include "bmpinfoheaderabs.h"

#define BMP_INFO_HEADER_CORE 12

class BmpInfoHeaderCore : public BmpInfoHeaderAbs
{
public:
    BmpInfoHeaderCore();
    virtual ~BmpInfoHeaderCore() override;

    virtual unsigned int GetWidth(void) override;
    virtual unsigned int GetHeight(void) override;

protected:
    virtual void ReadStream(std::istream &stream) override;

protected:
    INT32 mInfoHeaderSize;
    INT16 mImageWidth;
    INT16 mImageHeight;
    INT16 mPlanes; // should be 1.
    INT16 mBitPerPixel;
};

#endif // BMPINFOHEADERCORE_H
