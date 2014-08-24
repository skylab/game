#include "objectquad.h"

ObjectQuad::ObjectQuad()
{
    mVertexQuantity = 6;
    mObjectVertexes = new (std::nothrow) Vertex3f[mVertexQuantity];

    mObjectVertexes[0] = Vertex3f(-1.0f, 1.0f, 0.0f);
    mObjectVertexes[1] = Vertex3f(-1.0f, -1.0f, 0.0f);
    mObjectVertexes[2] = Vertex3f(1.0f, 1.0f, 0.0f);

    mObjectVertexes[3] = Vertex3f(1.0f, 1.0f, 0.0f);
    mObjectVertexes[4] = Vertex3f(1.0f, -1.0f, 0.0f);
    mObjectVertexes[5] = Vertex3f(-1.0f, -1.0f, 0.0f);
}

ObjectQuad::~ObjectQuad()
{
    ;
}
