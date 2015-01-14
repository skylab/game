#include "object.h"
#include "../ResourceLoader/modelloader.h"

Object::Object() : mbVisible(true)
{
    ;
}

Object::~Object()
{
    // Remove derived objects
    while (mDerivedObjects.size() != 0)
    {
        Object * obj = mDerivedObjects.back();
        delete obj;
        mDerivedObjects.remove(obj);
    }
}

void Object::SetScene(Scene *scene)
{
    GraphicLevel::SetScene(scene);

    for (auto i : mDerivedObjects)
    {
        Object * obj = i;
        obj->SetScene(scene);
    }
}

void Object::Draw()
{
    if (mbVisible)
        GraphicLevel::Draw();

    for (auto i : mDerivedObjects)
    {
        Object * obj = i;
        obj->Draw();
    }
}

void Object::SetVertexQuantity(unsigned int quantity)
{
    BaseLevel::SetVertexQuantity(quantity);
    GraphicLevel::SetVertexQuantity(quantity);
}

bool Object::LoadModel(const char *file)
{
    if (ModelLoader::Instance()->LoadModelFile(file, this))
    {
        LoadToGraphicMemory();

        for (auto i : mDerivedObjects)
        {
            Object * obj = i;
            obj->LoadToGraphicMemory();
            obj->SetScene(mScene);
        }
        return true;
    }

    return false;
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
