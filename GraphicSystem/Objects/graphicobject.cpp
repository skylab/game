#include "graphicobject.h"

#include "../Shaders/shadermanager.h"

GraphicObject::~GraphicObject()
{
    glDeleteBuffers(1, &GetVertexBufferObject());
}

GLuint &GraphicObject::GetVertexBufferObject()
{
    return mVertexBufferObject;
}

void GraphicObject::SetVertexBufferObject(GLuint &vertexBufferObject)
{
    mVertexBufferObject = vertexBufferObject;
}

void GraphicObject::LoadObjectToGraphicMemory()
{
    glBindBuffer(GL_ARRAY_BUFFER, GetVertexBufferObject());
    glBufferData(GL_ARRAY_BUFFER, (GetObjectVertexQuantity() * sizeof(glm::vec3)), GetObjectVertexes(), GL_STREAM_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void GraphicObject::SetShaderProgramm(const char *vertexShader, const char *fragmenShader)
{
    mShaderProgramm = ShaderManager::Instance()->GetShaderProgramm(vertexShader, fragmenShader);
}

const ShaderProgram *GraphicObject::GetShaderProgramm() const
{
    return mShaderProgramm;
}

void GraphicObject::FillAsCube()
{
    glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f);
    SetObjectScale(scale);

    SetObjectVertexQuantity(36);
    mObjectVertexes = new (std::nothrow) glm::vec3[GetObjectVertexQuantity()];

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

GraphicObject::GraphicObject() : ObjectRaw(), mVertexBufferObject(0), mShaderProgramm(nullptr)
{
    //Set Default Shader
    SetShaderProgramm("Resources/Shaders/VertexShader.vsh",
                      "Resources/Shaders/FragmentShader.fsh");

    //
    glGenBuffers(1, &mVertexBufferObject);
}
