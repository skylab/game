#ifndef TEXTURE_H
#define TEXTURE_H

#include "../pregraphic.h"

class Texture
{
public:
    Texture();

    bool LoadFromFile(const char *filename);

private:
    GLuint mTextureID;
};

#endif // TEXTURE_H
