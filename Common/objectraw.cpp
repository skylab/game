#include "objectraw.h"

#include "objectloader.h"

ObjectRaw::ObjectRaw() :
    mObjectVertexes(nullptr),
    mObjectVertexQuantity(0),

    mObjectFrontDirection(0.0f, 0.0f, -1.0f, 0.0f),
    mObjectRightDirection(1.0f, 0.0f, 0.0f, 0.0f),
    mObjectUpDirection(0.0f, 1.0f, 0.0f, 0.0f),

    mPositionRotationScaleMatrix(1.0f),

    mbCanHaveObjectList(true)
{
    SetObjectScale(glm::vec3(1.0f, 1.0f, 1.0f));
    mObjectRotation = glm::quat();

    FixAxis(false, false, false);
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
    mPositionRotationScaleMatrix = glm::translate(glm::mat4(1.0f), GetObjectPosition());
    mPositionRotationScaleMatrix *= GetRotationMatrix();
    mPositionRotationScaleMatrix *= glm::scale(glm::mat4(1.0f), GetObjectScale());
    return mPositionRotationScaleMatrix;
}

glm::vec3 ObjectRaw::GetObjectFrontDirection(void)
{
    return glm::vec3(mObjectFrontDirection);
}

glm::vec3 ObjectRaw::GetObjectUpDirection()
{
    return glm::vec3(mObjectUpDirection);
}

glm::vec3 ObjectRaw::GetObjectRightDirection()
{
    return glm::vec3(mObjectRightDirection);
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
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;

    if (axisAngle.x)
        x = axisAngle.x * 3.14f / 180.0f;

    if (axisAngle.y)
        y = axisAngle.y * 3.14f / 180.0f;

    if (axisAngle.z)
        z = axisAngle.z * 3.14f / 180.0f;

    //std::cerr << "Angles" << std::endl;
    //std::cerr << x << " " << y << " " << z << std::endl;

    // TODO in using of quaternion;
    glm::fquat currentRotationX;
    glm::fquat currentRotationY;
    glm::fquat currentRotationZ;

    if (0 != x)
    {
        currentRotationX.x = mObjectRightDirection.x * sin(x/2.0f);
        currentRotationX.y = mObjectRightDirection.y * sin(x/2.0f);
        currentRotationX.z = mObjectRightDirection.z * sin(x/2.0f);
        currentRotationX.w = cos(x/2.0f);
        currentRotationX = glm::normalize(currentRotationX);
    }
    if (0 != y)
    {
        currentRotationY.x = mObjectUpDirection.x * sin(y/2.0f);
        currentRotationY.y = mObjectUpDirection.y * sin(y/2.0f);
        currentRotationY.z = mObjectUpDirection.z * sin(y/2.0f);
        currentRotationY.w = cos(y/2.0f);
        currentRotationY = glm::normalize(currentRotationY);
    }
    if (0 != z)
    {
        currentRotationZ.x = mObjectFrontDirection.x * sin(z/2.0f);
        currentRotationZ.y = mObjectFrontDirection.y * sin(z/2.0f);
        currentRotationZ.z = mObjectFrontDirection.z * sin(z/2.0f);
        currentRotationZ.w = cos(z/2.0f);
        currentRotationZ = glm::normalize(currentRotationZ);
    }

    mObjectRotation = mObjectRotation *currentRotationX * currentRotationY * currentRotationZ;
    mObjectRotation = glm::normalize(mObjectRotation);

    if (!mFixAxis.Up)
    {
        //std::cerr << "Up" << std::endl;
        //std::cerr << mObjectUpDirection.x << " " << mObjectUpDirection.y << " " << mObjectUpDirection.z << std::endl;
        mObjectUpDirection = glm::mat4_cast(currentRotationX * currentRotationY * currentRotationZ) * mObjectUpDirection;
        mObjectUpDirection = glm::normalize(mObjectUpDirection);
        //std::cerr << mObjectUpDirection.x << " " << mObjectUpDirection.y << " " << mObjectUpDirection.z << std::endl;
    }
    if (!mFixAxis.Right)
    {
        //std::cerr << "Right" << std::endl;
        //std::cerr << mObjectRightDirection.x << " " << mObjectRightDirection.y << " " << mObjectRightDirection.z << std::endl;
        mObjectRightDirection = glm::mat4_cast(currentRotationX * currentRotationY * currentRotationZ) * mObjectRightDirection;
        mObjectRightDirection = glm::normalize(mObjectRightDirection);
        //std::cerr << mObjectRightDirection.x << " " << mObjectRightDirection.y << " " << mObjectRightDirection.z << std::endl;
    }
    if (!mFixAxis.Front)
    {
        //std::cerr << "Front" << std::endl;
        //std::cerr << mObjectFrontDirection.x << " " << mObjectFrontDirection.y << " " << mObjectFrontDirection.z << std::endl;
        mObjectFrontDirection = glm::mat4_cast(currentRotationX * currentRotationY * currentRotationZ) * mObjectFrontDirection;
        mObjectFrontDirection = glm::normalize(mObjectFrontDirection);
        //std::cerr << mObjectFrontDirection.x << " " << mObjectFrontDirection.y << " " << mObjectFrontDirection.z << std::endl;
    }
}

void ObjectRaw::SetObjectScale(glm::vec3 scale)
{
    mObjectScale = glm::vec4(scale, 0.0f);
}

glm::vec3 ObjectRaw::GetObjectScale() const
{
    return glm::vec3(mObjectScale);
}

void ObjectRaw::FixAxis(bool up, bool right, bool front)
{
    mFixAxis.Up = up;
    mFixAxis.Right = right;
    mFixAxis.Front = front;
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
