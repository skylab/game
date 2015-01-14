#include "bmpinfoheaderv5.h"

BmpInfoHeaderV5::BmpInfoHeaderV5()
{
    ;
}

BmpInfoHeaderV5::~BmpInfoHeaderV5()
{
    ;
}

void BmpInfoHeaderV5::ReadStream(std::istream &stream)
{
    BmpInfoHeaderV4::ReadStream(stream);

    stream.seekg(0x7A);

    stream.read((char*)&mIntent, sizeof(mIntent));
    stream.read((char*)&mProfileData, sizeof(mProfileData));
    stream.read((char*)&mProfileSize, sizeof(mProfileSize));
    stream.read((char*)&mReserved, sizeof(mReserved));
}
