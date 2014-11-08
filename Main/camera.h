#ifndef CAMERA_H
#define CAMERA_H

#include "../Common/precommon.h"
#include "../Common/objectraw.h"
#include "keylistener.h"

class Camera : public ObjectRaw, public KeyListener
{
public:
    Camera();
    ~Camera();

    void SetCameraViewAngle(float angle);
    const float &GetCameraViewAngle(void) const;
    void SetCameraViewAspectRatio(float aspectRatio);
    const float &GetCameraViewAspectRatio(void) const;
    void SetCameraUnitFrom(float from);
    const float &GetCameraUnitFrom(void) const;
    void SetCameraUnitTo(float to);
    const float &GetCameraUnitTo(void) const;


    const glm::mat4 &GetProjectionViewModelMatrix(void);

    void ProcessCursorPosition(double &xpos, double &ypos);
    void NotifyKeyEvent(void) override;

private:
    float CharacterHeight;

    //float mCameraRotationSpeed;

    // TODO read from config
    float mCameraViewAngle; // 45
    float mCameraViewAspectRatio; // 16/9
    float mCameraUnitFrom; // Distanses of view
    float mCameraUnitTo; // Distanses of view

    glm::mat4 mProjectioViewModelMatrix;
};

#endif // CAMERA_H
