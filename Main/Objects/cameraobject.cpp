#include "cameraobject.h"

#include "../scenemanager.h"

CameraObject::CameraObject()
{
    SetCameraViewAngle(90.0f);
    SetCameraViewAspectRatio(4.0f/3.0f);
    SetCameraUnitFrom(0.1f);
    SetCameraUnitTo(100.0f);

    SetDrawObject(false);
    //SetCanHaveObjectList(false);

    //FixAxis(false, true, false);
}

CameraObject::~CameraObject()
{
    ;
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
                              GetObjectPosition() + GetObjectFrontDirection(),
                              GetObjectUpDirection()); // Up vector - where is up

    mModelMatrix = glm::mat4(1.0f);

    mProjectioViewModelMatrix = mProjectionMatrix * mModelMatrix * mViewMatrix;

    return mProjectioViewModelMatrix;
}

void CameraObject::ProcessCursorPosition(double &xpos, double &ypos)
{
    //TODO CameraObject rotation
    int sceneWidth = SceneManager::Instance()->GetWindowManager()->GetWindowWidth();
    int sceneHeight = SceneManager::Instance()->GetWindowManager()->GetWindowHeight();

    float offsetX = ((float)sceneWidth/2.0f) - xpos;
    float offsetY = ((float)sceneHeight/2.0f) - ypos;

    SceneManager::Instance()->GetWindowManager()->SetCursorPosition(sceneWidth/2, sceneHeight/2);

    //std::cerr << offsetX << " " << offsetY << std::endl;

    //Gradus to radian
    float angleX = offsetX;
    float angleY = offsetY;

    //angleX /= 180.0*3.14;
    //angleY /= 180.0*3.14;
    angleX /= 10;
    angleY /= 10;

    RotateObject(glm::vec3(angleY, angleX, 0.0f));
    //std::cerr << angleX << " " << angleY << std::endl;
}


void CameraObject::ProcessButtonPress(int &key, int &scancode, int &action, int &mods)
{
    if(GLFW_PRESS == action || GLFW_REPEAT == action)
    {
        switch(key)
        {
        case GLFW_KEY_W:
            SetObjectPosition(GetObjectPosition() + (GetObjectFrontDirection() * 0.01f));
            break;
        case GLFW_KEY_S:
            SetObjectPosition(GetObjectPosition() - (GetObjectFrontDirection() * 0.01f));
            break;
        }
    }
}
