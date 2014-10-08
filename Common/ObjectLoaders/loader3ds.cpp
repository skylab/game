#include "loader3ds.h"

const UINT16 CHUNK_MAIN(0x4D4D); // main chunk
const UINT16 CHUNK_OBJMESH(0x3D3D); // all objects
const UINT16 CHUNK_OBJECTBLOCK(0x4000); // object
const UINT16 CHUNK_TRIMESH(0x4100); // object data start
const UINT16 CHUNK_VERTLIST(0x4110); // object vertexes (one point - only once)
const UINT16 CHUNK_TRI_FACELIST(0x4120); // Indexes of vertexes to object

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

    UINT16 chunkId = 0;
    UINT32 chunkSize = 0;
    file.read((char*)&chunkId, sizeof(chunkId));
    file.read((char*)&chunkSize, sizeof(chunkSize));

    UINT16 vertexQuantity = 0;
    file.read((char*)&vertexQuantity, sizeof(vertexQuantity));

    glm::vec3 *vertexArray = nullptr;
    try
    {
        vertexArray = new glm::vec3[vertexQuantity];
    }
    catch(std::bad_alloc &ba)
    {
        (void)ba;
        return false;
    }

    for(UINT16 i = 0; i < vertexQuantity; ++i)
    {
        float x, y, z;
        file.read((char*)&x, sizeof(x));
        file.read((char*)&z, sizeof(z));
        file.read((char*)&y, sizeof(y));
        glm::vec3 vec(x, y, z);
        vertexArray[i] = vec;
    }

    GetChunkPosition(file, CHUNK_TRI_FACELIST);
    file.read((char*)&chunkId, sizeof(chunkId));
    file.read((char*)&chunkSize, sizeof(chunkSize));

    UINT16 triangleQuantity = 0;
    file.read((char*)&triangleQuantity, sizeof(triangleQuantity));

    object->SetObjectVertexQuantity(triangleQuantity*3);

    UINT16 first = 0;
    UINT16 second = 0;
    UINT16 third = 0;
    UINT16 flag = 0;

    UINT16 vertexCounter = 0;
    for(UINT16 i = 0; i < triangleQuantity; ++i)
    {
        file.read((char*)&first, sizeof(first));
        file.read((char*)&second, sizeof(second));
        file.read((char*)&third, sizeof(third));
        file.read((char*)&flag, sizeof(flag));

        object->GetObjectVertexes()[vertexCounter++] = vertexArray[first];
        object->GetObjectVertexes()[vertexCounter++] = vertexArray[second];
        object->GetObjectVertexes()[vertexCounter++] = vertexArray[third];
    }

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
