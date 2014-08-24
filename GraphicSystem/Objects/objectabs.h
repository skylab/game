#ifndef OBJECTABS_H
#define OBJECTABS_H

#include "../pregraphic.h"

class ObjectAbs
{
public:
    ObjectAbs() throw();
    ~ObjectAbs();

    GLuint &GetVisualBufferObject();

    const GLuint &GetVertexArraySize();
    const GLuint &GetVertexQuantity();

    //operator GLvoid*();
    operator GLfloat*();

protected:
    GLuint mVBO;
    Vertex3f *mObjectVertexes;
    GLuint mVertexQuantity;
    GLuint mVertexArraySize;
};

#endif // OBJECTABS_H
