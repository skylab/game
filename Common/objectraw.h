#ifndef OBJECTRAW_H
#define OBJECTRAW_H

#include "precommon.h"

class Command;

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

    virtual const glm::vec3 &GetObjectFrontDirection(void);
    virtual const glm::vec3 &GetObjectUpDirection(void);
    virtual const glm::vec3 &GetObjectRightDirection(void);

    virtual void SetObjectPosition(glm::vec3 position);
    virtual glm::vec3 GetObjectPosition(void) const;

    //Change the pitch (up, down) for the free camera
    virtual void ChangePitch(float degrees);
    //Change heading (left, right) for the free camera
    virtual void ChangeHeading(float degrees);
    //Change the heading and pitch of the camera based on the 2d movement of the mouse
    virtual void Move2D(int x, int y);

    virtual void SetObjectScale(glm::vec3 scale);
    virtual glm::vec3 GetObjectScale(void) const;

    //Child obects functions
    virtual void SetSupportChildList(bool val);
    virtual bool GetSupportChildList(void) const;

    void SetCanBeChild(bool val);
    bool GetCanBeChild(void) const;
    virtual const std::list<ObjectRaw *> &GetChildObjectList(void);
    virtual bool AddChildObject(ObjectRaw *object, glm::vec3 position);
    void RemoveChilds(void);

    //To work with commands
    virtual void Accept(Command *command);

protected:
    ObjectRaw();

//private:
    virtual glm::mat4 GetRotationMatrix(void);

private:
    glm::vec3 *mObjectVertexes;
    size_t mObjectVertexQuantity;

    float mObjectPitch;
    float mObjectHeading;

    glm::vec4 mObjectFrontDirection;
    glm::vec4 mObjectRightDirection;
    glm::vec4 mObjectUpDirection;

    glm::vec4 mObjectPosition;
    glm::vec4 mObjectScale;
    glm::quat mObjectRotation; // Rotation in object use quaternion

    glm::mat4 mPositionRotationScaleMatrix;

    // Depended objects
    bool mbCanBeChild;
    bool mbSupportChildList;
    std::list<ObjectRaw*> mChildObjectList;
};

#endif // OBJECTRAW_H
