#include "mainscene.h"

MainScene::MainScene()
{
    GameObject * obj = new GameObject();
    glm::vec3 pos = glm::vec3(0.0f, 0.0f, 0.0f);
    AddObject(obj, pos);    

    glm::vec3 position = glm::vec3(2.0f, 2.0f, 4.0f);
    GetSceneCamera().SetCameraPosition(position);

    glm::vec3 direction = glm::vec3(0.0f, 0.0f, 0.0f);
    GetSceneCamera().SetCameraDirection(direction);

    float viewAngle = 90.0f;
    GetSceneCamera().SetCameraViewAngle(viewAngle);

    SetProcessCursorAsCamera(true);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
}

MainScene::~MainScene()
{
    ;
}

/*
void MainScene::Draw(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glClearColor(0.2f, 0.3f, 0.4f, 1); // Background color

    std::list<ObjectRaw*>::iterator itr;
    for (itr = GetObjectList().begin(); itr != GetObjectList().end(); ++itr)
    {
        GraphicObject *object = nullptr;
        try
        {
            object = dynamic_cast<GraphicObject*>(*itr);
        }
        catch(std::bad_cast &bc)
        {
            // TODO
            (void)bc;

            // skip bad cast
            continue;
        }

        // Additional check
        if (nullptr == object)
            continue;

        glUseProgram( object->GetShaderProgramm()->GetShaderProgrammID() );

        GLuint PVM = const_cast<ShaderProgram*>(object->GetShaderProgramm())->GetUniform("PVM");
        glUniformMatrix4fv( PVM, 1, false, &((GetSceneCamera().GetProjectionViewModelMatrix())[0][0]) );

        GLuint scale = const_cast<ShaderProgram*>(object->GetShaderProgramm())->GetUniform("ObjectSize");
        glUniform3fv(scale, 1, (GLfloat*)&(object->GetObjectScale()));

        GLuint position = const_cast<ShaderProgram*>(object->GetShaderProgramm())->GetUniform("ObjectPosition");
        glUniform3fv(position, 1, (GLfloat*)&(object->GetObjectPosition()));

        GLuint rotation = const_cast<ShaderProgram*>(object->GetShaderProgramm())->GetUniform("ObjectRotation");
        glUniform3fv(rotation, 1, (GLfloat*)&(object->GetObjectRotation()));

        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, object->GetVertexBufferObject());
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

        glDrawArrays(GL_TRIANGLES, 0, object->GetObjectVertexQuantity());
        glBindBuffer(GL_ARRAY_BUFFER, 0);

        glDisableVertexAttribArray(0);
        glUseProgram(0);
    }
}
*/

void MainScene::Keyboard(int &key)
{
    switch(key)
    {
    case GLFW_KEY_LEFT:
        for (std::list<Object*>::const_iterator itr = GetObjectList().begin(); itr != GetObjectList().end(); ++itr)
        {
            glm::vec3 vec = (*itr)->GetObjectRotation();
            vec.y +=0.1f;
            (*itr)->SetObjectRotation(vec);
        }
        break;
    case GLFW_KEY_RIGHT:
        for (std::list<Object*>::const_iterator itr = GetObjectList().begin(); itr != GetObjectList().end(); ++itr)
        {
            glm::vec3 vec = (*itr)->GetObjectRotation();
            vec.y -=0.1f;
            (*itr)->SetObjectRotation(vec);
        }
        break;
    default:
        SceneAbs::Keyboard(key);
    }
}

void MainScene::MousePosition(double &xpos, double &ypos)
{
    SceneAbs::MousePosition(xpos, ypos);
}
