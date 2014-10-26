#include "windowmanager.h"

#include <GLFW/glfw3.h>

#include "../Main/scenemanager.h"

void KeyCallBackFunction(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    (void)window; // disable warning
    SceneManager::Instance()->Keyboard(key, scancode, action, mods);
}

void CursorPositionFunction(GLFWwindow *window, double xpos, double ypos)
{
    (void)window; // disable warning
    SceneManager::Instance()->MousePosition(xpos, ypos);
}

void WindowResizeFunction(GLFWwindow *window, int width, int height)
{
    (void)window; // disable warning
    SceneManager::Instance()->GetCurrentScene()->Reshape(width, height);
    WindowManager::Instance()->SetWindowWidth(width);
    WindowManager::Instance()->SetWindowHeight(height);
}

WindowManager *WindowManager::mInstance = nullptr;

WindowManager *WindowManager::Instance()
{
    if (nullptr == mInstance)
    {
        try
        {
            mInstance = new WindowManager();
        }
        catch(std::bad_alloc &ba)
        {
            std::cerr << ba.what() << " : Can't create window manager" << std::endl;
            mInstance = nullptr;
        }
    }
    return mInstance;
}

bool WindowManager::Createwindow(unsigned int windowWidth, unsigned int windowHeight)
{
    if (nullptr != mWindow)
    {
        std::cerr << "Window is already initialized" << std::endl;
        return false;
    }

    if(!glfwInit())
    {
        std::cerr << "Initialization failed. Can't initialize glfw" << std::endl;
        return false;
    }

    mWindow = glfwCreateWindow( windowWidth, windowHeight, "Game", NULL, NULL);
    if (nullptr == mWindow)
    {
        std::cerr << "Initialization failed. Can't create window" << std::endl;
        glfwTerminate();
        return false;
    }
    glfwMakeContextCurrent(mWindow);

    glewExperimental = true; // Needed for core profile
    if (glewInit() != GLEW_OK)
    {
        std::cerr << "Initialization failed. Can't initialize glew" << std::endl;
        return false;
    }

    glfwSetInputMode(mWindow, GLFW_STICKY_KEYS, GL_TRUE);

    //TODO set callbacks
    glfwSetKeyCallback(mWindow, KeyCallBackFunction);
    glfwSetCursorPosCallback(mWindow, CursorPositionFunction);
    glfwSetWindowSizeCallback(mWindow, WindowResizeFunction);

    SetWindowWidth(static_cast<int>(windowWidth));
    SetWindowHeight(static_cast<int>(windowHeight));

    return true;
}

void WindowManager::Terminate() const
{
    glfwTerminate();
}

const size_t &WindowManager::GetWindowWidth() const
{
    return mWidth;
}

void WindowManager::SetWindowWidth(int size)
{
    std::cerr << "Window width is changed to " << size << std::endl;
    mWidth = static_cast<size_t>(size);
}

const size_t &WindowManager::GetWindowHeight() const
{
    return mHeight;
}

void WindowManager::SetWindowHeight(int size)
{
    std::cerr << "Window height is changed to " << size << std::endl;
    mHeight = static_cast<size_t>(size);
}

void WindowManager::SetCursorPosition(unsigned int width, unsigned int height)
{
    glfwSetCursorPos(mWindow, width, height);
}

void WindowManager::SetCursorVisible(bool visible)
{
    if (visible)
    {
        glfwSetInputMode(mWindow, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    }
    else
    {
        glfwSetInputMode(mWindow, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
    }
    mCursorVisible = visible;
}

bool WindowManager::GetCursorVisible() const
{
    return mCursorVisible;
}

void WindowManager::Draw(void)
{
    while (!glfwWindowShouldClose(mWindow))
    {
        SceneManager::Instance()->DrawScene();
        glfwSwapBuffers(mWindow);

        // Process external (button/mouse) events
        glfwPollEvents();
    }
}

WindowManager::WindowManager() : mWindow(nullptr), mWidth(0), mHeight(0), mCursorVisible(true)
{
    ;
}
