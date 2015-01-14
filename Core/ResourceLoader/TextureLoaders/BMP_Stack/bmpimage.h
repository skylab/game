#ifndef BMPIMAGE_H
#define BMPIMAGE_H

#include "bmpheader.h"
#include "bmpinfo.h"
#include "../../../Infra/preinfra.h"

class BmpImage
{
public:
    BmpImage();
    virtual ~BmpImage();

    friend std::istream & operator >> (std::istream &stream, BmpImage &img)
    {
        stream >> img.mHeader;
        stream >> img.mInfoHeader;

        try
        {
            img.mData = new UINT8[img.mHeader.GetSize()];
        }
        catch(std::bad_alloc &ba)
        {
            std::cerr << __PRETTY_FUNCTION__ << ":" << ba.what() << "Can't allocate data memmory" << std::endl;
            img.mData = nullptr;
        }

        if (nullptr != img.mData)
        {
            stream.seekg(img.mHeader.GetOffset());
            stream.read((char*)img.mData, img.mHeader.GetSize());
        }

        return stream;
    }

    unsigned char *GetData(void);
    unsigned int GetWidth(void) const;
    unsigned int GetHeight(void) const;

private:
    BmpHeader mHeader;
    BmpInfo mInfoHeader;
    UINT8 *mData;
};

#endif // BMPIMAGE_H
