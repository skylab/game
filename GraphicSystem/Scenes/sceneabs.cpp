#include "sceneabs.h"

#include "../Objects/objecttriangle.h"
#include "../Objects/objectquad.h"
#include "../Objects/objectcube.h"

SceneAbs::SceneAbs(GLuint VAO) throw() :
    mShaderProgram(NULL), mVAO(VAO), mVBO(0), mIsStarted(true)
{
    mShaderProgram = new (std::nothrow) ShaderProgram();

    // TODO SET SHADER CODE:

    if (NULL == mShaderProgram)
    {
        std::cerr << "Can't allocate ShaderProgram" << std::endl;
        setIsStarted(false);
    }

    mObjQuantity = 2;
    mObj = new (std::nothrow) ObjectAbs*[mObjQuantity];

    for (GLuint i = 0; i < mObjQuantity; ++i)
    {
        mObj[i] = new (std::nothrow) ObjectCube(glm::vec3(i*2, i*2, i*2));
        glGenBuffers(1, &mObj[i]->GetVertexVBO());
        glBindBuffer(GL_ARRAY_BUFFER, mObj[i]->GetVertexVBO());
        glBufferData(GL_ARRAY_BUFFER, mObj[i]->GetVertexArraySize(), mObj[i]->GetVertexes(), GL_STREAM_DRAW);
        glBindBuffer(GL_ARRAY_BUFFER, 0);

        glGenBuffers(1, &mObj[i]->GetColorVBO());
        glBindBuffer(GL_ARRAY_BUFFER, mObj[i]->GetColorVBO());
        glBufferData(GL_ARRAY_BUFFER, mObj[i]->GetVertexArraySize(), mObj[i]->GetColor(), GL_STREAM_DRAW);
    }

    const char* unif_name_pvm = "PVM";
    Unif_PVM = mShaderProgram->GetUniform(unif_name_pvm);
    if(Unif_PVM == -1)
    {
        setIsStarted(false);
        //return;
    }

    Projection = glm::perspective(90.0f, 4.0f / 3.0f, 0.1f, 100.0f);
    View       = glm::lookAt(
                glm::vec3(2,2,3), // Camera is at (4,3,-3), in World Space
                glm::vec3(0,0,0), // and looks at the origin
                glm::vec3(0,1,0)  // Head is up (set to 0,-1,0 to look upside-down)
                );
    Model      = glm::mat4(1.0f);
    PVM        = Projection * View * Model;

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
}

SceneAbs::~SceneAbs() throw()
{
    delete mShaderProgram;
}

void SceneAbs::DrawScene() const throw()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.2f, 0.3f, 0.4f, 1);

    glUseProgram(*mShaderProgram);

    glUniformMatrix4fv(Unif_PVM, 1, false, &PVM[0][0]);

    for (GLuint i = 0; i < mObjQuantity; ++i)
    {
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
bool SceneAbs::getIsStarted() const throw()
{
    return mIsStarted;
}

void SceneAbs::setIsStarted(bool value) throw()
{
    mIsStarted = value;
}

