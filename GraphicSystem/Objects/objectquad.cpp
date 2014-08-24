#include "objectquad.h"

ObjectQuad::ObjectQuad(glm::vec3 position) : ObjectAbs(position)
{
    mVertexQuantity = 6;
    mObjectVertexes = new (std::nothrow) glm::vec3[mVertexQuantity];

    mObjectVertexes[0] = glm::vec3(-1.0f, 1.0f, 0.0f);
    mObjectVertexes[1] = glm::vec3(-1.0f, -1.0f, 0.0f);
    mObjectVertexes[2] = glm::vec3(1.0f, 1.0f, 0.0f);

    mObjectVertexes[3] = glm::vec3(1.0f, 1.0f, 0.0f);
    mObjectVertexes[4] = glm::vec3(1.0f, -1.0f, 0.0f);
    mObjectVertexes[5] = glm::vec3(-1.0f, -1.0f, 0.0f);
}

ObjectQuad::~ObjectQuad()
{
    ;
}
