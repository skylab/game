#ifndef BMPINFOHEADERV4_H
#define BMPINFOHEADERV4_H

#include "bmpinfoheaderv3.h"

#define BMP_INFO_HEADER_V4 108

class BmpInfoHeaderV4 : public BmpInfoHeaderV3
{
public:
    BmpInfoHeaderV4();
    virtual ~BmpInfoHeaderV4() override;

protected:
    virtual void ReadStream(std::istream &stream) override;

protected:
    INT32 mRedMask;
    INT32 mGreenMask;
    INT32 mBlueMask;
    INT32 mAlphaMask;
    INT8 mTypeOfColorSheme[36];
    INT32 mGammaRed;
    INT32 mGammaGreen;
    INT32 mGammaBlue;
};

#endif // BMPINFOHEADERV4_H
