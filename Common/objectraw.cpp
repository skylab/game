#include "objectraw.h"

#include "objectloader.h"

ObjectRaw::ObjectRaw() :
    mObjectVertexes(nullptr),
    mObjectVertexQuantity(0),
    mObjectPosition(0.0f, 0.0f, 0.0f),
    mObjectScale(0.0f, 0.0f, 0.0f),
    mbCanHaveObjectList(true)
{
    SetObjectScale(1.0f, 1.0f, 1.0f);
}

ObjectRaw::~ObjectRaw()
{
    delete[] mObjectVertexes;
    mObjectVertexes = nullptr;

    ClearObjectList();
}

bool ObjectRaw::LoadObjectFromFile(const char *fileName)
{
    return ObjectLoader::Instance()->LoadObjectFile(fileName, this);
}

glm::vec3 *&ObjectRaw::GetObjectVertexes()
{
    return mObjectVertexes;
}

bool ObjectRaw::SetObjectVertexQuantity(unsigned long quantity)
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
        std::cerr << ba.what() << " : Can't allocate ObjectVertexesArray" << std::endl;
        mObjectVertexes = nullptr;
        mObjectVertexQuantity = 0;
        return false;
    }

    return true;
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

void ObjectRaw::RotateObject(float x, float y, float z, float angle)
{
    //mObjectRotation = glm::rotate(mObjectRotation, angle, glm::vec3(x,y,z));
    //mObjectRotation = glm::normalize(mObjectRotation);
}

const glm::vec3 &ObjectRaw::GetObjectRotation()
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
