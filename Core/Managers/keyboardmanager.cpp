#include "keyboardmanager.h"
#include "windowmanager.h"
#include "../Libs/glfw/glfw3.h"


Button KeyboardManager::Escape;
Button KeyboardManager::Enter;

KeyboardManager::KeyboardManager()
{

    Escape.mButtonName = "Escape";
    Escape.mButtonCode = GLFW_KEY_ESCAPE;

    Enter.mButtonName = "Enter";
    Enter.mButtonCode = GLFW_KEY_ENTER;
}

KeyboardManager::~KeyboardManager()
{
    ;
}

bool KeyboardManager::CheckPress(int buttonCode)
{
    return (glfwGetKey(WindowManager::Instance()->GetWindow(), buttonCode) == GLFW_PRESS);
}

bool KeyboardManager::CheckRelease(int buttonCode)
{
    return (glfwGetKey(WindowManager::Instance()->GetWindow(), buttonCode) == GLFW_RELEASE);
}

bool KeyboardManager::CheckRepeat(int buttonCode)
{
    return (glfwGetKey(WindowManager::Instance()->GetWindow(), buttonCode) == GLFW_REPEAT);
}
