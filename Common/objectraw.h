#ifndef OBJECTRAW_H
#define OBJECTRAW_H

#include "precommon.h"

class Command;

// Basic class to Object, needed to connection between graphic/physic and another system
class ObjectRaw
{
public:
    virtual ~ObjectRaw();

    bool SetObjectVertexQuantity(unsigned long int quantity);
    const size_t &GetObjectVertexQuantity(void) const;
    // TODO this is bad idea to use this function as is... rewrite
    glm::vec3 *&GetObjectVertexes(void);

    //Object manipulation finctions
    //void MoveObject(enum MoveDirection direction); // Move to Object

    void SetObjectFrontDirection(glm::vec3 direction); // Move to protected
    glm::vec3 GetObjectFrontDirection(void);
    void SetObjectUpDirection(glm::vec3 direction);
    glm::vec3 GetObjectUpDirection(void);

    void LockUpDirection(bool val);
    bool GetLockUpDirection(void) const;

    virtual void RotatePitch(float degrees);
    virtual void RotateHeading(float degrees);

    virtual void SetObjectPosition(glm::vec3 position);
    glm::vec3 GetObjectPosition(void) const;
    void SetObjectScale(glm::vec3 scale);
    glm::vec3 GetObjectScale(void) const;

    void MoveToDirection(enum MoveDirection direction);
    void MoveToDirection(glm::vec3 direction);

    // Final of calculation
    const glm::mat4 &GetPositionRotationScaleMatrix(void); // Move to private

protected:
    ObjectRaw();

protected:
    glm::quat mObjectRotation; // Rotation in object use quaternion
    bool mLockedUp;

    // TODO : move to private
    // m/s
    float mMoveSpeed;

private:
    glm::mat4 GetRotationMatrix(void);

    glm::vec3 *mObjectVertexes;
    size_t mObjectVertexQuantity;

    glm::vec3 mObjectFrontDirection;
    glm::vec3 mObjectUpDirection;

    glm::vec3 mObjectPosition;
    glm::vec3 mObjectScale;


    glm::mat4 mPositionRotationScaleMatrix;
};

#endif // OBJECTRAW_H
