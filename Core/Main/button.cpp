#include "button.h"

#include "../Managers/keyboardmanager.h"

const char *defaultButtonName = "Unknown";

Button::Button() : mButtonCode(0), mButtonName(defaultButtonName)
{
    ;
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

Button::operator int()
{
    return mButtonCode;
}
