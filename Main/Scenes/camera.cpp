#include "camera.h"

#include "../scenemanager.h"

Camera::Camera() : mCameraPosition(0.0f, 0.0f, 0.0f), mCameraDirection(0.0f, 0.0f, 0.0f), mCameraUp(0.0f, 1.0f, 0.0f)
{
    float viewAngle = 90.0f;
    SetCameraViewAngle(viewAngle);

    float aspectRatio = 4.0/3.0f;
    SetCameraViewAspectRatio(aspectRatio);

    float unitFrom = 0.1f;
    SetCameraUnitFrom(unitFrom);

    float unitTo = 100.0f;
    SetCameraUnitTo(unitTo);
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

void Camera::SetCameraDirection(glm::vec3 &direction)
{
    mCameraDirection = direction;
}

const glm::vec3 &Camera::GetCameraDirection() const
{
    return mCameraDirection;
}

void Camera::SetCameraUp(glm::vec3 &up)
{
    mCameraUp = up;
}

const glm::vec3 &Camera::GetCameraUp() const
{
    return mCameraUp;
}

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
                              GetCameraDirection(),
                              GetCameraUp()); // Up vector - where is up

    mModelMatrix = glm::mat4(1.0f);

    mProjectioViewModelMatrix = mProjectionMatrix * mModelMatrix * mViewMatrix;

    return mProjectioViewModelMatrix;
}

void Camera::ProcessCursorPosition(double &xpos, double &ypos)
{
    //TODO Camera rotation
    int sceneWidth = SceneManager::Instance()->GetWindowWidth();
    int sceneHeight = SceneManager::Instance()->GetWindowHeight();

    float offsetX = ((float)sceneWidth/2.0f) - xpos;
    float offsetY = ((float)sceneHeight/2.0f) - ypos;

    glfwSetCursorPos(const_cast<GLFWwindow*>(SceneManager::Instance()->GetWindow()), sceneWidth/2.0, sceneHeight/2.0);

    //std::cerr << offsetX << " " << offsetY << std::endl;

    //Gradus to radian
    float angleX = offsetX/180.0*3.14;
    float angleY = offsetY/180.0*3.14;

    //std::cerr << angleX << " " << angleY << std::endl;

    glm::vec3 rot(GetCameraDirection().x - angleX, GetCameraDirection().y + angleY, GetCameraDirection().z);
    SetCameraDirection(rot);
}


void Camera::ProcessButtonPress(int &key)
{
    //TODO camera moving;
    switch(key)
    {
    case GLFW_KEY_W:
        break;
    case GLFW_KEY_S:
        break;
    }
}

