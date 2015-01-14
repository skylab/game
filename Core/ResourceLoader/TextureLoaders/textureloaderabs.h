#ifndef TEXTURELOADERABS_H
#define TEXTURELOADERABS_H

#include "../../ObjectLevels/GraphicLevel/texture.h"

class TextureLoaderAbs
{
protected:
    TextureLoaderAbs();
    virtual ~TextureLoaderAbs();

public:
   virtual bool Load(const char *filename, Texture *texture) = 0;
};

#endif // TEXTURELOADERABS_H
