#include "bmpinfoheaderv4.h"

BmpInfoHeaderV4::BmpInfoHeaderV4()
{
    ;
}

BmpInfoHeaderV4::~BmpInfoHeaderV4()
{
    ;
}

void BmpInfoHeaderV4::ReadStream(std::istream &stream)
{
    BmpInfoHeaderV3::ReadStream(stream);

    stream.seekg(0x36);

    stream.read((char*)&mRedMask, sizeof(mRedMask));
    stream.read((char*)&mGreenMask, sizeof(mGreenMask));
    stream.read((char*)&mBlueMask, sizeof(mBlueMask));
    stream.read((char*)&mAlphaMask, sizeof(mAlphaMask));
    stream.read((char*)&mTypeOfColorSheme, 36);
    stream.read((char*)&mGammaRed, sizeof(mGammaRed));
    stream.read((char*)&mGammaGreen, sizeof(mGammaGreen));
    stream.read((char*)&mGammaBlue, sizeof(mGammaBlue));
}
