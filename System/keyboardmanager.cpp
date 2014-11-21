#include "keyboardmanager.h"

KeyInfo Key::ENTER;
KeyInfo Key::ESCAPE;
KeyInfo Key::SPACE;
KeyInfo Key::LEFT_CONTROL;

KeyInfo Key::W;
KeyInfo Key::A;
KeyInfo Key::S;
KeyInfo Key::D;

KeyInfo Key::UP;
KeyInfo Key::DOWN;
KeyInfo Key::LEFT;
KeyInfo Key::RIGHT;

ActionInfo Action::PRESS;
ActionInfo Action::REPEAT;
ActionInfo Action::RELEASE;

void KeyBoardManager::AddKeyListener(KeyListener *listener)
{
    mKeyListeners.push_back(listener);
}

void KeyBoardManager::AssignKeyInfo(KeyInfo &key, int code, const char *name)
{
    key.mCode = code;
    key.mName = name;

    mKeyList[code] = &key;
}

void KeyBoardManager::AssignActionInfo(ActionInfo &action, int code, const char *name)
{
    action.mCode = code;
    action.mName = name;
    mActionList[code] = &action;
}

void KeyBoardManager::Alarm()
{
    // Checking of keys will be implemented in the listener.
    for (auto itr : mKeyListeners)
    {
        KeyListener *listener = itr;
        listener->NotifyKeyEvent();
    }
}

KeyBoardManager::KeyBoardManager()
{
    Start(15, true);
}

bool KeyInfo::Press()
{
     return WindowManager::Instance()->CheckPress((int)*this);
}

bool KeyInfo::Release()
{
    return WindowManager::Instance()->CheckRelease((int)*this);
}

bool KeyInfo::Repeat()
{
    return WindowManager::Instance()->CheckRepeat((int)*this);
}
