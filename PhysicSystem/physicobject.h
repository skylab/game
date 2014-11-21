#ifndef PHYSICOBJECT_H
#define PHYSICOBJECT_H

#include "../Common/objectraw.h"

class PhysicObject : virtual public ObjectRaw
{
public:
    ~PhysicObject();

protected:
    PhysicObject();
};

#endif // PHYSICOBJECT_H
