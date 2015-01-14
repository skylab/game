#ifndef GRAPHICLEVEL_H
#define GRAPHICLEVEL_H

#include "../BaseLevel/baselevel.h"
#include "texture.h"
#include "../../Infra/preinfra.h"
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

    virtual void SetVertexQuantity(unsigned int quantity) override;
    glm::vec3 **GetUVArray(void);

    bool AddTexture(Texture *texture);
    int GetTextureNumberInObject(Texture *texture);

protected:
    void LoadToGraphicMemory(void);

protected:
    Scene *mScene;
    GLuint mVBO; // Vertexes
    GLuint mUVBO; // UV coordinates
    GLuint mSamplerBO;

    ShaderProgramm *mShaderProgramm;    
    glm::mat4 mPVMTranslationRotationScaleMatrix;
    int mDrawPrimitives;

    glm::vec3 *mUV;

    std::vector<Texture *> mTextureList;
};

#endif // GRAPHICLEVEL_H
