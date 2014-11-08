#include "camera.h"

#include "../Main/scenemanager.h"

Camera::Camera() : CharacterHeight(0.0f)
{
    SetCameraViewAngle(45.0f);
    SetCameraViewAspectRatio(4.0f/3.0f);
    SetCameraUnitFrom(0.1f);
    SetCameraUnitTo(100.0f);
    LockUpDirection(true);
    SetObjectUpDirection(glm::vec3(0.0f, 1.0f, 0.0f));
    SetObjectFrontDirection(glm::vec3(0.0f, 0.0f, -1.0f));
    SetObjectPosition(glm::vec3(0.0f, 0.0f, 0.0f));

    mMoveSpeed = 0.2777f / 2.0f;
}

Camera::~Camera()
{
    ;
}

void Camera::SetCameraViewAngle(float angle)
{
    mCameraViewAngle = angle;
}

const float &Camera::GetCameraViewAngle() const
{
    return mCameraViewAngle;
}

void Camera::SetCameraViewAspectRatio(float value)
{
    mCameraViewAspectRatio = value;
}

const float &Camera::GetCameraViewAspectRatio(void) const
{
    return mCameraViewAspectRatio;
}

void Camera::SetCameraUnitFrom(float from)
{
    mCameraUnitFrom = from;
}

const float &Camera::GetCameraUnitFrom() const
{
    return mCameraUnitFrom;
}

void Camera::SetCameraUnitTo(float to)
{
    mCameraUnitTo = to;
}

const float &Camera::GetCameraUnitTo() const
{
    return mCameraUnitTo;
}

const glm::mat4 &Camera::GetProjectionViewModelMatrix()
{
    glm::vec3 eyePosition = GetObjectPosition();
    eyePosition.y += CharacterHeight;

    // mProjectioViewModelMatrix = Projection * View * Model
    // Model matrix is glm::mat4(1.0f) and can be skipped, because has no affect to use it
    mProjectioViewModelMatrix = glm::perspective(GetCameraViewAngle(), GetCameraViewAspectRatio(), GetCameraUnitFrom(), GetCameraUnitTo()) *
            glm::lookAt(eyePosition, GetObjectPosition() + GetObjectFrontDirection(), GetObjectUpDirection());

    return mProjectioViewModelMatrix;
}

void Camera::ProcessCursorPosition(double &xpos, double &ypos)
{
    //TODO Camera rotation
    int sceneWidth = SceneManager::Instance()->GetWindowManager()->GetWindowWidth();
    int sceneHeight = SceneManager::Instance()->GetWindowManager()->GetWindowHeight();

    float offsetX = ((float)sceneWidth/2.0f) - xpos;
    float offsetY = ((float)sceneHeight/2.0f) - ypos;

    SceneManager::Instance()->GetWindowManager()->SetCursorPosition(sceneWidth/2, sceneHeight/2);

    RotateHeading(offsetX / 1000.0f);
    RotatePitch(offsetY / 1000.0f);
}


void Camera::NotifyKeyEvent(void)
{
    glm::vec3 dir;

    if (Key::W.Press() || Key::W.Repeat())
    {
        dir += GetObjectFrontDirection();
    }
    if (Key::S.Press() || Key::S.Repeat())
    {
        dir -= GetObjectFrontDirection();
    }
    if (Key::A.Press() || Key::A.Repeat())
    {
        dir -= glm::normalize(glm::cross(GetObjectFrontDirection(), GetObjectUpDirection()));
    }
    if (Key::D.Press() || Key::D.Repeat())
    {
        dir += glm::normalize(glm::cross(GetObjectFrontDirection(), GetObjectUpDirection()));
    }
    if (Key::SPACE.Press() || Key::SPACE.Repeat())
    {
        dir += GetObjectUpDirection();
    }
    if (Key::LEFT_CONTROL.Press() || Key::LEFT_CONTROL.Repeat())
    {
        dir -= GetObjectUpDirection();
    }

    if (dir.x != 0.0f ||
            dir.y != 0.0f ||
            dir.z != 0.0f)
    {
        dir = glm::normalize(dir);
        dir *= mMoveSpeed;
        MoveToDirection(dir);
    }
}
