#include "camera.h"

#include "../Managers/windowmanager.h"

Camera::Camera() :
    mViewAngle(45),
    mViewAspectRatio(16.0f/9.0f),
    mUnitFrom(0.01f),
    mUnitTo(100.0f),

    mFrontDirection(0.0f, 0.0f, -1.0f),
    mUpDirection(0.0f, 1.0f, 0.0f),
    mPosition(0.0f, 0.0f, 1.0f),
    mRotation()
{
    //mRotation = glm::quat();
}

Camera::~Camera()
{
    ;
}

void Camera::SetProsition(glm::vec3 position)
{
    mPosition = position;
}

void Camera::RotatePitch(float degrees)
{
    glm::quat rot;
    rot.x = glm::cross(mFrontDirection, mUpDirection).x * sin(degrees/2);
    rot.y = glm::cross(mFrontDirection, mUpDirection).y * sin(degrees/2);
    rot.z = glm::cross(mFrontDirection, mUpDirection).z * sin(degrees/2);
    rot.w = cos(degrees/2);

    mFrontDirection = rot * mFrontDirection;

    mRotation = rot * mRotation;
    mRotation = glm::normalize(mRotation);
}

void Camera::RotateHeading(float degrees)
{
    glm::quat rot;
    rot.x = mFrontDirection.x * sin(degrees/2);
    rot.y = mFrontDirection.y * sin(degrees/2);
    rot.z = mFrontDirection.z * sin(degrees/2);
    rot.w = cos(degrees/2);

    mFrontDirection = rot * mFrontDirection;

    mRotation = rot * mRotation;
    mRotation = glm::normalize(mRotation);
}

const glm::mat4 &Camera::GetPVMMatrix()
{
    mViewAspectRatio = (float)WindowManager::Instance()->GetWindowWidth()/(float)WindowManager::Instance()->GetWindowHeight();
    // mProjectioViewModelMatrix = Projection * View * Model
    // Model matrix is glm::mat4(1.0f) and can be skipped, because has no affect to use it
    mProjectioViewModelMatrix = glm::perspective(mViewAngle, mViewAspectRatio, mUnitFrom, mUnitTo) *
            glm::lookAt(mPosition, mPosition+ mFrontDirection, mUpDirection);
}

void Camera::SetAspectRatio(float val)
{
    mViewAspectRatio = val;
}
