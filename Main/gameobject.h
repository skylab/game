#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "premain.h"

#include "../GraphicSystem/Objects/graphicobject.h"

class GameObject : public GraphicObject
{
public:
    GameObject();
    virtual ~GameObject() override;
};

#endif // GAMEOBJECT_H
