#ifndef TEXTURELOADER_H
#define TEXTURELOADER_H

#include "../Infra/singleton.h"
#include "../ObjectLevels/GraphicLevel/texture.h"

class TextureLoader : public Singleton<TextureLoader>
{
public:
    TextureLoader();
    virtual ~TextureLoader() override;

    virtual const char *GetName(void) const override;

    bool Load(const char *filename, Texture *texture);
};

#endif // TEXTURELOADER_H
