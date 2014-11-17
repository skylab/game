#ifndef GRAPHICOBJECT_H
#define GRAPHICOBJECT_H

#include "pregraphic.h"
#include "Testure/texture.h"

class ShaderProgram;

class GraphicObject : virtual public ObjectRaw
{
public:
    virtual ~GraphicObject();

    virtual GLuint &GetVertexBufferObject(void);
    virtual void SetVertexBufferObject(GLuint &vertexBufferObject);

    virtual void SetShaderProgramm(const char *vertexShader, const char *fragmenShader);
    virtual const ShaderProgram *GetShaderProgramm(void) const;

    void SetObjectTextureName(const char *name);
    Texture *GetObjectTexture(void) const;

    virtual void Draw(void);

    void SetDrawObject(bool val);
    const bool &GetDrawObject(void) const;

    void SetDrawByPrimitive(int type);
    int GetDrawByPrimitive(void) const;

    virtual void LoadObjectToGraphicMemory(void);
protected:
    GraphicObject();

private:
    GLuint mVertexBufferObject;
    int mDrawByPrimitive;
    ShaderProgram *mShaderProgramm;
    glm::mat4 mPVMTranslationRotationScaleMatrix;
    //Texture *mTexture;
    bool mbDrawObject;
    char *mTextureName;
};

#endif // GRAPHICOBJECT_H
