#include "windowmanager.h"

#include <GLFW/glfw3.h>

#include "scenemanager.h"

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
}

const size_t &WindowManager::GetWindowWidth() const
{
    return mWidth;
}

const size_t &WindowManager::GetWindowHeight() const
{
    return mHeight;
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
    while (!glfwWindowShouldClose(window))
    {
        SceneManager::Instance()->DrawScene();
        glfwSwapBuffers(mWindow);
        glfwPollEvents();
    }
}

WindowManager::WindowManager() : mWindow(nullptr), mWidth(0), mHeight(0), mCursorVisible(true)
{
    ;
}
