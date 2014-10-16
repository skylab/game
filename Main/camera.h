#ifndef CAMERA_H
#define CAMERA_H

#include "../GraphicSystem/graphicobject.h"

class Camera : public GraphicObject
{
public:
    Camera();
    virtual ~Camera();

    virtual void SetCameraViewAngle(float angle);
    virtual const float &GetCameraViewAngle(void) const;

    virtual void SetCameraViewAspectRatio(float aspectRatio);
    virtual const float &GetCameraViewAspectRatio(void) const;

    virtual void SetCameraUnitFrom(float from);
    virtual const float &GetCameraUnitFrom(void) const;

    virtual void SetCameraUnitTo(float to);
    virtual const float &GetCameraUnitTo(void) const;

    virtual const glm::mat4 &GetProjectionViewModelMatrix(void);

    void RotatePitch(float degrees) override;
    void RotateHeading(float degrees) override;

    virtual void ProcessCursorPosition(double &xpos, double &ypos);
    virtual void ProcessButtonPress(int &key, int &scancode, int &action, int &mods);

private:
    float CharacterHeight;

    // TODO read from config
    float mCameraViewAngle; // 90
    float mCameraViewAspectRatio; // 16/9
    float mCameraUnitFrom; // Distanses of view
    float mCameraUnitTo; // Distanses of view

    glm::mat4 mProjectioViewModelMatrix;
};

#endif // CAMERA_H
