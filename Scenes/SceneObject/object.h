#ifndef OBJECT_H
#define OBJECT_H

#include "../../Common/precommon.h"
#include "../../GraphicSystem/Objects/graphicobject.h"

class Object : public GraphicObject // , PhysicObject
{
public:
    Object();
    virtual ~Object();
};

#endif // OBJECT_H
