#include "objectabs.h"

ObjectAbs::ObjectAbs(glm::vec3 position) :
    mVertexVBO(0), mColorVBO(0), mObjectVertexes(NULL),
    mObjectColor(NULL), mVertexQuantity(0), mVertexArraySize(0),
    mObjectCoordinate(position)
{
    mObjectScale = glm::vec3(1.0f, 1.0f, 1.0f);
    mObjectRotation = glm::vec3(0.0f, 0.0f, 0.0f);
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

glm::vec3 &ObjectAbs::GetScale()
{
    return mObjectScale;
}

glm::vec3 &ObjectAbs::GetPosition()
{
    return mObjectCoordinate;
}

glm::vec3 &ObjectAbs::GetRotations()
{
    return mObjectRotation;
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
