#include "texture.h"

Texture::Texture() : mTextureID(0)
{
    try
    {
        glGenTextures(1, &mTextureID);
    }
    catch(...)
    {
        std::cerr << "Can't create texture" << std::endl;
        return;
    }
}

bool Texture::LoadFromFile(const char *filename)
{
    glBindTexture(GL_TEXTURE_2D, mTextureID);

    //glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    /*
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glGenerateMipmap(GL_TEXTURE_2D);
    */

    return true;
}

Texture::operator unsigned int()
{
    return mTextureID;
}
