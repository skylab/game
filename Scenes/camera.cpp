#include "camera.h"

Camera::Camera() : mCameraPosition(0.0f, 0.0f, 0.0f), mCameraOrientation(0.0f, 0.0f, 0.0f)
{
    glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f);
    SetCameraPosition(position);

    glm::vec3 orientation = glm::vec3(0.0f, 0.0f, 0.0f);
    SetCameraOrientation(orientation);

    glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
    SetCameraUp(up);

    float viewAngle = 90.0f;
    SetCameraViewAngle(viewAngle);

    float aspectRatio = 4.0/3.0f;
    SetCameraViewAspectRatio(aspectRatio);

    float unitFrom = 0.1f;
    SetCameraUnitFrom(unitFrom);

    float unitTo = 100.0f;
    SetCameraUnitTo(unitTo);

    /*
    float horizontalAngle = 3.14f;
    SetCameraHorizontalOrientation(horizontalAngle);

    float verticalAngle = 0.0f;
    SetCameraVerticalOrientation(verticalAngle);
    */

    float speed = 3.0f;
    SetMouseSpeed(speed);

}

Camera::~Camera()
{
    ;
}

void Camera::SetCameraPosition(glm::vec3 &position)
{
    mCameraPosition = position;
}

const glm::vec3 &Camera::GetCameraPosition() const
{
    return mCameraPosition;
}

void Camera::SetCameraOrientation(glm::vec3 &orientation)
{
    mCameraOrientation = orientation;
}

const glm::vec3 &Camera::GetCameraOrientation() const
{
    return mCameraOrientation;
}

void Camera::SetCameraUp(glm::vec3 &up)
{
    mCameraUp = up;
}

const glm::vec3 &Camera::GetCameraUp() const
{
    return mCameraUp;
}
/*
void Camera::SetCameraHorizontalOrientation(float &angle)
{
    mCameraHorizontalOrientation = angle;
}

const float &Camera::GetCameraHorizontalOrientation() const
{
    return mCameraHorizontalOrientation;
}

void Camera::SetCameraVerticalOrientation(float &angle)
{
    mCameraVerticalOrientation = angle;
}

const float &Camera::GetCameraVerticalOrientation() const
{
    return mCameraVerticalOrientation;
}
*/
void Camera::SetCameraViewAngle(float &angle)
{
    mCameraViewAngle = angle;
}

const float &Camera::GetCameraViewAngle() const
{
    return mCameraViewAngle;
}

void Camera::SetCameraViewAspectRatio(float &value)
{
    mCameraViewAspectRatio = value;
}

const float &Camera::GetCameraViewAspectRatio(void) const
{
    return mCameraViewAspectRatio;
}

void Camera::SetCameraUnitFrom(float &from)
{
    mCameraUnitFrom = from;
}

const float &Camera::GetCameraUnitFrom() const
{
    return mCameraUnitFrom;
}

void Camera::SetCameraUnitTo(float &to)
{
    mCameraUnitTo = to;
}

const float &Camera::GetCameraUnitTo() const
{
    return mCameraUnitTo;
}

const glm::mat4 &Camera::GetProjectionViewModelMatrix()
{
    mProjectionMatrix = glm::perspective(GetCameraViewAngle(),
                                         GetCameraViewAspectRatio(),
                                         GetCameraUnitFrom(), // See from distanse
                                         GetCameraUnitTo()); // See to distanse

    mViewMatrix = glm::lookAt(GetCameraPosition(),
                              GetCameraOrientation(),
                              GetCameraUp()); // Up vector - where is up

    mModelMatrix = glm::mat4(1.0f);

    mProjectioViewModelMatrix = mProjectionMatrix * mModelMatrix * mViewMatrix;

    return mProjectioViewModelMatrix;
}

void Camera::SetMouseSpeed(float &speed)
{
    mMouseSpeed = speed;
}

const float &Camera::GetMouseSpeed() const
{
    return mMouseSpeed;
}


