#include "camera.h"

#include "../Managers/windowmanager.h"
#include "../Infra/timer.h"

Camera::Camera() :
    mViewAngle(45),
    mViewAspectRatio(16.0f/9.0f),
    mUnitFrom(0.01f),
    mUnitTo(100.0f),

    // km/h -> m/s
    // km/h * 1000 / 3600
    // Default move speed is 7km/h
    mMoveSpeedMS(0.2777f * 15.0f),
    mLastTimerPointMs(Timer::GetCurrentTimeMs().count()),

    mFrontDirection(0.0f, 0.0f, -1.0f),
    mUpDirection(0.0f, 1.0f, 0.0f),
    mPosition(0.0f, 0.0f, 1.0f),
    mRotation()
{
    ;
}

Camera::~Camera()
{
    ;
}

void Camera::NotifyMousePosition(int &x, int &y)
{
    int sceneWidth = WindowManager::Instance()->GetWindowWidth();
    int sceneHeight = WindowManager::Instance()->GetWindowHeight();

    float offsetX = ((float)sceneWidth/2.0f) - x;
    float offsetY = ((float)sceneHeight/2.0f) - y;

    WindowManager::Instance()->SetCursorPosition(sceneWidth/2, sceneHeight/2);

    RotateHeading(offsetX / 1000.0f);
    RotatePitch(offsetY / 1000.0f);
}

void Camera::CheckKeys()
{
    glm::vec3 moveDir(0.0f, 0.0f, 0.0f);
    if (Key::W.Press())
    {
        moveDir += mFrontDirection;
    }
    if (Key::A.Press())
    {
        moveDir -= glm::cross(mFrontDirection, mUpDirection);
    }
    if (Key::S.Press())
    {
        moveDir -= mFrontDirection;
    }
    if (Key::D.Press())
    {
         moveDir += glm::cross(mFrontDirection, mUpDirection);
    }
    if (Key::Space.Press())
    {
         moveDir += mUpDirection;
    }
    if (Key::LCtrl.Press())
    {
         moveDir -= mUpDirection;
    }

    if (0.0f != moveDir.x || 0.0f != moveDir.y || 0.0f != moveDir.z)
    {
        // Normalize move direction in according to movement by diagonal)
        moveDir = glm::normalize(moveDir);

        // Use move speed to movement
        float deltaTime = ((float)(Timer::GetCurrentTimeMs().count() - mLastTimerPointMs) / 1000.0f);
        mPosition += (deltaTime * mMoveSpeedMS) * moveDir;
    }

    // Last check time to use move speed;
    mLastTimerPointMs = Timer::GetCurrentTimeMs().count();
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
    rot.x = mUpDirection.x * sin(degrees/2);
    rot.y = mUpDirection.y * sin(degrees/2);
    rot.z = mUpDirection.z * sin(degrees/2);
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
    return mProjectioViewModelMatrix = glm::perspective(mViewAngle, mViewAspectRatio, mUnitFrom, mUnitTo) *
            glm::lookAt(mPosition, mPosition+ mFrontDirection, mUpDirection);
}

void Camera::SetAspectRatio(float val)
{
    mViewAspectRatio = val;
}
