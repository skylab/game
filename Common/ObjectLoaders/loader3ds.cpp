#include "loader3ds.h"

const UINT16 CHUNK_MAIN(0x4D4D); // main chunk
const UINT16 CHUNK_OBJMESH(0x3D3D); // all objects
const UINT16 CHUNK_OBJECTBLOCK(0x4000); // object
const UINT16 CHUNK_TRIMESH(0x4100); // object data start
const UINT16 CHUNK_VERTLIST(0x4110); // object vertexes

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

    if (!GetChunkPosition(file, CHUNK_OBJMESH))
        return false;

    GetChunkPosition(file, CHUNK_VERTLIST);

    UINT16 chunkSize = 0;
    file.read((char*)&chunkSize, sizeof(chunkSize));

    UINT16 vertexQuantity = 0;
    file.read((char*)&vertexQuantity, sizeof(vertexQuantity));

    object->SetObjectVertexQuantity(vertexQuantity);

    for(UINT16 i = 0; i < vertexQuantity; ++i)
    {
        float x, y, z;
        file.read((char*)&x, sizeof(x));
        file.read((char*)&z, sizeof(z));
        file.read((char*)&y, sizeof(y));
        glm::vec3 vec(x, y, z);
        object->GetObjectVertexes()[i] = vec;
    }

    glm::vec3 vec;
    std::cerr << vertexQuantity << sizeof(vec.x) << std::endl;

    file.close();
    return false;
}

size_t Loader3ds::GetChunkPosition(std::fstream &file, UINT16 ID)
{
    UINT16 readId = 0;
    UINT32 length = 0;

    UINT32 skip = 0;

    while (!file.eof() && ID != readId)
    {
        if (0 != readId && !IsParent(readId))
        {
            file.seekg(file.tellg() - sizeof(readId) - sizeof(length) - skip);
            skip = 0;
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
                ++skip;
            }while ('\0' != ch && !file.eof());
        }
    }

    if (CHUNK_OBJECTBLOCK != ID && 0 != skip)
    {
        skip = 0;
    }

    file.seekg(file.tellg() - sizeof(readId) - sizeof(length) - skip);

    if (ID == readId)
        return file.tellg();
    else
        return 0;
}

bool Loader3ds::IsParent(UINT16 ID)
{
    switch(ID)
    {
    // What blocks we need to enter.
    case CHUNK_MAIN:
    case CHUNK_OBJMESH:
    case CHUNK_OBJECTBLOCK:
    case CHUNK_TRIMESH:
        return true;
    default:
        return false;
    }
}