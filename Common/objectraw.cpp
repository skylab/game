#include "objectraw.h"

#include "../Utils/objectloader.h"
#include "../Main/Commands/command.h"

ObjectRaw::ObjectRaw() :
    mObjectVertexes(nullptr),
    mObjectVertexQuantity(0),

    mObjectMoveSpeed(0.1f),

    mObjectFrontDirection(0.0f, 0.0f, -1.0f),
    mObjectUpDirection(0.0f, 1.0f, 0.0f),

    mPositionRotationScaleMatrix(1.0f)
{
    SetCanBeChild(true);
    SetSupportChildList(true);
    SetObjectScale(glm::vec3(1.0f, 1.0f, 1.0f));
    mObjectRotation = glm::quat();
}

ObjectRaw::~ObjectRaw()
{
    delete[] mObjectVertexes;
    mObjectVertexes = nullptr;

    mChildObjectList.clear();
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

void ObjectRaw::MoveObject(MoveDirection direction)
{
    switch(direction)
    {
    case FORWARD:
        SetObjectPosition(GetObjectPosition() + GetObjectFrontDirection() * GetObjectMoveSpeed());
        break;
    case BACK:
        SetObjectPosition(GetObjectPosition() - GetObjectFrontDirection() * GetObjectMoveSpeed());
        break;
    case LEFT:
        SetObjectPosition(GetObjectPosition() - glm::cross(GetObjectFrontDirection(), GetObjectUpDirection()) * GetObjectMoveSpeed());
        break;
    case RIGHT:
        SetObjectPosition(GetObjectPosition() + glm::cross(GetObjectFrontDirection(), GetObjectUpDirection()) * GetObjectMoveSpeed());
        break;
    case UP:
        SetObjectPosition(GetObjectPosition() + GetObjectUpDirection() * GetObjectMoveSpeed());
        break;
    case DOWN:
        SetObjectPosition(GetObjectPosition() - GetObjectUpDirection() * GetObjectMoveSpeed());
        break;
    }
}

void ObjectRaw::SetObjectMoveSpeed(float speed)
{
    mObjectMoveSpeed = speed;
}

float ObjectRaw::GetObjectMoveSpeed() const
{
    return mObjectMoveSpeed;
}

void ObjectRaw::SetObjectFrontDirection(glm::vec3 direction)
{
    mObjectFrontDirection = direction;
}

glm::vec3 ObjectRaw::GetObjectFrontDirection(void)
{
    return glm::vec3(mObjectFrontDirection);
}

void ObjectRaw::SetObjectUpDirection(glm::vec3 direction)
{
    mObjectUpDirection = direction;
}

glm::vec3 ObjectRaw::GetObjectUpDirection()
{
    return glm::vec3(mObjectUpDirection);
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
    mObjectUpDirection = rot * mObjectUpDirection;

    mObjectRotation = rot * mObjectRotation;
}

void ObjectRaw::RotateHeading(float degrees)
{
    glm::quat rot;
    rot.x = GetObjectUpDirection().x * sin(degrees/2);
    rot.y = GetObjectUpDirection().y * sin(degrees/2);
    rot.z = GetObjectUpDirection().z * sin(degrees/2);
    rot.w = cos(degrees/2);

    mObjectFrontDirection = rot * mObjectFrontDirection;
    mObjectUpDirection = rot * mObjectUpDirection;

    mObjectRotation = rot * mObjectRotation;
}

void ObjectRaw::SetObjectScale(glm::vec3 scale)
{
    mObjectScale = scale;
}

glm::vec3 ObjectRaw::GetObjectScale() const
{
    return glm::vec3(mObjectScale);
}

void ObjectRaw::SetSupportChildList(bool val)
{
    mbSupportChildList = val;
}

bool ObjectRaw::GetSupportChildList() const
{
    return mbSupportChildList;
}

void ObjectRaw::SetCanBeChild(bool val)
{
    mbCanBeChild = val;
}

bool ObjectRaw::GetCanBeChild() const
{
    return mbCanBeChild;
}

const std::list<ObjectRaw *> &ObjectRaw::GetChildObjectList()
{
    return mChildObjectList;
}

bool ObjectRaw::AddChildObject(ObjectRaw *object, glm::vec3 position)
{
    if (nullptr == object)
    {
        std::cerr << "AddChildObject object is nullptr" << std::endl;
        return false;
    }

    if(object->GetCanBeChild())
    {
        object->SetObjectPosition(position);
        mChildObjectList.push_back(object);
    }
    else
    {
        std::cerr << "AddChildObject object can't be a child" << std::endl;
    }
}

void ObjectRaw::RemoveChilds()
{
    mChildObjectList.clear();
}

void ObjectRaw::Accept(Command *command)
{
    command->Visit(this);
}

glm::mat4 ObjectRaw::GetRotationMatrix()
{
    return glm::mat4_cast(mObjectRotation);
}
