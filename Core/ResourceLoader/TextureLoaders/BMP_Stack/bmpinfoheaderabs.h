#ifndef BMPINFOHEADERABS_H
#define BMPINFOHEADERABS_H

#include "../../../typedefs.h"
#include <istream>

class BmpInfoHeaderAbs
{
public:
    BmpInfoHeaderAbs();
    virtual ~BmpInfoHeaderAbs() = 0;

    friend std::istream & operator >> (std::istream &stream, BmpInfoHeaderAbs &obj)
    {
        obj.ReadStream(stream);
        return stream;
    }

    virtual unsigned int GetWidth(void) = 0;
    virtual unsigned int GetHeight(void) = 0;

protected:
    virtual void ReadStream(std::istream &stream) = 0;
};

#endif // BMPINFOHEADERABS_H
