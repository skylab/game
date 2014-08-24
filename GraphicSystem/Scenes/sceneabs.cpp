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

    //mObj = new (std::nothrow) ObjectTriangle;
    mObj = new (std::nothrow) ObjectCube;

    glGenBuffers(1, &mObj->GetVisualBufferObject());
    glBindBuffer(GL_ARRAY_BUFFER, mObj->GetVisualBufferObject());
    glBufferData(GL_ARRAY_BUFFER, mObj->GetVertexArraySize(), *mObj, GL_STREAM_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

/*
    const char* attr_name = "coord";
    Attrib_vertex = mShaderProgram->GetAttribute(attr_name);
    if(Attrib_vertex == -1)
    {
        setIsStarted(false);
        return;
    }
*/
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

    /*
    const char* unif_name = "color";
    Unif_color = mShaderProgram->GetUniform(unif_name);
    if(Unif_color == -1)
    {
        setIsStarted(false);
        return;
    }
    */

    ////
    ///
    GLfloat g_color_buffer_data[] = {
        1.0f,  0.0f,  0.0f,
        1.0f,  0.0f,  0.0f,
        1.0f,  0.0f,  0.0f,

        0.0f,  1.0f,  0.0f,
        0.0f,  1.0f,  0.0f,
        0.0f,  1.0f,  0.0f,

        0.0f,  0.0f,  1.0f,
        0.0f,  0.0f,  1.0f,
        0.0f,  0.0f,  1.0f,

        0.0f,  1.0f,  0.0f,
        0.0f,  1.0f,  0.0f,
        0.0f,  1.0f,  0.0f,

        0.0f,  0.0f,  1.0f,
        0.0f,  0.0f,  1.0f,
        0.0f,  0.0f,  1.0f,

        1.0f,  0.0f,  0.0f,
        1.0f,  0.0f,  0.0f,
        1.0f,  0.0f,  0.0f,

        0.0f,  0.0f,  1.0f,
        0.0f,  0.0f,  1.0f,
        0.0f,  0.0f,  1.0f,

        0.0f,  1.0f,  0.0f,
        0.0f,  1.0f,  0.0f,
        0.0f,  1.0f,  0.0f,

        1.0f,  0.0f,  0.0f,
        1.0f,  0.0f,  0.0f,
        1.0f,  0.0f,  0.0f,

        0.0f,  1.0f,  0.0f,
        0.0f,  1.0f,  0.0f,
        0.0f,  1.0f,  0.0f,

        0.0f,  0.0f,  1.0f,
        0.0f,  0.0f,  1.0f,
        0.0f,  0.0f,  1.0f,

        1.0f,  0.0f,  0.0f,
        1.0f,  0.0f,  0.0f,
        1.0f,  0.0f,  0.0f,
    };

    glGenBuffers(1, &mVBO);
    glBindBuffer(GL_ARRAY_BUFFER, mVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_color_buffer_data), g_color_buffer_data, GL_STREAM_DRAW);

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

    static GLfloat red[4] = {1.0f, 0.0f, 0.0f, 1.0f};
    glUniform4fv(Unif_color, 1, red);

    glUniformMatrix4fv(Unif_PVM, 1, false, &PVM[0][0]);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, mObj->GetVisualBufferObject());
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, mVBO);
    glVertexAttribPointer(1 /*position in shader*/, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glDrawArrays(GL_TRIANGLES, 0, mObj->GetVertexQuantity());
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glDisableVertexAttribArray(Attrib_vertex);

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

