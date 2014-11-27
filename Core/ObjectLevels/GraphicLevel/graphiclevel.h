#ifndef GRAPHICLEVEL_H
#define GRAPHICLEVEL_H

#include "../BaseLevel/baselevel.h"
class Scene;
class ShaderProgramm;

class GraphicLevel : virtual public BaseLevel
{
protected:
    GraphicLevel();
    virtual ~GraphicLevel() override;

public:
    virtual void SetScene(Scene *scene);
    virtual void Draw(void);

protected:
    void LoadToGraphicMemory(void);

protected:
    GLuint mVBO;
    Scene *mScene;
    //glm::mat4 GetPosRotScalMatrix(void);

    bool mVisible;
    ShaderProgramm *mShaderProgramm;
    glm::mat4 mPVMTranslationRotationScaleMatrix;
    int mDrawPrimitives;
    char **mTextureName;
};

#endif // GRAPHICLEVEL_H
