#include "keylistener.h"

#include "../System/keyboardmanager.h"

KeyListener::KeyListener() : mbEnabled(false)
{
    KeyBoardManager::Instance()->AddKeyListener(this);
}

KeyListener::~KeyListener()
{
    ;
}

void KeyListener::SetKeyListenerEnable(bool val)
{
    mbEnabled = val;
}

bool KeyListener::GetKeyListenerEnable() const
{
    return mbEnabled;
}

void KeyListener::NotifyKeyEvent()
{
    std::cerr << __PRETTY_FUNCTION__ << std::endl;
}
