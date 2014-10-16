#ifndef OBJECTRAW_H
#define OBJECTRAW_H

#include "precommon.h"

class Command;

enum MoveDirection
{
    FORWARD,
    BACK,
    LEFT,
    RIGHT,
    UP,
    DOWN
};

// Basic class to Object, needed to connection between graphic/physic and another system
class ObjectRaw
{
public:
    virtual ~ObjectRaw();
    virtual bool LoadObjectFromFile(const char *fileName);

    bool SetObjectVertexQuantity(unsigned long int quantity);
    const size_t &GetObjectVertexQuantity(void) const;
    // TODO this is bad idea to use this function as is... rewrite
    glm::vec3 *&GetObjectVertexes(void);

    //Object manipulation finctions
    void MoveObject(enum MoveDirection direction);

    void SetObjectMoveSpeed(float speed);
    float GetObjectMoveSpeed(void) const;

    void SetObjectFrontDirection(glm::vec3 direction);
    glm::vec3 GetObjectFrontDirection(void);
    void SetObjectUpDirection(glm::vec3 direction);
    glm::vec3 GetObjectUpDirection(void);

    virtual void RotatePitch(float degrees);
    virtual void RotateHeading(float degrees);


    void SetObjectPosition(glm::vec3 position);
    glm::vec3 GetObjectPosition(void) const;
    void SetObjectScale(glm::vec3 scale);
    glm::vec3 GetObjectScale(void) const;

    // Final of calculation
    const glm::mat4 &GetPositionRotationScaleMatrix(void);

    // Child obects functions
    void SetCanBeChild(bool val);
    bool GetCanBeChild(void) const;
    void SetSupportChildList(bool val);
    bool GetSupportChildList(void) const;
    const std::list<ObjectRaw *> &GetChildObjectList(void);
    bool AddChildObject(ObjectRaw *object, glm::vec3 position);
    void RemoveChilds(void);

    // To work with commands
    virtual void Accept(Command *command);

protected:
    ObjectRaw();

protected:
    glm::quat mObjectRotation; // Rotation in object use quaternion


private:
    glm::mat4 GetRotationMatrix(void);

    glm::vec3 *mObjectVertexes;
    size_t mObjectVertexQuantity;

    float mObjectPitch;
    float mObjectHeading;
    float mObjectMoveSpeed;

    glm::vec3 mObjectFrontDirection;
    glm::vec3 mObjectUpDirection;

    glm::vec3 mObjectPosition;
    glm::vec3 mObjectScale;

    glm::mat4 mPositionRotationScaleMatrix;

    // Depended objects
    bool mbCanBeChild;
    bool mbSupportChildList;
    std::list<ObjectRaw*> mChildObjectList;
};

#endif // OBJECTRAW_H
