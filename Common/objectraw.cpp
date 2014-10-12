#include "objectraw.h"

#include "objectloader.h"

ObjectRaw::ObjectRaw() :
    mObjectVertexes(nullptr),
    mObjectVertexQuantity(0),

    mObjectFrontDirection(0.0f, 0.0f, 1.0f, 0.0f),
    mObjectRightDirection(1.0f, 0.0f, 0.0f, 0.0f),
    mObjectUpDirection(0.0f, 1.0f, 0.0f, 0.0f),

    mPositionRotationScaleMatrix(1.0f),

    mbCanHaveObjectList(true)
{
    SetObjectScale(glm::vec3(1.0f, 1.0f, 1.0f));
}

ObjectRaw::~ObjectRaw()
{
    delete[] mObjectVertexes;
    mObjectVertexes = nullptr;

    //ClearObjectList();
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

const size_t &ObjectRaw::GetObjectVertexQuantity() const
{
    return mObjectVertexQuantity;
}

const glm::mat4 &ObjectRaw::GetPositionRotationScaleMatrix()
{
    mPositionRotationScaleMatrix = glm::translate(mPositionRotationScaleMatrix, GetObjectPosition());
    mPositionRotationScaleMatrix = GetRotationMatrix();
    mPositionRotationScaleMatrix = glm::scale(mPositionRotationScaleMatrix, GetObjectScale());

    return mPositionRotationScaleMatrix;
}

void ObjectRaw::SetObjectPosition(glm::vec3 position)
{
    mObjectPosition = glm::vec4(position, 1.0f);
}

glm::vec3 ObjectRaw::GetObjectPosition() const
{
    return glm::vec3(mObjectPosition);
}

void ObjectRaw::RotateObject(glm::vec3 axisAngle)
{
    // TODO in using of quaternion;

    glm::fquat currentRotation;

    if (0 != axisAngle.x)
    {
        currentRotation.x = mObjectRightDirection.x * sin(axisAngle.x);
        currentRotation.y = mObjectRightDirection.y * sin(axisAngle.z);
        currentRotation.z = mObjectRightDirection.z * sin(axisAngle.z);
    }
    if (0 != axisAngle.y)
    {
        currentRotation.x = mObjectUpDirection.x * sin(axisAngle.x);
        currentRotation.y = mObjectUpDirection.y * sin(axisAngle.y);
        currentRotation.z = mObjectUpDirection.z * sin(axisAngle.z);
    }
    if (0 != axisAngle.z)
    {
        currentRotation.x = mObjectFrontDirection.x * sin(axisAngle.x);
        currentRotation.y = mObjectFrontDirection.y * sin(axisAngle.y);
        currentRotation.z = mObjectFrontDirection.z * sin(axisAngle.z);
    }

    mObjectRotation *= currentRotation;

    mObjectRotation = glm::normalize(mObjectRotation);

    std::cerr << mObjectRotation.x << " " << mObjectRotation.y << " " << mObjectRotation.z << std::endl;
}

void ObjectRaw::SetObjectScale(glm::vec3 scale)
{
    mObjectScale = glm::vec4(scale, 0.0f);
}

glm::vec3 ObjectRaw::GetObjectScale() const
{
    return glm::vec3(mObjectScale);
}

const std::list<ObjectRaw *> &ObjectRaw::GetChildObjectList()
{
    return mChildObjectList;
}

bool ObjectRaw::AddChildObject(ObjectRaw *object, glm::vec3 position)
{
    object->SetObjectPosition(position);
    mChildObjectList.push_back(object);
}

glm::mat4 ObjectRaw::GetRotationMatrix()
{
    return glm::mat4_cast(mObjectRotation);
}
