#include "object.h"

#include "../Utils/objectloader.h"

Object::Object() : mMoveSpeed(0.2777f)
{
    ;
}

Object::~Object()
{
    ;
}

bool Object::LoadObjectMesh(const char *filename)
{
    if (nullptr != filename)
    {
        bool loaded = ObjectLoader::Instance()->LoadObjectFile(filename, this);
        if (loaded)
        {
            LoadObjectToGraphicMemory();
        }
        else
        {
            std::cerr << __PRETTY_FUNCTION__ << ": Can't load: " << filename << std::endl;
            return false;
        }
    }
    else
    {
        std::cerr << __PRETTY_FUNCTION__ << ": filename is nullptr" << std::endl;
        return false;
    }
}

bool Object::LoadObjectTexture(const char *filename)
{
    if (nullptr != filename)
    {
        // TODO : Add loading texture
        return false;
    }
    else
    {
        std::cerr << __PRETTY_FUNCTION__ << ": filename is nullptr" << std::endl;
        return false;
    }
}

void Object::SetObjectMoveSpeed(float speed)
{
    mMoveSpeed = speed;
}

float Object::GetObjectMoveSpeed() const
{
    return mMoveSpeed;
}

void Object::AddDerivedObject(Object *object, glm::vec3 detivedPosition, glm::quat derivedRotation)
{
    // TODO : Set deriving information
    mDerivedObjects.push_back(object);
}

void Object::RemoveDerivedObject(Object *object)
{
    mDerivedObjects.remove(object);
}

void Object::Draw()
{
    //Draw object
    GraphicObject::Draw();

    // Draw derived object
    for (auto itr : mDerivedObjects)
    {
        Object *obj = itr;
        if (nullptr != obj)
        {
            // Draw all derived objects
            obj->GraphicObject::Draw();
        }
    }
}
