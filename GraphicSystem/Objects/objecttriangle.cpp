#include "objecttriangle.h"

ObjectTriangle::ObjectTriangle(glm::vec3 position) : ObjectAbs(position)
{
    mVertexQuantity = 3;
    mObjectVertexes = new (std::nothrow) glm::vec3[mVertexQuantity];

    mObjectVertexes[0] = glm::vec3(-1.0f, -1.0f, 0.0f);
    mObjectVertexes[1] = glm::vec3(0.0f, 1.0f, 0.0f);
    mObjectVertexes[2] = glm::vec3(1.0f, -1.0f, 0.0f);
}

ObjectTriangle::~ObjectTriangle()
{
    ;
}
