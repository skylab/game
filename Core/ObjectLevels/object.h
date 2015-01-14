#ifndef OBJECT_H
#define OBJECT_H

#include "GraphicLevel/graphiclevel.h"
#include "PhysicLevel/physiclevel.h"

class Object : public PhysicLevel, public GraphicLevel
{
public:
    Object();
    virtual ~Object() override;

    virtual void SetScene(Scene *scene) override;
    virtual void Draw(void) override;

    virtual void SetVertexQuantity(unsigned int quantity) override;

public:
    bool LoadModel(const char *file);

    void AddDerivedObject(Object *object);
    void RemoveDerivedObject(Object *object);

private:
    bool mbVisible;
    std::list<Object*> mDerivedObjects;
};

#endif // OBJECT_H
