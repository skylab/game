#include "objectcube.h"

ObjectCube::ObjectCube(glm::vec3 position) : ObjectAbs(position)
{
    FillVertexArray();
    FillColorArray();
}

ObjectCube::~ObjectCube()
{
    delete[] mObjectVertexes;
    mObjectVertexes = NULL;
    delete[] mObjectColor;
    mObjectColor = NULL;
    mVertexQuantity = 0;
}

void ObjectCube::FillVertexArray()
{
    mObjectScale = glm::vec3(1.0f, 1.0f, 1.0f);
    mObjectCoordinate = glm::vec3(0.0f, 0.0f, 0.0f);

    mVertexQuantity = 36;
    mObjectVertexes = new (std::nothrow) glm::vec3[mVertexQuantity];

    mObjectVertexes[0] = glm::vec3(-1.0f, 1.0f, 1.0f); // Front
    mObjectVertexes[1] = glm::vec3(-1.0f, -1.0f, 1.0f);
    mObjectVertexes[2] = glm::vec3(1.0f, 1.0f, 1.0f);

    mObjectVertexes[3] = glm::vec3(1.0f, 1.0f, 1.0f);
    mObjectVertexes[4] = glm::vec3(1.0f, -1.0f, 1.0f);
    mObjectVertexes[5] = glm::vec3(-1.0f, -1.0f, 1.0f); // End front

    mObjectVertexes[6] = glm::vec3(-1.0f, 1.0f, -1.0f); // back
    mObjectVertexes[7] = glm::vec3(-1.0f, -1.0f, -1.0f);
    mObjectVertexes[8] = glm::vec3(1.0f, 1.0f, -1.0f);

    mObjectVertexes[9] =  glm::vec3(1.0f, 1.0f, -1.0f);
    mObjectVertexes[10] = glm::vec3(1.0f, -1.0f, -1.0f);
    mObjectVertexes[11] = glm::vec3(-1.0f, -1.0f, -1.0f); // End back


    mObjectVertexes[12] = glm::vec3(1.0f, 1.0f, -1.0f); // right
    mObjectVertexes[13] = glm::vec3(1.0f, -1.0f, -1.0f);
    mObjectVertexes[14] = glm::vec3(1.0f, 1.0f, 1.0f);

    mObjectVertexes[15] = glm::vec3(1.0f, 1.0f, 1.0f);
    mObjectVertexes[16] = glm::vec3(1.0f, -1.0f, 1.0f);
    mObjectVertexes[17] = glm::vec3(1.0f, -1.0f, -1.0f); // End right

    mObjectVertexes[18] = glm::vec3(-1.0f, 1.0f, -1.0f); // left
    mObjectVertexes[19] = glm::vec3(-1.0f, -1.0f, -1.0f);
    mObjectVertexes[20] = glm::vec3(-1.0f, 1.0f, 1.0f);

    mObjectVertexes[21] = glm::vec3(-1.0f, 1.0f, 1.0f);
    mObjectVertexes[22] = glm::vec3(-1.0f, -1.0f, 1.0f);
    mObjectVertexes[23] = glm::vec3(-1.0f, -1.0f, -1.0f); // End left

    mObjectVertexes[24] = glm::vec3(1.0f, -1.0f, -1.0f); // down
    mObjectVertexes[25] = glm::vec3(-1.0f, -1.0f, -1.0f);
    mObjectVertexes[26] = glm::vec3(1.0f, -1.0f, 1.0f);

    mObjectVertexes[27] = glm::vec3(1.0f, -1.0f, 1.0f);
    mObjectVertexes[28] = glm::vec3(-1.0f, -1.0f, 1.0f);
    mObjectVertexes[29] = glm::vec3(-1.0f, -1.0f, -1.0f); // End down

    mObjectVertexes[30] = glm::vec3(1.0f, 1.0f, -1.0f); // up
    mObjectVertexes[31] = glm::vec3(-1.0f, 1.0f, -1.0f);
    mObjectVertexes[32] = glm::vec3(1.0f, 1.0f, 1.0f);

    mObjectVertexes[33] = glm::vec3(1.0f, 1.0f, 1.0f);
    mObjectVertexes[34] = glm::vec3(-1.0f, 1.0f, 1.0f);
    mObjectVertexes[35] = glm::vec3(-1.0f, 1.0f, -1.0f); // End up
}

