#ifndef OBJECT_H
#define OBJECT_H

#include "premain.h"

#include "../GraphicSystem/graphicobject.h"

class Object : public GraphicObject
{
protected:

public:
    Object();
    virtual ~Object() override;

protected:
    // TODO some game field like
    // ID
    // health etc.
};

#endif // OBJECT_H
