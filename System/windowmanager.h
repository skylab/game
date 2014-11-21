#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include "../Common/precommon.h"

#include "Infra/singleton.h"

class GLFWwindow;
class KeyBoardManager;

class WindowManager : public Singleton<WindowManager>
{
public:
    // TOOD Write destructor
    WindowManager();

    bool Createwindow(unsigned int windowWidth, unsigned int windowHeight);
    void Terminate(void) const;

    bool InitKeyBoard(KeyBoardManager *manager);
    bool CheckPress(int key);
    bool CheckRelease(int key);
    bool CheckRepeat(int key);

    const size_t &GetWindowWidth(void) const;
    void SetWindowWidth(int size);
    const size_t &GetWindowHeight(void) const;
    void SetWindowHeight(int size);
    void SetCursorPosition(unsigned int width, unsigned int height);
    void SetCursorVisible(bool visible);
    bool GetCursorVisible(void) const;

    void Draw(void);
private:
    GLFWwindow* mWindow;
    size_t mWidth;
    size_t mHeight;
    bool mCursorVisible;
};

#endif // WINDOWMANAGER_H
