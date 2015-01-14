#include "bmpinfoheaderv3.h"

BmpInfoHeaderV3::BmpInfoHeaderV3()
{
    ;
}

BmpInfoHeaderV3::~BmpInfoHeaderV3()
{
    ;
}

unsigned int BmpInfoHeaderV3::GetWidth()
{
    return mImageWidth;
}

unsigned int BmpInfoHeaderV3::GetHeight()
{
    return mImageHeight;
}

void BmpInfoHeaderV3::ReadStream(std::istream &stream)
{
    stream.seekg(0x0E);
    stream.read((char*)&mInfoHeaderSize, sizeof(mInfoHeaderSize));
    stream.seekg(0x12);
    stream.read((char*)&mImageWidth, sizeof(mImageWidth));
    stream.seekg(0x16);
    stream.read((char*)&mImageHeight, sizeof(mImageHeight));
    stream.seekg(0x1A);
    stream.read((char*)&mPlanes, sizeof(mPlanes));
    stream.seekg(0x1C);
    stream.read((char*)&mBitPerPixel, sizeof(mBitPerPixel));
    stream.seekg(0x1E);
    stream.read((char*)&mImageCompression, sizeof(mImageCompression));
    stream.seekg(0x22);
    stream.read((char*)&mImageSize, sizeof(mImageSize));
    stream.seekg(0x26);
    stream.read((char*)&mXPixelsPerMeter, sizeof(mXPixelsPerMeter));
    stream.seekg(0x2A);
    stream.read((char*)&mYPixelsPerMeter, sizeof(mYPixelsPerMeter));
    stream.seekg(0x2E);
    stream.read((char*)&mUsed, sizeof(mUsed));
    stream.seekg(0x32);
    stream.read((char*)&mImportant, sizeof(mImportant));
}
