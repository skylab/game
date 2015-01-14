#ifndef TEXTURELOADERBMP_H
#define TEXTURELOADERBMP_H

#include "textureloaderabs.h"

#include "BMP_Stack/bmpimage.h"

class TextureLoaderBMP : public TextureLoaderAbs
{
public:
    TextureLoaderBMP();
    virtual ~TextureLoaderBMP();

public:
   virtual bool Load(const char *filename, Texture *texture);

private:
    BmpImage mImage;
};

#endif // TEXTURELOADERBMP_H
