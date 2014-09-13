#ifndef TEXTURE_H
#define TEXTURE_H

#include "../pregraphic.h"

#include "image.h"

class Texture
{
public:
    Texture(const char *filename);

private:
    Image mImg;
    GLuint mTextureID;
};

#endif // TEXTURE_H
