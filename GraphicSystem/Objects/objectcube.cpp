#include "objectcube.h"

ObjectCube::ObjectCube()
{
    mVertexQuantity = 36;
    mObjectVertexes = new (std::nothrow) Vertex3f[mVertexQuantity];
    mObjectColor = new (std::nothrow) Vertex3f[mVertexQuantity];

    mObjectVertexes[0] = Vertex3f(-1.0f, 1.0f, 1.0f); // Front
    mObjectVertexes[1] = Vertex3f(-1.0f, -1.0f, 1.0f);
    mObjectVertexes[2] = Vertex3f(1.0f, 1.0f, 1.0f);

    mObjectVertexes[3] = Vertex3f(1.0f, 1.0f, 1.0f);
    mObjectVertexes[4] = Vertex3f(1.0f, -1.0f, 1.0f);
    mObjectVertexes[5] = Vertex3f(-1.0f, -1.0f, 1.0f); // End front

    mObjectVertexes[6] = Vertex3f(-1.0f, 1.0f, -1.0f); // back
    mObjectVertexes[7] = Vertex3f(-1.0f, -1.0f, -1.0f);
    mObjectVertexes[8] = Vertex3f(1.0f, 1.0f, -1.0f);

    mObjectVertexes[9] =  Vertex3f(1.0f, 1.0f, -1.0f);
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

    //
    mObjectColor[0] = Vertex3f(1.0f,  0.0f,  0.0f);
    mObjectColor[1] = Vertex3f(1.0f,  0.0f,  0.0f);
    mObjectColor[2] = Vertex3f(1.0f,  0.0f,  0.0f);

    mObjectColor[3] = Vertex3f(0.0f,  1.0f,  0.0f);
    mObjectColor[4] = Vertex3f(0.0f,  1.0f,  0.0f);
    mObjectColor[5] = Vertex3f(0.0f,  1.0f,  0.0f);

    mObjectColor[6] = Vertex3f(0.0f,  0.0f,  1.0f);
    mObjectColor[7] = Vertex3f(0.0f,  0.0f,  1.0f);
    mObjectColor[8] = Vertex3f(0.0f,  0.0f,  1.0f);

    mObjectColor[9] =  Vertex3f(0.0f,  1.0f,  0.0f);
    mObjectColor[10] = Vertex3f(0.0f,  1.0f,  0.0f);
    mObjectColor[11] = Vertex3f(0.0f,  1.0f,  0.0f);

    mObjectColor[12] = Vertex3f(0.0f,  0.0f,  1.0f);
    mObjectColor[13] = Vertex3f(0.0f,  0.0f,  1.0f);
    mObjectColor[14] = Vertex3f(0.0f,  0.0f,  1.0f);

    mObjectColor[15] = Vertex3f(1.0f,  0.0f,  0.0f);
    mObjectColor[16] = Vertex3f(1.0f,  0.0f,  0.0f);
    mObjectColor[17] = Vertex3f(1.0f,  0.0f,  0.0f);

    mObjectColor[18] = Vertex3f(0.0f,  0.0f,  1.0f);
    mObjectColor[19] = Vertex3f(0.0f,  0.0f,  1.0f);
    mObjectColor[20] = Vertex3f(0.0f,  0.0f,  1.0f);

    mObjectColor[21] = Vertex3f(0.0f,  1.0f,  0.0f);
    mObjectColor[22] = Vertex3f(0.0f,  1.0f,  0.0f);
    mObjectColor[23] = Vertex3f(0.0f,  1.0f,  0.0f);

    mObjectColor[24] = Vertex3f(1.0f,  0.0f,  0.0f);
    mObjectColor[25] = Vertex3f(1.0f,  0.0f,  0.0f);
    mObjectColor[26] = Vertex3f(1.0f,  0.0f,  0.0f);

    mObjectColor[27] = Vertex3f(0.0f,  1.0f,  0.0f);
    mObjectColor[28] = Vertex3f(0.0f,  1.0f,  0.0f);
    mObjectColor[29] = Vertex3f(0.0f,  1.0f,  0.0f);

    mObjectColor[30] = Vertex3f(0.0f,  0.0f,  1.0f);
    mObjectColor[31] = Vertex3f(0.0f,  0.0f,  1.0f);
    mObjectColor[32] = Vertex3f(0.0f,  0.0f,  1.0f);

    mObjectColor[33] = Vertex3f(1.0f,  0.0f,  0.0f);
    mObjectColor[34] = Vertex3f(1.0f,  0.0f,  0.0f);
    mObjectColor[35] = Vertex3f(1.0f,  0.0f,  0.0f);
}

ObjectCube::~ObjectCube()
{
    ;
}
