#ifndef CAMERA_H
#define CAMERA_H

#include "../coreconfig.h"
#include "../Listeners/mouselistener.h"
#include "../Listeners/keyboardlistener.h"

class Camera : public MouseListener, public KeyboardListener
{
public:
    Camera();
    virtual ~Camera() override;

    virtual void NotifyMousePosition(int &x, int &y) override;
    virtual void CheckKeys(void) override;

    void SetProsition(glm::vec3 position);

    void RotatePitch(float degrees);
    void RotateHeading(float degrees);

    const glm::mat4 &GetPVMMatrix(void);

    void SetAspectRatio(float val);

private:
    float mViewAngle; // 45
    float mViewAspectRatio; // 16/9
    float mUnitFrom; // Distanses of view
    float mUnitTo; // Distanses of view

    float mMoveSpeedMS;
    unsigned int mLastTimerPointMs;

    glm::vec3 mFrontDirection;
    glm::vec3 mUpDirection;
    glm::vec3 mPosition;
    glm::quat mRotation;

    mutable glm::mat4 mProjectioViewModelMatrix;
};


#endif // CAMERA_H
