#include "texture.h"

Texture::Texture(const char *filename) : mImg(filename)
{
    glGenTextures(1, &mTextureID);

    glBindTexture(GL_TEXTURE_2D, mTextureID);
    glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, mImg.GetImageWidth(), mImg.GetImageHeight(), 0, GL_BGR, GL_UNSIGNED_BYTE, mImg.GetImageData());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    glBindTexture(GL_TEXTURE_2D, 0);
}
