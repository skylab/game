#include "camera.h"

#include "../Main/scenemanager.h"

Camera::Camera() : CharacterHeight(0.0f)
{
    SetCameraViewAngle(45.0f);
    SetCameraViewAspectRatio(4.0f/3.0f);
    SetCameraUnitFrom(0.1f);
    SetCameraUnitTo(100.0f);

    SetCameraDirection(glm::vec3(0.0f, 0.0f, -1.0f));
    SetCameraUp(glm::vec3(0.0f, 1.0f, 0.0f));
    SetCameraMoveSpeed(0.1f);

    mCameraPosition = glm::vec3(0.0f, 0.0f, 0.0f);
    mCameraRotation = glm::quat();
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

void Camera::SetCameraMoveSpeed(float speed)
{
    mCameraMoveSpeed = speed;
}

const float &Camera::GetCameraMoveSpeed() const
{
    return mCameraMoveSpeed;
}

const glm::mat4 &Camera::GetProjectionViewModelMatrix()
{
    glm::vec3 eyePosition = GetPosition();
    eyePosition.y += CharacterHeight;

    // mProjectioViewModelMatrix = Projection * View * Model
    // Model matrix is glm::mat4(1.0f) and can be skipped, because has no affect to use it
   mProjectioViewModelMatrix = glm::perspective(GetCameraViewAngle(), GetCameraViewAspectRatio(), GetCameraUnitFrom(), GetCameraUnitTo()) *
                               glm::lookAt(eyePosition, GetPosition() + GetCameraDirection(), GetCameraUp());

   return mProjectioViewModelMatrix;
}

void Camera::SetPosition(glm::vec3 position)
{
    mCameraPosition = position;
}

const glm::vec3 &Camera::GetPosition() const
{
    return mCameraPosition;
}

void Camera::SetCameraDirection(glm::vec3 direction)
{
    mCameraDirection = direction;
    mCameraDirection = glm::normalize(mCameraDirection);
}

const glm::vec3 &Camera::GetCameraDirection() const
{
    return mCameraDirection;
}

void Camera::SetCameraUp(glm::vec3 up)
{
    mCameraUp = up;
    mCameraUp = glm::normalize(mCameraUp);
}

const glm::vec3 &Camera::GetCameraUp() const
{
    return mCameraUp;
}

void Camera::MoveToDirectin(MoveDirection direction)
{
    switch(direction)
    {
    case FORWARD:
        SetPosition(GetPosition() + GetCameraDirection() * GetCameraMoveSpeed());
        break;
    case BACK:
        SetPosition(GetPosition() - GetCameraDirection() * GetCameraMoveSpeed());
        break;
    case LEFT:
        SetPosition(GetPosition() - glm::cross(GetCameraDirection(), GetCameraUp()) * GetCameraMoveSpeed());
        break;
    case RIGHT:
        SetPosition(GetPosition() + glm::cross(GetCameraDirection(), GetCameraUp()) * GetCameraMoveSpeed());
        break;
    case UP:
        SetPosition(GetPosition() + GetCameraUp() * GetCameraMoveSpeed());
        break;
    case DOWN:
        SetPosition(GetPosition() - GetCameraUp() * GetCameraMoveSpeed());
        break;
    }
}

void Camera::RotatePitch(float degrees)
{
    glm::quat rot;
    rot.x = glm::cross(GetCameraDirection(), GetCameraUp()).x * sin(degrees/2);
    rot.y = glm::cross(GetCameraDirection(), GetCameraUp()).y * sin(degrees/2);
    rot.z = glm::cross(GetCameraDirection(), GetCameraUp()).z * sin(degrees/2);
    rot.w = cos(degrees/2);

    SetCameraDirection(rot * GetCameraDirection());

    mCameraRotation = rot * mCameraRotation;
}

void Camera::RotateHeading(float degrees)
{
    glm::quat rot;
    rot.x = GetCameraUp().x * sin(degrees/2);
    rot.y = GetCameraUp().y * sin(degrees/2);
    rot.z = GetCameraUp().z * sin(degrees/2);
    rot.w = cos(degrees/2);

    SetCameraDirection(rot * GetCameraDirection());

    mCameraRotation = rot * mCameraRotation;
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

    //std::cerr << angleX << " " << angleY << std::endl;
}


void Camera::ProcessButtonPress(int &key, int &scancode, int &action, int &mods)
{
    std::cerr << "Addr2 " << &Key::PRESS << std::endl;
    std::cerr << (int)Key::Instance()->PRESS << " " << (int)Key::PRESS << " " << key << std::endl;

    if (Key::PRESS == action || Key::REPEAT == action)
    {
        if (Key::W == key)
            MoveToDirectin(FORWARD);
        if (Key::S == key)
            MoveToDirectin(BACK);
        if (Key::A == key)
            MoveToDirectin(LEFT);
        if (Key::D == key)
            MoveToDirectin(RIGHT);

        /*
            break;
        case GLFW_KEY_1:
            MoveToDirectin(UP);
            break;
        case GLFW_KEY_2:
            MoveToDirectin(DOWN);
            break;
        }
        */
    }
}
