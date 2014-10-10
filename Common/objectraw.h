#ifndef OBJECTRAW_H
#define OBJECTRAW_H

#include "precommon.h"

// Basic class to Object, needed to connection between graphic/physic and another system
class ObjectRaw
{
public:
    virtual ~ObjectRaw();

    bool LoadObjectFromFile(const char *fileName);

    virtual void SetObjectName(const char *name);
    virtual const char *GetObjectName(void) const;

    virtual glm::vec3 *&GetObjectVertexes(void);

    virtual void SetObjectVertexQuantity(unsigned long int quantity);
    virtual const unsigned long int &GetObjectVertexQuantity(void) const;

    virtual void SetObjectPosition(glm::vec3 &position);
    virtual const glm::vec3 &GetObjectPosition(void) const;

    virtual void SetObjectRotation(glm::vec3 &rotation);
    virtual const glm::vec3 &GetObjectRotation(void) const;

    virtual void SetObjectScale(glm::vec3 &scale);
    virtual const glm::vec3 &GetObjectScale(void) const;

    // Depended objects
    virtual void AddObject(ObjectRaw* object);
    virtual void RemoveObject(ObjectRaw* object);
    virtual void ClearObjectList(void);
    virtual const std::list<ObjectRaw*> &GetObjectList(void) const;
    virtual size_t GetObjectQuantity(void) const;
    virtual void SetCanHaveObjectList(bool val);
    virtual bool GetCanHaveObjectList(void);

protected:
    ObjectRaw();

private:
    char * mObjectFile;
    char * mObjectName;

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
