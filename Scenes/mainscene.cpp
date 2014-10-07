#include "mainscene.h"

MainScene::MainScene()
{
    Object * obj = new Object;
    //obj->FillAsCube();
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

void MainScene::Draw(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.2f, 0.3f, 0.4f, 1);

    std::list<Object*>::const_iterator itr = GetObjectList().begin();
    for (GLuint i = 0; i < GetObjectQuantity() && itr != GetObjectList().end(); ++i, ++itr)
    {
        glUseProgram( (*itr)->GetShaderProgramm()->GetShaderProgrammID() );

        GLuint PVM = const_cast<ShaderProgram*>((*itr)->GetShaderProgramm())->GetUniform("PVM");
        glUniformMatrix4fv( PVM, 1, false, &((GetSceneCamera().GetProjectionViewModelMatrix())[0][0]) );

        GLuint scale = const_cast<ShaderProgram*>((*itr)->GetShaderProgramm())->GetUniform("ObjectSize");
        glUniform3fv( scale, 1, (GLfloat*)&((*itr)->GetObjectScale()) );

        GLuint position = const_cast<ShaderProgram*>((*itr)->GetShaderProgramm())->GetUniform("ObjectPosition");
        glUniform3fv(position, 1, (GLfloat*)&((*itr)->GetObjectPosition()));

        GLuint rotation = const_cast<ShaderProgram*>((*itr)->GetShaderProgramm())->GetUniform("ObjectRotation");
        glUniform3fv(rotation, 1, (GLfloat*)&((*itr)->GetObjectRotation()));

        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, (*itr)->GetVertexBufferObject());
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

        glDrawArrays(GL_TRIANGLES, 0, (*itr)->GetObjectVertexQuantity());
        glBindBuffer(GL_ARRAY_BUFFER, 0);

        glDisableVertexAttribArray(0);
        glUseProgram(0);
    }
}

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
        Scene::Keyboard(key);
    }
}

void MainScene::MousePosition(double &xpos, double &ypos)
{
    Scene::MousePosition(xpos, ypos);
}
