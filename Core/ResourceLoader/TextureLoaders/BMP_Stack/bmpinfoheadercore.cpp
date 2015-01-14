#include "bmpinfoheadercore.h"

BmpInfoHeaderCore::BmpInfoHeaderCore()
{
    ;
}

BmpInfoHeaderCore::~BmpInfoHeaderCore()
{
    ;
}

unsigned int BmpInfoHeaderCore::GetWidth()
{
    return mImageWidth;
}

unsigned int BmpInfoHeaderCore::GetHeight()
{
    return mImageHeight;
}

void BmpInfoHeaderCore::ReadStream(std::istream &stream)
{
    stream.seekg(0x0E);
    stream.read((char*)&(mInfoHeaderSize), sizeof(mInfoHeaderSize));
    stream.seekg(0x12);
    stream.read((char*)&(mImageWidth), sizeof(mImageWidth));
    stream.seekg(0x14);
    stream.read((char*)&(mImageHeight), sizeof(mImageHeight));
    stream.seekg(0x16);
    stream.read((char*)&(mPlanes), sizeof(mPlanes));
    stream.seekg(0x18);
    stream.read((char*)&(mBitPerPixel), sizeof(mBitPerPixel));
}
