#include "loader3ds.h"

const UINT16 CHUNK_MAIN(0x4D4D); // main chunk
const UINT16 CHUNK_OBJMESH(0x3D3D); // all objects
const UINT16 CHUNK_OBJECTBLOCK(0x4000); // object
const UINT16 CHUNK_TRIMESH(0x4100); // object data start
const UINT16 CHUNK_VERTLIST(0x4110); // object vertexes

const UINT16 CHUNK_EDIT_MATRIAL(0xAFFF);
const UINT16 CHUNK_EDIT_VIEW_P1(0x7012);
const UINT16 CHUNK_EDIT_VIEW_P2(0x7011);

Loader3ds::Loader3ds()
{
}

bool Loader3ds::LoadObjectFile(const char *filename, ObjectRaw *object)
{
    if (nullptr == filename || nullptr == object)
    {
        // TODO
        return false;
    }

    std::fstream file(filename, std::ios_base::in|std::ios_base::binary);
    if (!file.is_open())
    {
        // TODO
        return false;
    }

    size_t position = 0;

    position = GetChunkPosition(file, CHUNK_MAIN);
    position = GetChunkPosition(file, CHUNK_OBJMESH);
    position = GetChunkPosition(file, CHUNK_OBJECTBLOCK);
    position = GetChunkPosition(file, CHUNK_TRIMESH);
    position = GetChunkPosition(file, CHUNK_VERTLIST);

    std::cerr << position << std::endl;

    file.close();
    return false;
}

size_t Loader3ds::GetChunkPosition(std::fstream &file, UINT16 ID)
{
    UINT16 readId = 0;
    UINT32 length = 0;

    while (!file.eof() && ID != readId)
    {
        if (0 != readId && !IsParent(readId))
        {
            file.seekg(file.tellg() - sizeof(readId) - sizeof(length));
            file.ignore(length);
        }
        file.read((char*)&readId, sizeof(readId));
        file.read((char*)&length, sizeof(length));

        // Skip object name
        if (CHUNK_OBJECTBLOCK == readId)
        {
            char ch;
            do
            {
                file.read(&ch, 1);
            }while ('0' != ch && !file.eof());
        }

        size_t a = file.tellg();
        std::cerr << a << std::endl;
    }

    size_t a = file.tellg();
    std::cerr << a << std::endl;

    file.seekg(file.tellg() - sizeof(readId) - sizeof(length));

    if (ID == readId)
    {
        std::cerr << std::hex << readId << std::endl;
        return file.tellg();
    }
    else
        return 0;
}

bool Loader3ds::IsParent(UINT16 ID)
{
    switch(ID)
    {
    case CHUNK_MAIN:
    case CHUNK_OBJMESH:
    case CHUNK_OBJECTBLOCK:
    case CHUNK_TRIMESH:

    case CHUNK_EDIT_MATRIAL:
    case CHUNK_EDIT_VIEW_P1:
    case CHUNK_EDIT_VIEW_P2:
        return true;
    default:
        return false;
    }
}
