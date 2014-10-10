#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "premain.h"

#include "../GraphicSystem/Objects/graphicobject.h"

class GameObject : public GraphicObject
{
protected:

public:
    GameObject();
    virtual ~GameObject() override;

protected:
    // TODO some field like
    // ID
    // health etc.
};

#endif // GAMEOBJECT_H
