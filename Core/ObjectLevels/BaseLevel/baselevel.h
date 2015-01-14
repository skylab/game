#ifndef BASELEVEL_H
#define BASELEVEL_H

#include "../../coreconfig.h"
#include "../../Infra/preinfra.h"

class BaseLevel
{
protected:
    BaseLevel();
    virtual ~BaseLevel();

public:
    glm::vec3 **GetVertexArray(void);

    virtual void SetVertexQuantity(unsigned int quantity);
    unsigned int GetVertexArrayQuantity(void) const;

    const glm::mat4 &GetPositionRotationScaleMatrix(void);

private:
    glm::mat4 GetRotationMatrix(void);
    glm::mat4 mPositionRotationScaleMatrix;

protected:
    glm::vec3 *mVertex;
    unsigned int mVertexQuantity;

    glm::vec3 mPosition;
    glm::quat mRotation;
    glm::vec3 mScale;
};

#endif // BASELEVEL_H
