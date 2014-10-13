#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include "Common/precommon.h"

class GLFWwindow;

class WindowManager
{
public:
    // TOOD Write destructor
    static WindowManager *Instance();
    bool Createwindow(unsigned int windowWidth, unsigned int windowHeight);

    const size_t &GetWindowWidth(void) const;
    const size_t &GetWindowHeight(void) const;
    void SetCursorPosition(unsigned int width, unsigned int height);
    void SetCursorVisible(bool visible);
    bool GetCursorVisible(void) const;

    void Draw(void);
private:
    WindowManager();

private:
    static WindowManager *mInstance;
    GLFWwindow* mWindow;
    size_t mWidth;
    size_t mHeight;
    bool mCursorVisible;
};

#endif // WINDOWMANAGER_H