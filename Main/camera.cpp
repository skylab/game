#include "camera.h"

#include "../Main/scenemanager.h"

Camera::Camera()
{
    SetCameraViewAngle(45.0f);
    SetCameraViewAspectRatio(4.0f/3.0f);
    SetCameraUnitFrom(0.1f);
    SetCameraUnitTo(100.0f);

    SetObjectPosition(glm::vec3(0.0f, 0.0f, 0.0f));

    SetCanBeChild(false);
    SetDrawObject(false);
    SetSupportChildList(false);
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
    // mProjectioViewModelMatrix = Projection * View * Model
    // Model matrix is glm::mat4(1.0f) and can be skipped, because has no affect to use it
   mProjectioViewModelMatrix = glm::perspective(GetCameraViewAngle(), GetCameraViewAspectRatio(), GetCameraUnitFrom(), GetCameraUnitTo()) *
                               glm::lookAt(GetObjectPosition(), GetObjectPosition() + GetObjectFrontDirection(), GetObjectUpDirection());

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

    //std::cerr << offsetX << " " << offsetY << std::endl;

    //Gradus to radian
    float angleX = offsetX;
    float angleY = offsetY;

    angleX /= 10;
    angleY /= 10;

    RotateHeading(angleY);
    RotatePitch(angleX);

    //std::cerr << angleX << " " << angleY << std::endl;
}


void Camera::ProcessButtonPress(int &key, int &scancode, int &action, int &mods)
{
    if(GLFW_PRESS == action || GLFW_REPEAT == action)
    {
        switch(key)
        {
        case GLFW_KEY_W:
            MoveObject(FORWARD);
            break;
        case GLFW_KEY_S:
            MoveObject(BACK);
            break;
        case GLFW_KEY_1:
            MoveObject(UP);
            break;
        case GLFW_KEY_2:
            MoveObject(DOWN);
            break;
        }
    }
}
