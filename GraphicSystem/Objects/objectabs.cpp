#include "objectabs.h"

ObjectAbs::ObjectAbs() throw() : mObjectVertexes(NULL), mVertexQuantity(0), mVertexArraySize(0)
{
    ;
}

ObjectAbs::~ObjectAbs()
{
    ;
}

GLuint &ObjectAbs::GetVisualBufferObject()
{
    return mVBO;
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

ObjectAbs::operator GLfloat *()
{
    if (NULL != mObjectVertexes)
    {
        return *mObjectVertexes;
    }
    return NULL;
}
