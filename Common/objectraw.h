#ifndef OBJECTRAW_H
#define OBJECTRAW_H

#include "precommon.h"

// Basic class to Object, needed to connection between graphic/physic and another system
class ObjectRaw
{
public:
    virtual ~ObjectRaw();

    virtual bool LoadObjectFromFile(const char *fileName);

    // TODO this is bad idea to use this function as is... rewrite
    virtual glm::vec3 *&GetObjectVertexes(void);

    virtual bool SetObjectVertexQuantity(unsigned long int quantity);
    virtual const size_t &GetObjectVertexQuantity(void) const;

    //Object manipulation finctions
    virtual const glm::mat4 &GetPositionRotationScaleMatrix(void);

    virtual glm::vec3 GetObjectFrontDirection(void);
    virtual glm::vec3 GetObjectUpDirection(void);
    virtual glm::vec3 GetObjectRightDirection(void);

    virtual void SetObjectPosition(glm::vec3 position);
    virtual glm::vec3 GetObjectPosition(void) const;

    virtual void RotateObject(glm::vec3 axisAngle);

    virtual void SetObjectScale(glm::vec3 scale);
    virtual glm::vec3 GetObjectScale(void) const;

    virtual void FixAxis(bool up = false, bool right = false, bool front = false);

    //Child obects functions
    virtual const std::list<ObjectRaw *> &GetChildObjectList(void);
    virtual bool AddChildObject(ObjectRaw *object, glm::vec3 position);

protected:
    ObjectRaw();

//private:
    virtual glm::mat4 GetRotationMatrix(void);

private:
    glm::vec3 *mObjectVertexes;
    size_t mObjectVertexQuantity;

    glm::vec4 mObjectFrontDirection;
    glm::vec4 mObjectRightDirection;
    glm::vec4 mObjectUpDirection;

    glm::vec4 mObjectPosition;
    glm::vec4 mObjectScale;
    glm::quat mObjectRotation; // Rotation in object use quaternion
    struct FixAxis
    {
        bool Up;
        bool Right;
        bool Front;
    } mFixAxis;

    glm::mat4 mPositionRotationScaleMatrix;

    // Depended objects
    std::list<ObjectRaw*> mChildObjectList;
    bool mbCanHaveObjectList;
};

#endif // OBJECTRAW_H
