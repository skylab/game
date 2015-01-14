#ifndef BMPINFOHEADERV5_H
#define BMPINFOHEADERV5_H

#include "bmpinfoheaderv4.h"

#define BMP_INFO_HEADER_V5 124

class BmpInfoHeaderV5 : public BmpInfoHeaderV4
{
public:
    BmpInfoHeaderV5();
    virtual ~BmpInfoHeaderV5() override;

protected:
    virtual void ReadStream(std::istream &stream) override;

protected:
    INT32 mIntent;
    INT32 mProfileData;
    INT32 mProfileSize;
    INT32 mReserved;
};

#endif // BMPINFOHEADERV5_H
