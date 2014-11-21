#include "objectraw.h"

#include "../Utils/objectloader.h"

ObjectRaw::ObjectRaw() :
    mLockedUp(false),
    mObjectVertexes(nullptr),
    mObjectVertexQuantity(0),

    mObjectFrontDirection(0.0f, 0.0f, -1.0f),
    mObjectUpDirection(0.0f, 1.0f, 0.0f),
    mMoveSpeed(0.2777f),

    mPositionRotationScaleMatrix(1.0f)
{
    SetObjectScale(glm::vec3(1.0f, 1.0f, 1.0f));
    mObjectRotation = glm::quat();
}

ObjectRaw::~ObjectRaw()
{
    delete[] mObjectVertexes;
    mObjectVertexes = nullptr;
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
    mPositionRotationScaleMatrix = glm::translate(glm::mat4(1.0f), GetObjectPosition());
    mPositionRotationScaleMatrix *= GetRotationMatrix();
    mPositionRotationScaleMatrix *= glm::scale(glm::mat4(1.0f), GetObjectScale());
    return mPositionRotationScaleMatrix;
}

void ObjectRaw::SetObjectFrontDirection(glm::vec3 direction)
{
    mObjectFrontDirection = direction;
    mObjectFrontDirection = glm::normalize(mObjectFrontDirection);
}

glm::vec3 ObjectRaw::GetObjectFrontDirection(void)
{
    return glm::vec3(mObjectFrontDirection);
}

void ObjectRaw::SetObjectUpDirection(glm::vec3 direction)
{
    mObjectUpDirection = direction;
    mObjectUpDirection = glm::normalize(mObjectUpDirection);
}

glm::vec3 ObjectRaw::GetObjectUpDirection()
{
    return glm::vec3(mObjectUpDirection);
}

void ObjectRaw::LockUpDirection(bool val)
{
    mLockedUp = val;
}

bool ObjectRaw::GetLockUpDirection() const
{
    return mLockedUp;
}

void ObjectRaw::SetObjectPosition(glm::vec3 position)
{
    mObjectPosition = position;
}

glm::vec3 ObjectRaw::GetObjectPosition() const
{
    return glm::vec3(mObjectPosition);
}

void ObjectRaw::RotatePitch(float degrees)
{
    glm::quat rot;
    rot.x = glm::cross(GetObjectFrontDirection(), GetObjectUpDirection()).x * sin(degrees/2);
    rot.y = glm::cross(GetObjectFrontDirection(), GetObjectUpDirection()).y * sin(degrees/2);
    rot.z = glm::cross(GetObjectFrontDirection(), GetObjectUpDirection()).z * sin(degrees/2);
    rot.w = cos(degrees/2);

    mObjectFrontDirection = rot * mObjectFrontDirection;

    if (!GetLockUpDirection())
        mObjectUpDirection = rot * mObjectUpDirection;

    mObjectRotation = rot * mObjectRotation;
    mObjectRotation = glm::normalize(mObjectRotation);
}

void ObjectRaw::RotateHeading(float degrees)
{
    glm::quat rot;
    rot.x = GetObjectUpDirection().x * sin(degrees/2);
    rot.y = GetObjectUpDirection().y * sin(degrees/2);
    rot.z = GetObjectUpDirection().z * sin(degrees/2);
    rot.w = cos(degrees/2);

    mObjectFrontDirection = rot * mObjectFrontDirection;

    if (!GetLockUpDirection())
        mObjectUpDirection = rot * mObjectUpDirection;

    mObjectRotation = rot * mObjectRotation;
    mObjectRotation = glm::normalize(mObjectRotation);
}

void ObjectRaw::SetObjectScale(glm::vec3 scale)
{
    mObjectScale = scale;
}

glm::vec3 ObjectRaw::GetObjectScale() const
{
    return glm::vec3(mObjectScale);
}

void ObjectRaw::MoveToDirection(MoveDirection direction)
{
    switch(direction)
    {
    case FORWARD:
        mObjectPosition = mObjectPosition + (mObjectFrontDirection * mMoveSpeed);
        break;
    case BACK:
        mObjectPosition = mObjectPosition - (mObjectFrontDirection * mMoveSpeed);
        break;
    case LEFT:
        mObjectPosition = mObjectPosition - (glm::cross(mObjectFrontDirection, mObjectUpDirection) * mMoveSpeed);
        break;
    case RIGHT:
        mObjectPosition = mObjectPosition + (glm::cross(mObjectFrontDirection, mObjectUpDirection) * mMoveSpeed);
        break;
    case UP:
        mObjectPosition = mObjectPosition + (mObjectUpDirection * mMoveSpeed);
        break;
    case DOWN:
        mObjectPosition = mObjectPosition - (mObjectUpDirection * mMoveSpeed);
        break;
    }
}

void ObjectRaw::MoveToDirection(glm::vec3 direction)
{
    //glm::vec3 dir = glm::normalize(direction);
    mObjectPosition = mObjectPosition + direction;
}

glm::mat4 ObjectRaw::GetRotationMatrix()
{
    return glm::mat4_cast(mObjectRotation);
}
