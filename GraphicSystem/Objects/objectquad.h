#ifndef OBJECTQUAD_H
#define OBJECTQUAD_H

#include "objectabs.h"

class ObjectQuad : public ObjectAbs
{
public:
    ObjectQuad(glm::vec3 position);
    ~ObjectQuad();
};

#endif // OBJECTQUAD_H
