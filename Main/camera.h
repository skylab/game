#ifndef CAMERA_H
#define CAMERA_H

#include "../Common/precommon.h"
#include "keylistener.h"

class Camera : public KeyListener
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

    void SetCameraMoveSpeed(float speed);
    const float &GetCameraMoveSpeed(void) const;

    const glm::mat4 &GetProjectionViewModelMatrix(void);

    void SetPosition(glm::vec3 position);
    const glm::vec3 &GetPosition(void) const;
    void SetCameraDirection(glm::vec3 direction);
    const glm::vec3 &GetCameraDirection(void) const;
    void SetCameraUp(glm::vec3 up);
    const glm::vec3 &GetCameraUp(void) const;
    void MoveToDirectin(enum MoveDirection direction);
    void RotatePitch(float degrees);
    void RotateHeading(float degrees);

    void ProcessCursorPosition(double &xpos, double &ypos);
    void NotifyKey(KeyInfo *key, ActionInfo *action, int &mods) override;

private:
    float CharacterHeight;
    float mCameraMoveSpeed;
    //float mCameraRotationSpeed;

    // TODO read from config
    float mCameraViewAngle; // 45
    float mCameraViewAspectRatio; // 16/9
    float mCameraUnitFrom; // Distanses of view
    float mCameraUnitTo; // Distanses of view

    glm::vec3 mCameraDirection;
    glm::vec3 mCameraUp;

    glm::vec3 mCameraPosition;
    glm::quat mCameraRotation;

    glm::mat4 mProjectioViewModelMatrix;
};

#endif // CAMERA_H
