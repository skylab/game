#ifndef OBJECTABS_H
#define OBJECTABS_H

#include "../pregraphic.h"

class ObjectAbs
{
public:
    ObjectAbs() throw();
    ~ObjectAbs();

    GLuint &GetVertexVBO();
    GLuint &GetColorVBO();

    const GLfloat *GetVertexes();
    const GLfloat *GetColor();

    const GLuint &GetVertexArraySize();
    const GLuint &GetVertexQuantity();

protected:
    GLuint mVertexVBO;
    GLuint mColorVBO;
    Vertex3f *mObjectVertexes;
    Vertex3f *mObjectColor;
    GLuint mVertexQuantity;
    GLuint mVertexArraySize;
};

#endif // OBJECTABS_H
