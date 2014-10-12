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
    glm::fquat currentRotationX;
    glm::fquat currentRotationY;
    glm::fquat currentRotationZ;

    if (0 != axisAngle.x)
    {
        currentRotationX.x = mObjectRightDirection.x * sin(axisAngle.x);
        currentRotationX.y = mObjectRightDirection.y * sin(axisAngle.z);
        currentRotationX.z = mObjectRightDirection.z * sin(axisAngle.z);
    }
    if (0 != axisAngle.y)
    {
        currentRotationY.x = mObjectUpDirection.x * sin(axisAngle.x);
        currentRotationY.y = mObjectUpDirection.y * sin(axisAngle.y);
        currentRotationY.z = mObjectUpDirection.z * sin(axisAngle.z);
    }
    if (0 != axisAngle.z)
    {
        currentRotationZ.x = mObjectFrontDirection.x * sin(axisAngle.x);
        currentRotationZ.y = mObjectFrontDirection.y * sin(axisAngle.y);
        currentRotationZ.z = mObjectFrontDirection.z * sin(axisAngle.z);
    }

    mObjectRotation *= (currentRotationX * currentRotationY * currentRotationZ);

    mObjectRotation = glm::normalize(mObjectRotation);

    mObjectRightDirection = GetRotationMatrix() * mObjectRightDirection;
    mObjectUpDirection = GetRotationMatrix() * mObjectUpDirection;
    mObjectFrontDirection = GetRotationMatrix() * mObjectFrontDirection;

    std::cerr << mObjectFrontDirection.x << " " << mObjectFrontDirection.y << " " << mObjectFrontDirection.z << std::endl;
    std::cerr << mObjectRightDirection.x << " " << mObjectRightDirection.y << " " << mObjectRightDirection.z << std::endl;
    std::cerr << mObjectUpDirection.x << " " << mObjectUpDirection.y << " " << mObjectUpDirection.z << std::endl;
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
