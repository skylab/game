#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include "../Infra/singleton.h"
#include "../Infra/thread.h"

class GLFWwindow;

class WindowManager : public Singleton<WindowManager>
{
public:
    WindowManager();
    virtual ~WindowManager() override;

    const char *GetName(void) const override;

    GLFWwindow *GetWindow(void);

    void SetWindowWindthHeight(unsigned int width, unsigned int height);
    bool GetWindowCreated(void) const;

    int GetWindowWidth(void) const;
    int GetWindowHeight(void) const;

    void SetCursorPosition(int x, int y);
    void SetCursorVisible(bool val);
    bool GetCorsorVisible(void) const;

    void Draw(void);
    void Terminate(void);

private:
    GLFWwindow* mWindow;
    size_t mWidth;
    size_t mHeight;
    bool mWindowCreated;

    bool mbTerminate;

    bool mbCursorVisible;
};

#endif // WINDOWMANAGER_H
