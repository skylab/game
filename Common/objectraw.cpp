#include "objectraw.h"

#include "objectloader.h"

static const char *defaultObjectName = "Unknown";

ObjectRaw::ObjectRaw() :
    mObjectFile(nullptr), mObjectName(nullptr), mObjectVertexes(nullptr),
    mObjectVertexQuantity(0),
    mObjectPosition(0.0f, 0.0f, 0.0f), mObjectRotation(0.0f, 0.0f, 0.0f, 0.0f), mObjectScale(0.0f, 0.0f, 0.0f), mbCanHaveObjectList(true)
{
    mObjectName = (char*)defaultObjectName;

    // Default object scale is 1.0
    SetObjectScale(1.0f, 1.0f, 1.0f);
}

ObjectRaw::~ObjectRaw()
{
    // TODO destructor
    if (defaultObjectName != mObjectName)
        delete[] mObjectName;
    mObjectName = nullptr;

    delete[] mObjectVertexes;
    mObjectVertexes = nullptr;

    ClearObjectList();
}

bool ObjectRaw::LoadObjectFromFile(const char *fileName)
{
    try
    {
        mObjectFile = new char [strlen(fileName) + 1];
    }
    catch(std::bad_alloc &ba)
    {
        // TODO bad alloc
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
        return;
    }

    try
    {
        mObjectName = new char [strlen(name) + 1];
    }
    catch(std::bad_alloc &ba)
    {
        // TODO bad alloc
        (void)ba;
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
        delete[] mObjectVertexes;
        mObjectVertexes = nullptr;
        mObjectVertexQuantity = 0;
    }

    mObjectVertexQuantity = quantity;

    try
    {
        mObjectVertexes = new glm::vec3[mObjectVertexQuantity];
    }
    catch(std::bad_alloc &ba)
    {
        // TODO bad alloc
        (void)ba;
        mObjectVertexQuantity = 0;
    }
}

const unsigned long &ObjectRaw::GetObjectVertexQuantity() const
{
    return mObjectVertexQuantity;
}

void ObjectRaw::SetObjectPosition(float x, float y, float z)
{
    mObjectPosition = glm::vec3(x, y, z);
}

const glm::vec3 &ObjectRaw::GetObjectPosition() const
{
    return mObjectPosition;
}

void ObjectRaw::SetObjectRotation(float x, float y, float z)
{
    mObjectRotation = glm::vec4(x, y, z, 0.0f);
}

void ObjectRaw::SetObjectRotation(glm::vec4 &rotation)
{
    mObjectRotation = rotation;
}

const glm::vec4 &ObjectRaw::GetObjectRotation()
{
    return mObjectRotation;
}

void ObjectRaw::SetObjectScale(float x, float y, float z)
{
    mObjectScale = glm::vec3(x, y, z);
}

const glm::vec3 &ObjectRaw::GetObjectScale() const
{
    return mObjectScale;
}

void ObjectRaw::AddObject(ObjectRaw *object, glm::vec3 position)
{
    object->SetObjectPosition(position.x, position.y, position.z);
    if (GetCanHaveObjectList())
        mObjectList.push_back(object);
    else
        std::cerr << "Object can't have objectlist" << std::endl;
}

void ObjectRaw::RemoveObject(ObjectRaw *object)
{
    if (0 != mObjectList.size())
        mObjectList.remove(object);

}

void ObjectRaw::ClearObjectList()
{
    mObjectList.clear();
}

const std::list<ObjectRaw *> &ObjectRaw::GetObjectList() const
{
    return mObjectList;
}

size_t ObjectRaw::GetObjectQuantity() const
{
    return mObjectList.size();
}

void ObjectRaw::SetCanHaveObjectList(bool val)
{
    mbCanHaveObjectList = val;
}

bool ObjectRaw::GetCanHaveObjectList()
{
    return mbCanHaveObjectList;
}
