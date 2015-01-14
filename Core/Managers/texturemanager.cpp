#include "texturemanager.h"

TextureManager::TextureManager()
{
    ;
}

TextureManager::~TextureManager()
{
    while (0 != mTextureList.size())
    {
        Texture *texture = mTextureList.back();
        delete texture;
        mTextureList.remove(texture);
    }
}

const char *TextureManager::GetName() const
{
    return __PRETTY_FUNCTION__;
}

unsigned int TextureManager::LoadTexture(const char *filename)
{
    if (nullptr == filename)
    {
        std::cerr << __PRETTY_FUNCTION__ << ": filename is nullptr" << std::endl;
        return 0;
    }

    if (nullptr != GetTexture(filename))
    {
        return GetTexture(filename)->ID();
    }

    Texture *texture = nullptr;
    try
    {
        texture = new Texture(filename);
        mTextureList.push_back(texture);
    }
    catch(std::bad_alloc &ba)
    {
        std::cerr << __PRETTY_FUNCTION__ << ba.what() << " : Can't allocate texture: " << filename << std::endl;
        texture = nullptr;
        return 0;
    }

    if (nullptr == texture || 0 == texture->ID())
    {
        mTextureList.remove(texture);
        delete texture;
        texture = nullptr;
        std::cerr << __PRETTY_FUNCTION__ << " : Can't create texture: " << filename << std::endl;
        return 0;
    }

    return texture->ID();
}

Texture *TextureManager::GetTexture(const char *textureName)
{
    if (nullptr == textureName)
    {
        std::cerr << __PRETTY_FUNCTION__ << ": textureName is nullptr" << std::endl;
        return nullptr;
    }

    Texture *texture = nullptr;
    for (std::list<Texture *>::iterator i = mTextureList.begin(); i != mTextureList.end(); ++i)
    {
        Texture *txt = *i;
        if (!strcmp(txt->GetTextureFileName(), textureName))
        {
            return *i;
        }
    }

    return texture;
}

Texture *TextureManager::GetTexture(unsigned int id)
{
    Texture *texture = nullptr;
    for (std::list<Texture *>::iterator itr = mTextureList.begin(); itr != mTextureList.end(); ++itr)
    {
        Texture *t = *itr;
        if (id == t->ID())
        {
            texture = t;
            break;
        }
    }

    return texture;
}
