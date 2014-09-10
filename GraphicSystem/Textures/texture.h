#ifndef TEXTURE_H
#define TEXTURE_H

#include "../pregraphic.h"

#include "../Common/Image/image.h"

class Texture
{
public:
    Texture(const char *filename);

private:
    Image mImg;
};

#endif // TEXTURE_H
