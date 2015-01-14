#include "texture.h"
#include "../../ResourceLoader/textureloader.h"

Texture::Texture(const char *filename) : mTextureFileName(nullptr), mID(0)
{
    if (nullptr != filename)
    {
        try
        {
            mTextureFileName = new char[strlen(filename)+1];
            memcpy(mTextureFileName, filename, strlen(filename));
            mTextureFileName[strlen(filename)] = '\0';
        }
        catch(std::bad_alloc &ba)
        {
            std::cerr << __PRETTY_FUNCTION__ << ba.what() << ": Can't allocate texture name" << std::endl;
            mTextureFileName = nullptr;
            return;
        }
        if (TextureLoader::Instance()->Load(mTextureFileName, this))
        {
            // DEBUG print
            //std::cerr << mTextureFileName << " ID: " << mID << std::endl;
        }
        else
        {
            std::cerr << __PRETTY_FUNCTION__ << ": Can't load texture: " << filename << std::endl;
            delete[] mTextureFileName;
            mTextureFileName = nullptr;
            return;
        }
    }
}

unsigned int &Texture::ID()
{
    return mID;
}

const char *Texture::GetTextureFileName() const
{
    return mTextureFileName;
}

Texture::~Texture()
{
    if (nullptr != mTextureFileName)
        delete[] mTextureFileName;
    if (0 != mID)
        glDeleteTextures(1, &mID);
}
