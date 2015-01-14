#ifndef BMPHEADER_H
#define BMPHEADER_H

#include "../../../typedefs.h"
#include "../../../Infra/preinfra.h"

class BmpHeader
{
    friend class BmpImage;
public:
    BmpHeader();
    ~BmpHeader();

    friend std::istream & operator >> (std::istream &stream, BmpHeader &obj)
    {
        stream.seekg(0x00);
        stream.read(obj.BM, 2);
        stream.seekg(0x02);
        stream.read((char*)&obj.Size, 4);
        stream.seekg(0x06);
        stream.read((char*)&obj.Reserved1, 1);
        stream.seekg(0x08);
        stream.read((char*)&obj.Reserved2, 1);
        stream.seekg(0x0A);
        stream.read((char*)&obj.Offset, 4);

        return stream;
    }

    INT32 GetSize(void) const;
    INT32 GetOffset(void) const;

private:
    char BM[2];
    INT32 Size;
    char Reserved1;
    char Reserved2;
    INT32 Offset;
};

#endif // BMPHEADER_H
