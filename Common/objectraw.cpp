#include "objectraw.h"

#include "../Utils/objectloader.h"
#include "../Main/Commands/command.h"

ObjectRaw::ObjectRaw() :
    mObjectVertexes(nullptr),
    mObjectVertexQuantity(0),

    mObjectFrontDirection(0.0f, 0.0f, -1.0f, 0.0f),
    mObjectRightDirection(1.0f, 0.0f, 0.0f, 0.0f),
    mObjectUpDirection(0.0f, 1.0f, 0.0f, 0.0f),
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

const glm::vec3 &ObjectRaw::GetObjectFrontDirection(void)
{
    return glm::vec3(mObjectFrontDirection);
}

const glm::vec3 &ObjectRaw::GetObjectUpDirection()
{
    return glm::vec3(mObjectUpDirection);
}

const glm::vec3 &ObjectRaw::GetObjectRightDirection()
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

void ObjectRaw::ChangePitch(float degrees)
{
    mObjectPitch += degrees;
    mObjectPitch %= 360.0f;
}

void ObjectRaw::ChangeHeading(float degrees)
{
    mObjectHeading += degrees;
    mObjectHeading %= 360.0f;
}

void ObjectRaw::SetObjectScale(glm::vec3 scale)
{
    mObjectScale = glm::vec4(scale, 0.0f);
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
