#include "objectloader3ds.h"

/*
#include <fstream>


const unsigned int CHUNK_MAIN = 0x4D4D;

const unsigned int CHUNK_NAMED_OBJECT = 0x4000;
const unsigned int CHUNK_VERTEX_COORDINATES = 0x4110;
const unsigned int CHUNK_FACES = 0x4120;
const unsigned int CHUNK_TEXTURE_COORDINATES = 0x4140;
const unsigned int CHUNK_TEXTURE_MATERIAL = 0xAFFF;
const unsigned int CHUNK_TEXTURE_MATERIAL_NAME = 0xA200;

struct Chunk_header
{
    unsigned short chunk_id;
    unsigned int chunk_len;
};

ObjectLoader3ds::ObjectLoader3ds()
{
    ;
}

bool ObjectLoader3ds::LoadObject(ObjectAbs *object, const char *objectFile)
{
    if (nullptr == object || nullptr == objectFile)
    {
        std::cerr << "ObjectLoader3ds::LoadObject.  "<< (nullptr == object? "ObjectAbs" : "fileName" ) << " is nullptr" << std::endl;
        return false;
    }

    std::fstream file(objectFile, std::ios_base::in|std::ios_base::binary);
    if (!file.is_open())
    {
        std::cerr << "ObjectLoader3ds::LoadObject. Can't open object file " << objectFile << std::endl;
        return false;
    }

    Chunk_header header;
    while (!file.eof())
    {
        file.read((char*)&header, sizeof(header));

        switch (header.chunk_id)
        {
        case CHUNK_MAIN:
            break;
        default:
            break;
        }
    }

    file.close();
    return false;
}
*/
