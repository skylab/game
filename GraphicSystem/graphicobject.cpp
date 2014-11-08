#include "graphicobject.h"

#include "Shaders/shadermanager.h"
#include "../Main/scenemanager.h"

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

Texture *GraphicObject::GetObjectTexture() const
{
    return mTexture;
}

void GraphicObject::Draw()
{
    // DRAW THIS OBJECT
    if (nullptr != GetObjectVertexes())
    {
        glUseProgram( GetShaderProgramm()->GetShaderProgrammID() );

        GLuint PVMTRSM = const_cast<ShaderProgram*>(GetShaderProgramm())->GetUniform("PVMTranslationRotationScaleMatrix");
        mPVMTranslationRotationScaleMatrix =
                SceneManager::Instance()->GetCurrentScene()->GetCameraObject()->GetProjectionViewModelMatrix() *
                GetPositionRotationScaleMatrix();
        glUniformMatrix4fv( PVMTRSM, 1, false, &mPVMTranslationRotationScaleMatrix[0][0]);

        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, GetVertexBufferObject());
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

        glDrawArrays(GetDrawByPrimitive(), 0, GetObjectVertexQuantity());
        glBindBuffer(GL_ARRAY_BUFFER, 0);

        glDisableVertexAttribArray(0);
        glUseProgram(0);
    }
}

void GraphicObject::SetDrawObject(bool val)
{
    mbDrawObject = val;
}

const bool &GraphicObject::GetDrawObject() const
{
    return mbDrawObject;
}

void GraphicObject::SetDrawByPrimitive(int type)
{
    mDrawByPrimitive = type;
}

int GraphicObject::GetDrawByPrimitive() const
{
    return mDrawByPrimitive;
}

GraphicObject::GraphicObject() : ObjectRaw(), mVertexBufferObject(0), mShaderProgramm(nullptr), mDrawByPrimitive(GL_TRIANGLES), mTexture(nullptr), mbDrawObject(true)
{
    //Set Default Shader
    SetShaderProgramm("Resources/Shaders/VertexShader.vsh",
                      "Resources/Shaders/FragmentShader.fsh");

    glGenBuffers(1, &mVertexBufferObject);

    try
    {
        mTexture = new Texture();
    }
    catch(std::bad_alloc &ba)
    {
        std::cerr << ba.what() << " : Can't allocate texture" << std::endl;
    }
}
