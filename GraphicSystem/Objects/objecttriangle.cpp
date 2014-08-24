#include "objecttriangle.h"

ObjectTriangle::ObjectTriangle()
{
    mVertexQuantity = 3;
    mObjectVertexes = new (std::nothrow) Vertex3f[mVertexQuantity];

    mObjectVertexes[0] = Vertex3f(-1.0f, -1.0f, 0.0f);
    mObjectVertexes[1] = Vertex3f(0.0f, 1.0f, 0.0f);
    mObjectVertexes[2] = Vertex3f(1.0f, -1.0f, 0.0f);
}

ObjectTriangle::~ObjectTriangle()
{
    ;
}
