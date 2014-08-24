#include "objectcube.h"

ObjectCube::ObjectCube()
{
    mVertexQuantity = 36;
    mObjectVertexes = new (std::nothrow) Vertex3f[mVertexQuantity];

    mObjectVertexes[0] = Vertex3f(-1.0f, 1.0f, 1.0f); // Front
    mObjectVertexes[1] = Vertex3f(-1.0f, -1.0f, 1.0f);
    mObjectVertexes[2] = Vertex3f(1.0f, 1.0f, 1.0f);

    mObjectVertexes[3] = Vertex3f(1.0f, 1.0f, 1.0f);
    mObjectVertexes[4] = Vertex3f(1.0f, -1.0f, 1.0f);
    mObjectVertexes[5] = Vertex3f(-1.0f, -1.0f, 1.0f); // End front

    mObjectVertexes[6] = Vertex3f(-1.0f, 1.0f, -1.0f); // back
    mObjectVertexes[7] = Vertex3f(-1.0f, -1.0f, -1.0f);
    mObjectVertexes[8] = Vertex3f(1.0f, 1.0f, -1.0f);

    mObjectVertexes[9] = Vertex3f(1.0f, 1.0f, -1.0f);
    mObjectVertexes[10] = Vertex3f(1.0f, -1.0f, -1.0f);
    mObjectVertexes[11] = Vertex3f(-1.0f, -1.0f, -1.0f); // End back


    mObjectVertexes[12] = Vertex3f(1.0f, 1.0f, -1.0f); // right
    mObjectVertexes[13] = Vertex3f(1.0f, -1.0f, -1.0f);
    mObjectVertexes[14] = Vertex3f(1.0f, 1.0f, 1.0f);

    mObjectVertexes[15] = Vertex3f(1.0f, 1.0f, 1.0f);
    mObjectVertexes[16] = Vertex3f(1.0f, -1.0f, 1.0f);
    mObjectVertexes[17] = Vertex3f(1.0f, -1.0f, -1.0f); // End right

    mObjectVertexes[18] = Vertex3f(-1.0f, 1.0f, -1.0f); // left
    mObjectVertexes[19] = Vertex3f(-1.0f, -1.0f, -1.0f);
    mObjectVertexes[20] = Vertex3f(-1.0f, 1.0f, 1.0f);

    mObjectVertexes[21] = Vertex3f(-1.0f, 1.0f, 1.0f);
    mObjectVertexes[22] = Vertex3f(-1.0f, -1.0f, 1.0f);
    mObjectVertexes[23] = Vertex3f(-1.0f, -1.0f, -1.0f); // End left

    mObjectVertexes[24] = Vertex3f(1.0f, -1.0f, -1.0f); // down
    mObjectVertexes[25] = Vertex3f(-1.0f, -1.0f, -1.0f);
    mObjectVertexes[26] = Vertex3f(1.0f, -1.0f, 1.0f);

    mObjectVertexes[27] = Vertex3f(1.0f, -1.0f, 1.0f);
    mObjectVertexes[28] = Vertex3f(-1.0f, -1.0f, 1.0f);
    mObjectVertexes[29] = Vertex3f(-1.0f, -1.0f, -1.0f); // End down

    mObjectVertexes[30] = Vertex3f(1.0f, 1.0f, -1.0f); // up
    mObjectVertexes[31] = Vertex3f(-1.0f, 1.0f, -1.0f);
    mObjectVertexes[32] = Vertex3f(1.0f, 1.0f, 1.0f);

    mObjectVertexes[33] = Vertex3f(1.0f, 1.0f, 1.0f);
    mObjectVertexes[34] = Vertex3f(-1.0f, 1.0f, 1.0f);
    mObjectVertexes[35] = Vertex3f(-1.0f, 1.0f, -1.0f); // End up
}

ObjectCube::~ObjectCube()
{
    ;
}
