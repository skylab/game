#ifndef OBJECT_H
#define OBJECT_H

#include "premain.h"

#include "../GraphicSystem/graphicobject.h"

class Object : public GraphicObject
{
protected:

public:
    Object();
    virtual ~Object() override;

    bool LoadObjectMesh(const char *filename);
    bool LoadObjectTexture(const char *filename);

    // Basic unit is meter. Basic time is second
    // km/h -> m/s as 1000/3600.
    // 1 km/h -> m/s = 1000/3600 = 10/36 = 0.2(7)
    void SetObjectMoveSpeed(float speed);
    float GetObjectMoveSpeed(void) const;

    void AddDerivedObject(Object *object);
    void RemoveDerivedObject(Object *object);

    void LoadObjectToGraphicMemory(void) override;

    virtual void SetObjectPosition(glm::vec3 position) override;

    virtual void RotatePitch(float degrees) override;
    virtual void RotateHeading(float degrees) override;

    void Draw(void);

private:
    float mMoveSpeed;

    std::list<Object*> mDerivedObjects;
};

#endif // OBJECT_H
