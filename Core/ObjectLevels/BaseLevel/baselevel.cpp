#include "baselevel.h"

BaseLevel::BaseLevel() :
    mVertex(nullptr),
    mVertexQuantity(0),
    mPosition(0.0f, 0.0f, 0.0f),
    mRotation(),
    mScale(1.0f,1.0f,1.0f)
{
    ;
}

BaseLevel::~BaseLevel()
{
    if (nullptr != mVertex)
    {
        delete[] mVertex;
        mVertex = nullptr;
    }
    mVertexQuantity = 0;
}

glm::vec3 **const BaseLevel::GetVertexArray()
{
    return &mVertex;
}

void BaseLevel::SetVertexQuantity(unsigned int quantity)
{
    if (quantity > 0)
    {
        try
        {
            mVertex = new glm::vec3[quantity];
            mVertexQuantity = quantity;
        }
        catch(std::bad_alloc &ba)
        {
            std::cerr << __PRETTY_FUNCTION__ << ba.what() << std::endl;
            mVertexQuantity = 0;
        }
    }
}

unsigned int BaseLevel::GetVertexArrayQuantity() const
{
    return mVertexQuantity;
}

const glm::mat4 &BaseLevel::GetPositionRotationScaleMatrix()
{
    mPositionRotationScaleMatrix = glm::translate(glm::mat4(1.0f), mPosition);
    mPositionRotationScaleMatrix *= GetRotationMatrix();
    mPositionRotationScaleMatrix *= glm::scale(glm::mat4(1.0f), mScale);
    return mPositionRotationScaleMatrix;
}

glm::mat4 BaseLevel::GetRotationMatrix()
{
    return glm::mat4_cast(mRotation);
}
