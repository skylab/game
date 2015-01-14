#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include "../Infra/singleton.h"
#include "../ObjectLevels/GraphicLevel/texture.h"

class TextureManager : public Singleton<TextureManager>
{
public:
    TextureManager();
    virtual ~TextureManager() override;

    const char *GetName(void) const override;

    unsigned int LoadTexture(const char *filename);

    Texture *GetTexture(const char *textureName);
    Texture *GetTexture(unsigned int id);

private:
    std::list<Texture *> mTextureList;
};

#endif // TEXTUREMANAGER_H
