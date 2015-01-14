#include "textureloaderbmp.h"

TextureLoaderBMP::TextureLoaderBMP()
{
    ;
}

TextureLoaderBMP::~TextureLoaderBMP()
{
    ;
}

bool TextureLoaderBMP::Load(const char *filename, Texture *texture)
{
    if (nullptr == filename)
    {
        std::cerr << __PRETTY_FUNCTION__ << ": filename is nullptr" << std::endl;
        return false;
    }
    if (nullptr == texture)
    {
        std::cerr << __PRETTY_FUNCTION__ << ": texture is nullptr" << std::endl;
        return false;
    }
    if (!strstr(filename, ".bmp") && !strstr(filename, ".BMP"))
    {
        std::cerr << __PRETTY_FUNCTION__ << ": filename hasn't bmp extension." << std::endl;
        return false;
    }

    std::fstream file(filename, std::ios_base::in | std::ios_base::binary);
    if (file.is_open())
    {
        file >> mImage;
        file.close();

        glGenTextures(1, &(texture->ID()));
        glBindTexture(GL_TEXTURE_2D, texture->ID());

        glTexImage2D(GL_TEXTURE_2D,
                     0,
                     GL_RGB,
                     mImage.GetWidth(),
                     mImage.GetHeight(),
                     0,
                     GL_BGR,
                     GL_UNSIGNED_BYTE,
                     mImage.GetData()
                     );

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

        return true;
    }

    return false;
}
