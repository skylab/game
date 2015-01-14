#include "button.h"

#include "../Managers/keyboardmanager.h"

Button::Button(int code, const char *name) : mButtonCode(code), mButtonName(name)
{
    KeyboardManager::Instance()->AddButton(this);
}

Button::~Button()
{
    ;
}

bool Button::Press()
{
    return KeyboardManager::Instance()->CheckPress(mButtonCode);
}

bool Button::Release()
{
    return KeyboardManager::Instance()->CheckRelease(mButtonCode);
}

bool Button::Repeat()
{
    return KeyboardManager::Instance()->CheckRepeat(mButtonCode);
}

Button::operator const char *()
{
    return mButtonName;
}

Button::operator int()
{
    return mButtonCode;
}
