#include "bmpinfo.h"

#include "../../../Infra/preinfra.h"

#include "bmpinfoheadercore.h"
#include "bmpinfoheaderv3.h"
#include "bmpinfoheaderv4.h"
#include "bmpinfoheaderv5.h"

BmpInfo::BmpInfo() : mInfoHeader(nullptr)
{
    ;
}

BmpInfo::~BmpInfo()
{
    if (nullptr != mInfoHeader)
    {
        delete mInfoHeader;
        mInfoHeader = nullptr;
    }
}

unsigned int BmpInfo::GetWidth() const
{
    if (nullptr != mInfoHeader)
    {
        return mInfoHeader->GetWidth();
    }
    else
    {
        return 0;
    }
}

unsigned int BmpInfo::GetHeight() const
{
    if (nullptr != mInfoHeader)
    {
        return mInfoHeader->GetHeight();
    }
    else
    {
        return 0;
    }
}

void BmpInfo::AllocateInfoHeader(INT32 size)
{
    try
    {
        switch(size)
        {
        case BMP_INFO_HEADER_CORE:
            mInfoHeader = new BmpInfoHeaderCore;
            break;
        case BMP_INFO_HEADER_V3:
            mInfoHeader = new BmpInfoHeaderV3;
            break;
        case BMP_INFO_HEADER_V4:
            mInfoHeader = new BmpInfoHeaderV4;
            break;
        case BMP_INFO_HEADER_V5:
            mInfoHeader = new BmpInfoHeaderV5;
            break;
        default:
            std::cerr << __PRETTY_FUNCTION__ << ": Unknown InfoHeader type with size: " << size << std::endl;
            break;
        }
    }
    catch(std::bad_alloc &ba)
    {
        std::cerr << __PRETTY_FUNCTION__ << " " << ba.what() << ": Can't allocate InfoHeader with size: " << size << std::endl;
        mInfoHeader = nullptr;
    }
}
