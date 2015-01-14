#ifndef BMPINFO_H
#define BMPINFO_H

#include "../../../Infra/preinfra.h"
#include "bmpinfoheaderabs.h"

class BmpInfo
{
    friend class BmpImage;
public:
    BmpInfo();
    ~BmpInfo();

    friend std::istream & operator >> (std::istream &stream, BmpInfo &obj)
    {
        stream.seekg(0x0E);

        INT32 infoHeadeSize = 0;
        stream.read((char*)&(infoHeadeSize), sizeof(infoHeadeSize));

        // Chose version of info header by size.
        obj.AllocateInfoHeader(infoHeadeSize);

        if (nullptr != obj.mInfoHeader)
            stream >> *(obj.mInfoHeader);

        return stream;
    }

    unsigned int GetWidth(void) const;
    unsigned int GetHeight(void) const;

private:
    void AllocateInfoHeader(INT32 size);

private:
    BmpInfoHeaderAbs *mInfoHeader;
};

#endif // BMPINFO_H
