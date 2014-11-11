#include "object.h"

#include "../Utils/objectloader.h"
#include "../Utils/imageloader.h"

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
        if (ObjectLoader::Instance()->LoadObjectFile(filename, this))
        {
            // Load parent object and all derived
            LoadObjectToGraphicMemory();
            return true;
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
        return ImageLoader::Instance()->LoadImageFile(filename, GetObjectTexture());
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

void Object::AddDerivedObject(Object *object)
{
    // TODO : Set deriving information
    mDerivedObjects.push_back(object);
}

void Object::RemoveDerivedObject(Object *object)
{
    mDerivedObjects.remove(object);
}

void Object::LoadObjectToGraphicMemory()
{
    GraphicObject::LoadObjectToGraphicMemory();
    for(auto itr : mDerivedObjects)
    {
        Object* obj = itr;
        if (nullptr != obj)
        {
            // Load all derived objects
            obj->LoadObjectToGraphicMemory();
        }
    }
}

void Object::SetObjectPosition(glm::vec3 position)
{
    ObjectRaw::SetObjectPosition(position);
    for(auto itr : mDerivedObjects)
        itr->SetObjectPosition(position);
}

void Object::RotatePitch(float degrees)
{
    ObjectRaw::RotatePitch(degrees);
    for(auto itr : mDerivedObjects)
        itr->RotatePitch(degrees);
}

void Object::RotateHeading(float degrees)
{
    ObjectRaw::RotateHeading(degrees);
    for(auto itr : mDerivedObjects)
        itr->RotateHeading(degrees);
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
