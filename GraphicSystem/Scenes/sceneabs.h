#ifndef SCENEABS_H
#define SCENEABS_H

#include "../pregraphic.h"

#include "../Objects/objectabs.h"
#include "../Shaders/shaderprogram.h"

#include <list>

class SceneAbs
{
public:
    SceneAbs(GLuint VAO) throw();
    ~SceneAbs() throw();

    void DrawScene() const throw();

    bool getIsStarted() const throw();
    void setIsStarted(bool value) throw();


private:
    ShaderProgram *mShaderProgram;
    GLuint &mVAO;
    GLuint mVBO;

    GLint Attrib_vertex;
    GLint Unif_color, Unif_PVM;

    ObjectAbs *mObj;

    bool mIsStarted;

    glm::mat4 PVM, Projection, View, Model;
};

#endif // SCENEABS_H
