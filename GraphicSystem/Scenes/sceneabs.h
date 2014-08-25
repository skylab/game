#ifndef SCENEABS_H
#define SCENEABS_H

#include "../pregraphic.h"

#include "../Objects/objectabs.h"
#include "../Shaders/shaderprogram.h"

#include <list>

class SceneAbs
{
public:
    SceneAbs();
    virtual ~SceneAbs() = 0;

    virtual void DrawScene();
    virtual void KeyBoard(unsigned char &key, int &x, int &y);

    void ChangeScene(SceneAbs *scene);

protected:
    ShaderProgram *mShaderProgram;

    GLint Unif_PVM;

    GLint mObjectScaleUniform;
    GLint mObjectCoordinateUniform;

    ObjectAbs **mObj;
    GLuint mObjQuantity;

    glm::mat4 PVM, Projection, View, Model;
};

#endif // SCENEABS_H