void ObjectCube::FillColorArray()
{
    mObjectColor = new (std::nothrow) glm::vec3[mVertexQuantity];

    mObjectColor[0] = glm::vec3(1.0f,  0.0f,  0.0f);
    mObjectColor[1] = glm::vec3(1.0f,  0.0f,  0.0f);
    mObjectColor[2] = glm::vec3(1.0f,  0.0f,  0.0f);

    mObjectColor[3] = glm::vec3(0.0f,  1.0f,  0.0f);
    mObjectColor[4] = glm::vec3(0.0f,  1.0f,  0.0f);
    mObjectColor[5] = glm::vec3(0.0f,  1.0f,  0.0f);

    mObjectColor[6] = glm::vec3(0.0f,  0.0f,  1.0f);
    mObjectColor[7] = glm::vec3(0.0f,  0.0f,  1.0f);
    mObjectColor[8] = glm::vec3(0.0f,  0.0f,  1.0f);

    mObjectColor[9] =  glm::vec3(0.0f,  1.0f,  0.0f);
    mObjectColor[10] = glm::vec3(0.0f,  1.0f,  0.0f);
    mObjectColor[11] = glm::vec3(0.0f,  1.0f,  0.0f);

    mObjectColor[12] = glm::vec3(0.0f,  0.0f,  1.0f);
    mObjectColor[13] = glm::vec3(0.0f,  0.0f,  1.0f);
    mObjectColor[14] = glm::vec3(0.0f,  0.0f,  1.0f);

    mObjectColor[15] = glm::vec3(1.0f,  0.0f,  0.0f);
    mObjectColor[16] = glm::vec3(1.0f,  0.0f,  0.0f);
    mObjectColor[17] = glm::vec3(1.0f,  0.0f,  0.0f);

    mObjectColor[18] = glm::vec3(0.0f,  0.0f,  1.0f);
    mObjectColor[19] = glm::vec3(0.0f,  0.0f,  1.0f);
    mObjectColor[20] = glm::vec3(0.0f,  0.0f,  1.0f);

    mObjectColor[21] = glm::vec3(0.0f,  1.0f,  0.0f);
    mObjectColor[22] = glm::vec3(0.0f,  1.0f,  0.0f);
    mObjectColor[23] = glm::vec3(0.0f,  1.0f,  0.0f);

    mObjectColor[24] = glm::vec3(1.0f,  0.0f,  0.0f);
    mObjectColor[25] = glm::vec3(1.0f,  0.0f,  0.0f);
    mObjectColor[26] = glm::vec3(1.0f,  0.0f,  0.0f);

    mObjectColor[27] = glm::vec3(0.0f,  1.0f,  0.0f);
    mObjectColor[28] = glm::vec3(0.0f,  1.0f,  0.0f);
    mObjectColor[29] = glm::vec3(0.0f,  1.0f,  0.0f);

    mObjectColor[30] = glm::vec3(0.0f,  0.0f,  1.0f);
    mObjectColor[31] = glm::vec3(0.0f,  0.0f,  1.0f);
    mObjectColor[32] = glm::vec3(0.0f,  0.0f,  1.0f);

    mObjectColor[33] = glm::vec3(1.0f,  0.0f,  0.0f);
    mObjectColor[34] = glm::vec3(1.0f,  0.0f,  0.0f);
    mObjectColor[35] = glm::vec3(1.0f,  0.0f,  0.0f);
}
