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
    virtual ~SceneAbs();

    virtual void DrawScene() const;

    virtual void KeyBoard(unsigned char &key, int &x, int &y);

    bool getIsStarted() const;
    void setIsStarted(bool value);

    void ChangeScene(SceneAbs *scene);
    SceneAbs **GetCurrentScene() const;

protected:
    ShaderProgram *mShaderProgram;
    GLuint mVBO;

    GLint Attrib_vertex;
    GLint Unif_color, Unif_PVM;

    ObjectAbs **mObj;
    GLuint mObjQuantity;

    bool mIsStarted;

    glm::mat4 PVM, Projection, View, Model;
};

#endif // SCENEABS_H
