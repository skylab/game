#include "gamescene.h"

#include "../Objects/objecttriangle.h"
#include "../Objects/objectquad.h"
#include "../Objects/objectcube.h"

GameScene::GameScene() : SceneAbs()
{
    mShaderProgram = new (std::nothrow) ShaderProgram("GraphicSystem/Shaders/VertexShader.vsh",
                                                      "GraphicSystem/Shaders/FragmentShader.fsh");

    if (NULL == mShaderProgram)
    {
        std::cerr << "Can't allocate ShaderProgram" << std::endl;
    }

    mObjQuantity = 2;
    mObj = new (std::nothrow) ObjectAbs*[mObjQuantity];

    for (GLuint i = 0; i < mObjQuantity; ++i)
    {
        mObj[i] = new (std::nothrow) ObjectCube(glm::vec3(i*3, 0, 0));
        glGenBuffers(1, &mObj[i]->GetVertexVBO());
        glBindBuffer(GL_ARRAY_BUFFER, mObj[i]->GetVertexVBO());
        glBufferData(GL_ARRAY_BUFFER, mObj[i]->GetVertexArraySize(), mObj[i]->GetVertexes(), GL_STREAM_DRAW);
        glBindBuffer(GL_ARRAY_BUFFER, 0);

        glGenBuffers(1, &mObj[i]->GetColorVBO());
        glBindBuffer(GL_ARRAY_BUFFER, mObj[i]->GetColorVBO());
        glBufferData(GL_ARRAY_BUFFER, mObj[i]->GetVertexArraySize(), mObj[i]->GetColor(), GL_STREAM_DRAW);
    }

    const char* unif_name= "PVM";
    Unif_PVM = mShaderProgram->GetUniform(unif_name);

    unif_name = "ObjectSize";
    mObjectScaleUniform = mShaderProgram->GetUniform(unif_name);
    unif_name = "ObjectPosition";
    mObjectCoordinateUniform = mShaderProgram->GetUniform(unif_name);
    unif_name = "ObjectRotation";
    mObjectRotationAnglesUniform = mShaderProgram->GetUniform(unif_name);

    Projection = glm::perspective(90.0f, 4.0f / 3.0f, 0.1f, 100.0f);
    View       = glm::lookAt(
                glm::vec3(2,2,4), // Camera is at (4,3,-3), in World Space
                glm::vec3(0,0,0), // and looks at the origin
                glm::vec3(0,1,0)  // Head is up (set to 0,-1,0 to look upside-down)
                );
    Model      = glm::mat4(1.0f);

    PVM  = Projection * View * Model;

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
}

void GameScene::DrawScene()
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.2f, 0.3f, 0.4f, 1);

    glUseProgram(*mShaderProgram);

    PVM  = Projection * View * Model;

    glUniformMatrix4fv(Unif_PVM, 1, false, &PVM[0][0]);


    for (GLuint i = 0; i < mObjQuantity; ++i)
    {
        glUniform3fv(mObjectScaleUniform, 1, (GLfloat*)&mObj[i]->GetScale());
        glUniform3fv(mObjectCoordinateUniform, 1, (GLfloat*)&mObj[i]->GetPosition());
        glUniform3fv(mObjectRotationAnglesUniform, 1, (GLfloat*)&mObj[i]->GetRotations());

        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, mObj[i]->GetVertexVBO());
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

        glEnableVertexAttribArray(1);
        glBindBuffer(GL_ARRAY_BUFFER, mObj[i]->GetColorVBO());
        glVertexAttribPointer(1 /*position in shader*/, 3, GL_FLOAT, GL_FALSE, 0, 0);

        glDrawArrays(GL_TRIANGLES, 0, mObj[i]->GetVertexQuantity());
        glBindBuffer(GL_ARRAY_BUFFER, 0);

        glDisableVertexAttribArray(0);
        glDisableVertexAttribArray(1);
    }

    glUseProgram(0);

    glutSwapBuffers();
}

void GameScene::KeyBoard(unsigned char &key, int &x, int &y)
{
    static int _x=2;
    static int _y=2;
    static int _z=3;

    static float _ox=0;
    static float _oy=0;
    static float _oz=0;
    switch (key)
    {
    case 'a':
        --_x;
        break;
    case 'd':
        ++_x;
        break;
    case 'w':
        ++_y;
        break;
    case 's':
        --_y;
        break;
    case 'p':
        ++_z;
        break;
    case 'o':
        --_z;
        break;
    case 'l':
        _oy -= 0.01f;
        break;
    case 'k':
        _oy += 0.01f;
        break;
    default:
        SceneAbs::KeyBoard(key, x, y);
        break;
    }
    switch (key)
    {
    case 'a':
    case 'd':
    case 'w':
    case 's':
    case 'p':
    case 'o':
    case 'l':
    case 'k':
        View       = glm::lookAt(
                    glm::vec3(_x,_y,_z), // Camera is at (4,3,-3), in World Space
                    glm::vec3(0,0,0), // and looks at the origin
                    glm::vec3(0,1,0)  // Head is up (set to 0,-1,0 to look upside-down)
                    );        

        for (GLuint i = 0; i < mObjQuantity; ++i)
        {
            mObj[i]->GetRotations() = glm::vec3(_ox, _oy, _oz);
        }
        break;
    }
    DrawScene();
}
