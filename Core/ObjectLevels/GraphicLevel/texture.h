#ifndef TEXTURE_H
#define TEXTURE_H

#include "../../Infra/preinfra.h"
#include "pregraphic.h"

class Texture
{
    friend class TextureManager;
    friend class GraphicLevel;
public:
    Texture(const char *filename = nullptr);

    unsigned int &ID(void);
    const char *GetTextureFileName(void) const;

private:
    ~Texture();

private:
    char *mTextureFileName;
    unsigned int mID;
};

#endif // TEXTURE_H
