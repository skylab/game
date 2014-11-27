#include "windowmanager.h"

#define GLEW_STATIC
#include "../Libs/glew/glew.h"
#include <GL/gl.h>
#include <GL/glext.h>

#include "../Libs/glfw/glfw3.h"

#include "scenemanager.h"

void CusrosPositionChanged(GLFWwindow *window, double xpos, double ypos)
{
    (void)window; // disable warning
}

void WindowSizeChanged(GLFWwindow *window, int width, int height)
{
    (void)window;
    SceneManager::Instance()->Reshape(width, height);
}

WindowManager::WindowManager() : mWindow(nullptr), mWidth(200), mHeight(200), mWindowCreated(true), mbTerminate(false)
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
}

WindowManager::~WindowManager()
{
    glfwTerminate();
    glfwDestroyWindow(mWindow);
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
