#include "objectraw.h"

#include "objectloader.h"

static const char *defaultObjectName = "Unknown";

ObjectRaw::ObjectRaw() :
    mObjectFile(nullptr), mObjectName(nullptr), mObjectVertexes(nullptr),
    mObjectVertexQuantity(0),
    mObjectPosition(0.0f, 0.0f, 0.0f), mObjectRotation(0.0f, 0.0f, 0.0f)
{
    mObjectName = (char*)defaultObjectName;

    LoadObjectFromFile("Resources/Engine.3ds");
}

ObjectRaw::~ObjectRaw()
{
    if (defaultObjectName != mObjectName)
        delete[] mObjectName;
    mObjectName = nullptr;

    delete[] mObjectVertexes;
    mObjectVertexes = nullptr;
}

bool ObjectRaw::LoadObjectFromFile(const char *fileName)
{
    //TODO Loading mechanism;

    try
    {
        mObjectFile = new char [strlen(fileName) + 1];
    }
    catch(std::bad_alloc &ba)
    {
        (void)ba;
        return false;
    }

    memcpy(mObjectFile, fileName, strlen(fileName));

    ObjectLoader::Instance()->LoadObjectFile(mObjectFile, this);

    return true;
}

void ObjectRaw::SetObjectName(const char *name)
{
    if (nullptr == name)
    {
        //Memory error
        return;
    }

    try
    {
        mObjectName = new char [strlen(name) + 1];
    }
    catch(std::bad_alloc &ba)
    {
        (void)ba;
        // Handle memory error
        return;
    }

    memcpy(mObjectName, name, strlen(name));
}

const char *ObjectRaw::GetObjectName() const
{
    return mObjectName;
}

glm::vec3 *&ObjectRaw::GetObjectVertexes()
{
    return mObjectVertexes;
}

void ObjectRaw::SetObjectVertexQuantity(unsigned long quantity)
{
    if (0 != mObjectVertexQuantity)
    {
        // Remove previous data
        delete[] GetObjectVertexes();
        GetObjectVertexes() = nullptr;
        mObjectVertexQuantity = 0;
    }

    mObjectVertexQuantity = quantity;

    try
    {
        GetObjectVertexes() = new glm::vec3[mObjectVertexQuantity];
    }
    catch(std::bad_alloc &ba)
    {
        // TODO
        (void)ba;
        mObjectVertexQuantity = 0;
    }
}

const unsigned long &ObjectRaw::GetObjectVertexQuantity() const
{
    return mObjectVertexQuantity;
}

void ObjectRaw::SetObjectPosition(glm::vec3 &position)
{
    mObjectPosition = position;
}

const glm::vec3 &ObjectRaw::GetObjectPosition() const
{
    return mObjectPosition;
}

void ObjectRaw::SetObjectRotation(glm::vec3 &rotation)
{
    mObjectRotation = rotation;
}

const glm::vec3 &ObjectRaw::GetObjectRotation() const
{
    return mObjectRotation;
}

void ObjectRaw::SetObjectScale(glm::vec3 &scale)
{
    mObjectScale = scale;
}

const glm::vec3 &ObjectRaw::GetObjectScale() const
{
    return mObjectScale;
}
