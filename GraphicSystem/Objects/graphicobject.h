#ifndef GRAPHICOBJECT_H
#define GRAPHICOBJECT_H

#include "../pregraphic.h"

class ShaderProgram;

class GraphicObject : virtual public ObjectRaw
{
public:
    virtual ~GraphicObject();

    virtual GLuint &GetVertexBufferObject(void);
    virtual void SetVertexBufferObject(GLuint &vertexBufferObject);

    virtual void LoadObjectToGraphicMemory(void);

    virtual void SetShaderProgramm(const char *vertexShader, const char *fragmenShader);
    virtual const ShaderProgram *GetShaderProgramm(void) const;

    virtual void Draw(void);

    void SetDrawObject(bool val);
    const bool &GetDrawObject(void) const;

protected:
    GraphicObject();

private:
    GLuint mVertexBufferObject;
    ShaderProgram *mShaderProgramm;

    bool mbDrawObject;
};

#endif // GRAPHICOBJECT_H
