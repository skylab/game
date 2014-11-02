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

void KeyListener::NotifyKey(KeyInfo *key, ActionInfo *action, int &mods)
{
    std::cerr << "KeyListener::NotifyKey key: " << (const char*)*key << std::endl;
}
