#ifndef LOADER3DS_H
#define LOADER3DS_H

#include "loaderabs.h"

class Loader3ds : public LoaderAbs
{
public:
    Loader3ds();
    bool LoadObjectFile(const char *filename, ObjectRaw *object) override;

private:
    size_t GetChunkPosition(std::fstream &file, UINT16 ID);

    bool IsParent(UINT16 ID);
};

#endif // LOADER3DS_H
