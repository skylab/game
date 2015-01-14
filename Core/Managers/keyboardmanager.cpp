#include "keyboardmanager.h"
#include "windowmanager.h"
#include "../Libs/glfw/glfw3.h"

Button KeyboardManager::F1(GLFW_KEY_F1, "F1");
Button KeyboardManager::F2(GLFW_KEY_F2, "F2");
Button KeyboardManager::F3(GLFW_KEY_F3, "F3");

Button KeyboardManager::Escape(GLFW_KEY_ESCAPE, "Escape");
Button KeyboardManager::Enter(GLFW_KEY_ENTER, "Enter");
Button KeyboardManager::LCtrl(GLFW_KEY_LEFT_CONTROL, "LCtrl");
Button KeyboardManager::RCtrl(GLFW_KEY_RIGHT_CONTROL, "RCtrl");
Button KeyboardManager::Space(GLFW_KEY_SPACE, "Space");

Button KeyboardManager::W(GLFW_KEY_W, "W");
Button KeyboardManager::A(GLFW_KEY_A, "A");
Button KeyboardManager::S(GLFW_KEY_S, "S");
Button KeyboardManager::D(GLFW_KEY_D, "D");

KeyboardManager::KeyboardManager()
{
    StartTimer(15, true);
}

KeyboardManager::~KeyboardManager()
{
    StopTimer();
}

const char *KeyboardManager::GetName() const
{
    return __PRETTY_FUNCTION__;
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

void KeyboardManager::AddButton(Button *button)
{
    mButtonList.push_back(button);
}

void KeyboardManager::Timeout()
{
    KeyboardListener::SendNotification();
}
