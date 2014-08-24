#include "objectabs.h"

ObjectAbs::ObjectAbs() throw() :
    mVertexVBO(0), mColorVBO(0), mObjectVertexes(NULL), mObjectColor(NULL), mVertexQuantity(0), mVertexArraySize(0)
{
    ;
}

ObjectAbs::~ObjectAbs()
{
    ;
}

GLuint &ObjectAbs::GetVertexVBO()
{
    return mVertexVBO;
}

GLuint &ObjectAbs::GetColorVBO()
{
    return mColorVBO;
}

const GLfloat *ObjectAbs::GetVertexes()
{
    if (NULL != mObjectVertexes)
    {
        return *mObjectVertexes;
    }
    return NULL;
}

const GLfloat *ObjectAbs::GetColor()
{
    if (NULL != mObjectColor)
    {
        return *mObjectColor;
    }
    return NULL;
}

const GLuint &ObjectAbs::GetVertexArraySize()
{
    mVertexArraySize = mVertexQuantity * sizeof(Vertex3f);
    return mVertexArraySize;
}

const GLuint &ObjectAbs::GetVertexQuantity()
{
    return mVertexQuantity;
}
