#include "objectabs.h"

ObjectAbs::ObjectAbs(glm::vec3 position) throw() :
    mVertexVBO(0), mColorVBO(0), mObjectVertexes(NULL), mObjectColor(NULL), mVertexQuantity(0), mVertexArraySize(0), mPosition(position)
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

const glm::vec3 *ObjectAbs::GetVertexes()
{
    if (NULL != mObjectVertexes)
    {
        return mObjectVertexes;
    }
    return NULL;
}

const glm::vec3 *ObjectAbs::GetColor()
{
    if (NULL != mObjectColor)
    {
        return mObjectColor;
    }
    return NULL;
}

const GLuint &ObjectAbs::GetVertexArraySize()
{
    mVertexArraySize = mVertexQuantity * sizeof(glm::vec3);
    return mVertexArraySize;
}

const GLuint &ObjectAbs::GetVertexQuantity()
{
    return mVertexQuantity;
}

glm::vec3 &ObjectAbs::Position()
{
    return mPosition;
}
