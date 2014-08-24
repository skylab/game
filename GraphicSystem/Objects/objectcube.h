#ifndef OBJECTCUBE_H
#define OBJECTCUBE_H

#include "objectabs.h"

class ObjectCube : public ObjectAbs
{
public:
    ObjectCube(glm::vec3 position);
    ~ObjectCube();

    void FillVertexArray();
    void FillColorArray();
};

#endif // OBJECTCUBE_H
