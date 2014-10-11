#ifndef CAMERAOBJECT_H
#define CAMERAOBJECT_H

#include "../object.h"

class CameraObject : public Object
{
public:
    CameraObject();
    virtual ~CameraObject();

    virtual void SetCameraUp(glm::vec3 &up);
    virtual const glm::vec3 &GetCameraUp(void) const;

    virtual void SetCameraViewAngle(float &angle);
    virtual const float &GetCameraViewAngle(void) const;

    virtual void SetCameraViewAspectRatio(float &aspectRatio);
    virtual const float &GetCameraViewAspectRatio(void) const;

    virtual void SetCameraUnitFrom(float &from);
    virtual const float &GetCameraUnitFrom(void) const;

    virtual void SetCameraUnitTo(float &to);
    virtual const float &GetCameraUnitTo(void) const;

    virtual const glm::mat4 &GetProjectionViewModelMatrix(void);

    virtual void ProcessCursorPosition(double &xpos, double &ypos);
    virtual void ProcessButtonPress(int &key);

private:
    glm::vec3 mCameraUp;

    float CharacterHeight;

    // TODO read from config
    float mCameraViewAngle; // 90
    float mCameraViewAspectRatio; // 16/9
    float mCameraUnitFrom; // Distanses of view
    float mCameraUnitTo; // Distanses of view

    glm::mat4 mProjectionMatrix;
    glm::mat4 mViewMatrix;
    glm::mat4 mModelMatrix;
    glm::mat4 mProjectioViewModelMatrix;
};

#endif // CAMERAOBJECT_H
