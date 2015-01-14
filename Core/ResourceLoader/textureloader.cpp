#include "textureloader.h"

/// Loader section
#include "TextureLoaders/loaderjpeg.h"
#include "TextureLoaders/textureloaderbmp.h"

TextureLoader::TextureLoader()
{
}

TextureLoader::~TextureLoader()
{
}

const char *TextureLoader::GetName() const
{
    return __PRETTY_FUNCTION__;
}

bool TextureLoader::Load(const char *filename, Texture *texture)
{
    if (nullptr == filename)
    {
        std::cerr << __PRETTY_FUNCTION__ << ": filename is nullptr" << std::endl;
    }
    if (nullptr == texture)
    {
        std::cerr << __PRETTY_FUNCTION__ << ": Can't load: " << filename << " texture is nullptr" << std::endl;
    }

    if (strstr(filename, ".jpeg") || strstr(filename, ".JPG"))
    {
        LoaderJpeg loader;
        return loader.Load(filename, texture);
    }

    if (strstr(filename, ".bmp") || strstr(filename, ".BMP"))
    {
        TextureLoaderBMP loader;
        return loader.Load(filename, texture);
    }

    return false;
}
