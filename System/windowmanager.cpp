#include "windowmanager.h"

#include "System/GLFW/glfw3.h"

#include "../Main/scenemanager.h"

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

    mWindow = glfwCreateWindow( windowWidth, windowHeight, "Game", NULL /*glfwGetPrimaryMonitor()*/, NULL);
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
    glfwSetCursorPosCallback(mWindow, CursorPositionFunction);
    glfwSetWindowSizeCallback(mWindow, WindowResizeFunction);

    SetWindowWidth(static_cast<int>(windowWidth));
    SetWindowHeight(static_cast<int>(windowHeight));

    return true;
}

bool WindowManager::InitKeyBoard(KeyBoardManager *manager)
{
    (void)manager; // To disable warning message about unused variable
#define ASSIGN_KEY(name) manager->AssignKeyInfo(Key::name, GLFW_KEY_##name, #name);

    ASSIGN_KEY(ENTER);
    ASSIGN_KEY(ESCAPE);
    ASSIGN_KEY(SPACE);
    ASSIGN_KEY(LEFT_CONTROL);

    ASSIGN_KEY(W);
    ASSIGN_KEY(A);
    ASSIGN_KEY(S);
    ASSIGN_KEY(D);

    ASSIGN_KEY(UP);
    ASSIGN_KEY(DOWN);
    ASSIGN_KEY(LEFT);
    ASSIGN_KEY(RIGHT);

#define ASSIGN_ACTION(name) manager->AssignActionInfo(Action::name, GLFW_##name, #name);
    ASSIGN_ACTION(PRESS);
    ASSIGN_ACTION(REPEAT);
    ASSIGN_ACTION(RELEASE);

    return true;
}

bool WindowManager::CheckPress(int key)
{
    return glfwGetKey(mWindow, key) == GLFW_PRESS;
}

bool WindowManager::CheckRelease(int key)
{
    return glfwGetKey(mWindow, key) == GLFW_RELEASE;
}

bool WindowManager::CheckRepeat(int key)
{
    return glfwGetKey(mWindow, key) == GLFW_REPEAT;
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
    KeyBoardManager::Instance();
}
