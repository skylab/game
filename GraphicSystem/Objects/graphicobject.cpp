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

    GetObjectVertexes()[0] = glm::vec3(-1.0f, 1.0f, 1.0f); // Front
    GetObjectVertexes()[1] = glm::vec3(-1.0f, -1.0f, 1.0f);
    GetObjectVertexes()[2] = glm::vec3(1.0f, 1.0f, 1.0f);

    GetObjectVertexes()[3] = glm::vec3(1.0f, 1.0f, 1.0f);
    GetObjectVertexes()[4] = glm::vec3(1.0f, -1.0f, 1.0f);
    GetObjectVertexes()[5] = glm::vec3(-1.0f, -1.0f, 1.0f); // End front

    GetObjectVertexes()[6] = glm::vec3(-1.0f, 1.0f, -1.0f); // back
    GetObjectVertexes()[7] = glm::vec3(-1.0f, -1.0f, -1.0f);
    GetObjectVertexes()[8] = glm::vec3(1.0f, 1.0f, -1.0f);

    GetObjectVertexes()[9] =  glm::vec3(1.0f, 1.0f, -1.0f);
    GetObjectVertexes()[10] = glm::vec3(1.0f, -1.0f, -1.0f);
    GetObjectVertexes()[11] = glm::vec3(-1.0f, -1.0f, -1.0f); // End back


    GetObjectVertexes()[12] = glm::vec3(1.0f, 1.0f, -1.0f); // right
    GetObjectVertexes()[13] = glm::vec3(1.0f, -1.0f, -1.0f);
    GetObjectVertexes()[14] = glm::vec3(1.0f, 1.0f, 1.0f);

    GetObjectVertexes()[15] = glm::vec3(1.0f, 1.0f, 1.0f);
    GetObjectVertexes()[16] = glm::vec3(1.0f, -1.0f, 1.0f);
    GetObjectVertexes()[17] = glm::vec3(1.0f, -1.0f, -1.0f); // End right

    GetObjectVertexes()[18] = glm::vec3(-1.0f, 1.0f, -1.0f); // left
    GetObjectVertexes()[19] = glm::vec3(-1.0f, -1.0f, -1.0f);
    GetObjectVertexes()[20] = glm::vec3(-1.0f, 1.0f, 1.0f);

    GetObjectVertexes()[21] = glm::vec3(-1.0f, 1.0f, 1.0f);
    GetObjectVertexes()[22] = glm::vec3(-1.0f, -1.0f, 1.0f);
    GetObjectVertexes()[23] = glm::vec3(-1.0f, -1.0f, -1.0f); // End left

    GetObjectVertexes()[24] = glm::vec3(1.0f, -1.0f, -1.0f); // down
    GetObjectVertexes()[25] = glm::vec3(-1.0f, -1.0f, -1.0f);
    GetObjectVertexes()[26] = glm::vec3(1.0f, -1.0f, 1.0f);

    GetObjectVertexes()[27] = glm::vec3(1.0f, -1.0f, 1.0f);
    GetObjectVertexes()[28] = glm::vec3(-1.0f, -1.0f, 1.0f);
    GetObjectVertexes()[29] = glm::vec3(-1.0f, -1.0f, -1.0f); // End down

    GetObjectVertexes()[30] = glm::vec3(1.0f, 1.0f, -1.0f); // up
    GetObjectVertexes()[31] = glm::vec3(-1.0f, 1.0f, -1.0f);
    GetObjectVertexes()[32] = glm::vec3(1.0f, 1.0f, 1.0f);

    GetObjectVertexes()[33] = glm::vec3(1.0f, 1.0f, 1.0f);
    GetObjectVertexes()[34] = glm::vec3(-1.0f, 1.0f, 1.0f);
    GetObjectVertexes()[35] = glm::vec3(-1.0f, 1.0f, -1.0f); // End up

    /////////////Color
}

GraphicObject::GraphicObject() : ObjectRaw(), mVertexBufferObject(0), mShaderProgramm(nullptr)
{
    //Set Default Shader
    SetShaderProgramm("Resources/Shaders/VertexShader.vsh",
                      "Resources/Shaders/FragmentShader.fsh");

    //
    glGenBuffers(1, &mVertexBufferObject);
}
