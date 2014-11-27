#include "modelloader.h"
#include "Loader/loader3ds.h"

ModelLoader::ModelLoader()
{
    ;
}

ModelLoader::~ModelLoader()
{
    ;
}

bool ModelLoader::LoadModelFile(const char *filename, Object *object)
{
    if (nullptr == filename)
    {
        std::cerr << __PRETTY_FUNCTION__ << ": filename is empty" << std::endl;
        return false;
    }

    if (strstr(filename, ".3ds"))
    {
        Loader3ds loader;
        return loader.Load(filename, object);
    }

    return false;
}
