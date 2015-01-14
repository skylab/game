#include "loaderjpeg.h"
#include "../../Libs/soil/SOIL.h"

LoaderJpeg::LoaderJpeg()
{
    ;
}

LoaderJpeg::~LoaderJpeg()
{
    ;
}

bool LoaderJpeg::Load(const char *filename, Texture *texture)
{
    if (nullptr == filename)
    {
        std::cerr << __PRETTY_FUNCTION__ << " filename is nullptr" << std::endl;
        return false;
    }
    if (nullptr == texture)
    {
        std::cerr << __PRETTY_FUNCTION__ << ": Can't load texture: " << filename << " texture is nullptr" << std::endl;
        return false;
    }

    unsigned int id = SOIL_load_OGL_texture(filename, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
    if (0 == id)
    {
        std::cerr << __PRETTY_FUNCTION__ << ":" << SOIL_last_result() << " : Can't load: " << filename << std::endl;
        return false;
    }
    else
    {
        texture->ID() = id;
        return true;
    }
    return false;
}
