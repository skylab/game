#include "imageloader.h"

#include "../GraphicSystem/Testure/texture.h"

///LoaderList
#include "ImageLoaders/loaderjpeg.h"

bool ImageLoader::LoadImageFile(const char *filename, Texture *texture)
{
    if (nullptr == filename)
    {
        std::cerr << "LoadImageFile. Filename is nullptr" << std::endl;
        return false;
    }
    if (nullptr == texture)
    {
        std::cerr << "ImageLoader::LoadImageFile. Texture is nullptr" << std::endl;
        return false;
    }

    if (strstr(filename, ".jpeg") || strstr(filename, ".jpg"))
    {
        LoaderJPEG loader;
        return loader.LoadImageFile(filename, texture);
    }

    return false;
}

ImageLoader::ImageLoader()
{
    ;
}
