#include "cameraobject.h"

#include "../scenemanager.h"

CameraObject::CameraObject() : mCameraUp(0.0f, 1.0f, 0.0f)
{
    SetCameraViewAngle(90.0f);
    SetCameraViewAspectRatio(4.0f/3.0f);
    SetCameraUnitFrom(0.1f);
    SetCameraUnitTo(100.0f);

    SetDrawObject(false);
    SetCanHaveObjectList(false);
}

CameraObject::~CameraObject()
{
    ;
}

void CameraObject::SetCameraUp(glm::vec3 up)
{
    mCameraUp = up;
}

const glm::vec3 &CameraObject::GetCameraUp() const
{
    return mCameraUp;
}

void CameraObject::SetCameraViewAngle(float angle)
{
    mCameraViewAngle = angle;
}

const float &CameraObject::GetCameraViewAngle() const
{
    return mCameraViewAngle;
}

void CameraObject::SetCameraViewAspectRatio(float value)
{
    mCameraViewAspectRatio = value;
}

const float &CameraObject::GetCameraViewAspectRatio(void) const
{
    return mCameraViewAspectRatio;
}

void CameraObject::SetCameraUnitFrom(float from)
{
    mCameraUnitFrom = from;
}

const float &CameraObject::GetCameraUnitFrom() const
{
    return mCameraUnitFrom;
}

void CameraObject::SetCameraUnitTo(float to)
{
    mCameraUnitTo = to;
}

const float &CameraObject::GetCameraUnitTo() const
{
    return mCameraUnitTo;
}

const glm::mat4 &CameraObject::GetProjectionViewModelMatrix()
{
    mProjectionMatrix = glm::perspective(GetCameraViewAngle(),
                                         GetCameraViewAspectRatio(),
                                         GetCameraUnitFrom(), // See from distanse
                                         GetCameraUnitTo()); // See to distanse

    mViewMatrix = glm::lookAt(GetObjectPosition(),
                              GetObjectRotation(),
                              GetCameraUp()); // Up vector - where is up

    mModelMatrix = glm::mat4(1.0f);

    mProjectioViewModelMatrix = mProjectionMatrix * mModelMatrix * mViewMatrix;

    return mProjectioViewModelMatrix;
}

void CameraObject::ProcessCursorPosition(double &xpos, double &ypos)
{
    //TODO CameraObject rotation
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

    glm::vec3 rot(GetObjectRotation().x - angleX, GetObjectRotation().y + angleY, GetObjectRotation().z);
    SetObjectRotation(rot);
}


void CameraObject::ProcessButtonPress(int &key)
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
