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

    virtual void SetCameraOrientation(glm::vec3 &orientation);
    virtual const glm::vec3 &GetCameraOrientation(void) const;

    virtual void SetCameraUp(glm::vec3 &up);
    virtual const glm::vec3 &GetCameraUp(void) const;

    /*
    virtual void SetCameraHorizontalOrientation(float &angle);
    virtual const float &GetCameraHorizontalOrientation(void) const;

    virtual void SetCameraVerticalOrientation(float &angle);
    virtual const float &GetCameraVerticalOrientation(void) const;
    */

    virtual void SetCameraViewAngle(float &angle);
    virtual const float &GetCameraViewAngle(void) const;

    virtual void SetCameraViewAspectRatio(float &aspectRatio);
    virtual const float &GetCameraViewAspectRatio(void) const;

    virtual void SetCameraUnitFrom(float &from);
    virtual const float &GetCameraUnitFrom(void) const;

    virtual void SetCameraUnitTo(float &to);
    virtual const float &GetCameraUnitTo(void) const;

    virtual const glm::mat4 &GetProjectionViewModelMatrix(void);

    virtual void SetMouseSpeed(float &speed);
    virtual const float &GetMouseSpeed(void) const;

private:
    glm::vec3 mCameraPosition;
    glm::vec3 mCameraOrientation;
    glm::vec3 mCameraUp;

    /*
    float mCameraHorizontalOrientation;
    float mCameraVerticalOrientation;
    */

    float mCameraViewAngle;
    float mCameraViewAspectRatio;
    float mCameraUnitFrom; // Distanses of view
    float mCameraUnitTo;

    glm::mat4 mProjectionMatrix;
    glm::mat4 mViewMatrix;
    glm::mat4 mModelMatrix;
    glm::mat4 mProjectioViewModelMatrix;

    float mMouseSpeed;
};

#endif // CAMERA_H
