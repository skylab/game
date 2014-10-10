#include "graphicobject.h"

#include "../Shaders/shadermanager.h"

#include "../../Main/scenemanager.h"

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

void GraphicObject::Draw()
{
    // DRAW THIS OBJECT
    if (GetDrawObject() && nullptr != GetObjectVertexes())
    {
        glUseProgram( GetShaderProgramm()->GetShaderProgrammID() );

        GLuint PVM = const_cast<ShaderProgram*>(GetShaderProgramm())->GetUniform("PVM");

        glUniformMatrix4fv( PVM, 1, false, &((SceneManager::Instance()->GetCurrentScene()->GetSceneCamera()->GetProjectionViewModelMatrix())[0][0]) );

        GLuint scale = const_cast<ShaderProgram*>(GetShaderProgramm())->GetUniform("ObjectSize");
        glUniform3fv(scale, 1, (GLfloat*)&(GetObjectScale()));

        GLuint position = const_cast<ShaderProgram*>(GetShaderProgramm())->GetUniform("ObjectPosition");
        glUniform3fv(position, 1, (GLfloat*)&(GetObjectPosition()));

        GLuint rotation = const_cast<ShaderProgram*>(GetShaderProgramm())->GetUniform("ObjectRotation");
        glUniform3fv(rotation, 1, (GLfloat*)&(GetObjectRotation()));

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
