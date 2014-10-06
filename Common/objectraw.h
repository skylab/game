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

protected:
    ObjectRaw();

private:
    char * mObjectFile;
    char * mObjectName;

    //FOR TESTS
//public:
    glm::vec3 *mObjectVertexes;
private:

    unsigned long int mObjectVertexQuantity;

    glm::vec3 mObjectPosition;
    glm::vec3 mObjectRotation;
    glm::vec3 mObjectScale;
};

#endif // OBJECTRAW_H
