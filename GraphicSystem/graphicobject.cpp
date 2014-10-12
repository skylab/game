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

bool GraphicObject::LoadObjectFromFile(const char *fileName)
{
    ObjectRaw::LoadObjectFromFile(fileName);
    LoadObjectToGraphicMemory();
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

void GraphicObject::Draw()
{
    // DRAW THIS OBJECT
    if (GetDrawObject() && nullptr != GetObjectVertexes())
    {
        glUseProgram( GetShaderProgramm()->GetShaderProgrammID() );

        GLuint PVMTRSM = const_cast<ShaderProgram*>(GetShaderProgramm())->GetUniform("PVMTranslationRotationScaleMatrix");
        mPVMTranslationRotationScaleMatrix =
                SceneManager::Instance()->GetCurrentScene()->GetCameraObject()->GetProjectionViewModelMatrix() *
                glm::translate(glm::mat4(1.0f), GetObjectPosition()) *
                glm::rotate(glm::mat4(1.0f), GetObjectRotation().x, glm::vec3(1.0f, 0.0f, 0.0f)) *
                glm::rotate(glm::mat4(1.0f), GetObjectRotation().y, glm::vec3(0.0f, 1.0f, 0.0f)) *
                glm::rotate(glm::mat4(1.0f), GetObjectRotation().z, glm::vec3(0.0f, 0.0f, 1.0f)) *
                glm::scale(glm::mat4(1.0f), GetObjectScale());
        glUniformMatrix4fv( PVMTRSM, 1, false, &mPVMTranslationRotationScaleMatrix[0][0]);

        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, GetVertexBufferObject());
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

        glDrawArrays(GL_TRIANGLES, 0, GetObjectVertexQuantity());
        glBindBuffer(GL_ARRAY_BUFFER, 0);

        glDisableVertexAttribArray(0);
        glUseProgram(0);
    }

    // DRAW ALL ANOTHER OBJECTS
    for (std::list<ObjectRaw*>::const_iterator itr = GetObjectList().begin(); itr != GetObjectList().end(); ++itr)
    {
        GraphicObject *object = nullptr;
        try
        {
            object = dynamic_cast<GraphicObject*>(*itr);
        }
        catch(std::bad_cast &bc)
        {
            (void)bc;
            // skip bad cast, object have not graphic part
        }
        if (nullptr != (*itr))
        {
            object->Draw();
        }
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

GraphicObject::GraphicObject() : ObjectRaw(), mVertexBufferObject(0), mShaderProgramm(nullptr), mbDrawObject(true)
{
    //Set Default Shader
    SetShaderProgramm("Resources/Shaders/VertexShader.vsh",
                      "Resources/Shaders/FragmentShader.fsh");

    glGenBuffers(1, &mVertexBufferObject);
}
