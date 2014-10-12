#ifndef OBJECTRAW_H
#define OBJECTRAW_H

#include "precommon.h"

// Basic class to Object, needed to connection between graphic/physic and another system
class ObjectRaw
{
public:
    virtual ~ObjectRaw();

    virtual bool LoadObjectFromFile(const char *fileName);

    virtual glm::vec3 *&GetObjectVertexes(void);

    virtual bool SetObjectVertexQuantity(unsigned long int quantity);
    virtual const unsigned long int &GetObjectVertexQuantity(void) const;

    virtual void SetObjectPosition(float x = 0, float y = 0, float z = 0);
    virtual const glm::vec3 &GetObjectPosition(void) const;

    virtual void RotateObject(float x, float y, float z, float angle = 0);
    virtual const glm::vec3 &GetObjectRotation(void);

    virtual void SetObjectScale(float x = 0, float y = 0, float z = 0);
    virtual const glm::vec3 &GetObjectScale(void) const;

    // Depended objects
    virtual void AddObject(ObjectRaw* object, glm::vec3 position);
    virtual void RemoveObject(ObjectRaw* object);
    virtual void ClearObjectList(void);
    virtual const std::list<ObjectRaw*> &GetObjectList(void) const;
    virtual size_t GetObjectQuantity(void) const;

    virtual void SetCanHaveObjectList(bool val);
    virtual bool GetCanHaveObjectList(void);

protected:
    ObjectRaw();

private:
    glm::vec3 *mObjectVertexes;
    unsigned long int mObjectVertexQuantity;

    glm::vec3 mObjectPosition;
    glm::vec3 mObjectRotation;
    glm::vec3 mObjectScale;

    // Depended objects
    std::list<ObjectRaw*> mObjectList;
    bool mbCanHaveObjectList;
};

#endif // OBJECTRAW_H
