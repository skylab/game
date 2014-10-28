#include "loaderjpeg.h"

#include "soil/SOIL.h"

LoaderJPEG::LoaderJPEG()
{
}

bool LoaderJPEG::LoadImageFile(const char *filename, Texture *texture)
{
    if (nullptr == filename)
    {
        std::cerr << "ImageLoaderJPEG::LoadImageFile. filename is nullptr" << std::endl;
        return false;
    }
    if (nullptr == texture)
    {
        std::cerr << "ImageLoaderJPEG::LoadImageFile. texture is nullptr" << std::endl;
        return false;
    }
    unsigned int id = SOIL_load_OGL_texture(filename, SOIL_LOAD_AUTO, (unsigned int)texture, SOIL_FLAG_INVERT_Y);
    if (0 == id)
    {
        std::cerr << "Failed to load " << filename << std::endl;
        return false;
    }
    return true;
}
