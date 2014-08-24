#ifndef OBJECTTRIANGLE_H
#define OBJECTTRIANGLE_H

#include "objectabs.h"

class ObjectTriangle : public ObjectAbs
{
public:
    ObjectTriangle(glm::vec3 position);
    ~ObjectTriangle();
};

#endif // OBJECTTRIANGLE_H
