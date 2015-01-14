#include "windowmanager.h"

#define GLEW_STATIC
#include "../Libs/glew/glew.h"
#include <GL/gl.h>
#include <GL/glext.h>
#include "../Libs/glfw/glfw3.h"

#include "../Infra/timer.h"

#include "scenemanager.h"
#include "../Listeners/mouselistener.h"

void CusrosPositionChanged(GLFWwindow *window, double xpos, double ypos)
{
    (void)window; // disable warning
    int x = (int)xpos;
    int y = (int)ypos;
    MouseListener::SendNotification(x, y);
}

void WindowSizeChanged(GLFWwindow *window, int width, int height)
{
    (void)window;
    glfwSetWindowSize(window, width, height);
    glViewport(0, 0, width, height);
}

WindowManager::WindowManager() : mWindow(nullptr), mWidth(500), mHeight(500), mWindowCreated(true), mbTerminate(false), mbCursorVisible(true)
{
    if (nullptr != mWindow)
    {
        std::cerr << __PRETTY_FUNCTION__ << ": Window already exist" << std::endl;
        mWindowCreated = false;
        return;
    }

    if(!glfwInit())
    {
        std::cerr << __PRETTY_FUNCTION__ << ": Can't initialize glfw" << std::endl;
        mWindowCreated = false;
        return;
    }

    mWindow = glfwCreateWindow( mWidth, mHeight, "Game", NULL /*glfwGetPrimaryMonitor()*/, NULL);
    if (nullptr == mWindow)
    {
        std::cerr << __PRETTY_FUNCTION__ << ": Can't create window" << std::endl;
        mWindowCreated = false;
        glfwTerminate();
        return;
    }
    glfwMakeContextCurrent(mWindow);

    glewExperimental = true; // Needed for core profile
    if (glewInit() != GLEW_OK)
    {
        std::cerr << __PRETTY_FUNCTION__ << ": Can't initialize glew" << std::endl;
        mWindowCreated = false;
        return;
    }

    glfwSetInputMode(mWindow, GLFW_STICKY_KEYS, GL_TRUE);

    //TODO set callbacks
    glfwSetCursorPosCallback(mWindow, CusrosPositionChanged);
    glfwSetWindowSizeCallback(mWindow, WindowSizeChanged);

    Timer::GetCurrentTimeMs();
}

WindowManager::~WindowManager()
{
    glfwTerminate();
    glfwDestroyWindow(mWindow);
}

const char *WindowManager::GetName() const
{
    return __PRETTY_FUNCTION__;
}

GLFWwindow *WindowManager::GetWindow()
{
    return mWindow;
}

void WindowManager::SetWindowWindthHeight(unsigned int width, unsigned int height)
{
    mWidth = width;
    mHeight = height;
    WindowSizeChanged(mWindow, mWidth, mHeight);
}

bool WindowManager::GetWindowCreated(void) const
{
    return mWindowCreated;
}

int WindowManager::GetWindowWidth() const
{
    return mWidth;
}

int WindowManager::GetWindowHeight() const
{
    return mHeight;
}

void WindowManager::SetCursorPosition(int x, int y)
{
    glfwSetCursorPos(mWindow, x, y);
}

void WindowManager::SetCursorVisible(bool val)
{
    glfwSetInputMode(mWindow, GLFW_CURSOR, (val? GLFW_CURSOR_NORMAL : GLFW_CURSOR_HIDDEN));
    mbCursorVisible = val;
}

bool WindowManager::GetCorsorVisible() const
{
    return mbCursorVisible;
}

void WindowManager::Draw()
{
    while (!glfwWindowShouldClose(mWindow) && !mbTerminate)
    {
        SceneManager::Instance()->DrawScene();
        glfwSwapBuffers(mWindow);

        // Process external (button/mouse) events
        glfwPollEvents();
    }
}

void WindowManager::Terminate(void)
{
    mbTerminate = true;
}
