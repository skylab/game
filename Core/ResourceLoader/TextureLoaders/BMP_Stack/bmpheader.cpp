#include "bmpheader.h"

BmpHeader::BmpHeader()
{
    BM[0] = 0;
    BM[1] = 0;
    Size = 0;
    Reserved1 = 0;
    Reserved2 = 0;
    Offset = 0;
}

BmpHeader::~BmpHeader()
{
    BM[0] = 0;
    BM[1] = 0;
    Size = 0;
    Reserved1 = 0;
    Reserved2 = 0;
    Offset = 0;
}

INT32 BmpHeader::GetSize() const
{
    return Size;
}

INT32 BmpHeader::GetOffset() const
{
    return Offset;
}
