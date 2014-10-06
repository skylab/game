#ifndef CAMERA_H
#define CAMERA_H

#include "../Common/precommon.h"

class Camera
{
public:
    Camera();
    virtual ~Camera();

    virtual void SetCameraPosition(glm::vec3 &position);
    virtual const glm::vec3 &GetCameraPosition(void) const;

    virtual void SetCameraDirection(glm::vec3 &direction);
    virtual const glm::vec3 &GetCameraDirection(void) const;

    ///
    virtual void SetCameraUp(glm::vec3 &up);
    virtual const glm::vec3 &GetCameraUp(void) const;
    ///

    virtual void SetCameraViewAngle(float &angle);
    virtual const float &GetCameraViewAngle(void) const;

    virtual void SetCameraViewAspectRatio(float &aspectRatio);
    virtual const float &GetCameraViewAspectRatio(void) const;

    virtual void SetCameraUnitFrom(float &from);
    virtual const float &GetCameraUnitFrom(void) const;

    virtual void SetCameraUnitTo(float &to);
    virtual const float &GetCameraUnitTo(void) const;

    virtual const glm::mat4 &GetProjectionViewModelMatrix(void);

    virtual void SetCameraSideSpeed(float &speed);
    virtual const float &GetCameraSideSpeed(void) const;

    virtual void ProcessCursorPosition(double &xpos, double &ypos);
    virtual void ProcessButtonPress(int &key);

private:
    glm::vec3 mCameraPosition;    
    glm::vec3 mCameraDirection;
    glm::vec3 mCameraUp;

    float CharacterHeight;

    float mCameraViewAngle; // 90
    float mCameraViewAspectRatio; // 16/9
    float mCameraUnitFrom; // Distanses of view
    float mCameraUnitTo;

    glm::mat4 mProjectionMatrix;
    glm::mat4 mViewMatrix;
    glm::mat4 mModelMatrix;
    glm::mat4 mProjectioViewModelMatrix;

    float mCameraSideSpeed;
};

#endif // CAMERA_H
