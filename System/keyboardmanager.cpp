#include "keyboardmanager.h"


class KeyTimer : public Timer
{
public:
    void Alarm(void) override
    {
        std::cout << "Hello" << std::endl;
    }
};

class KeyTimer1 : public Timer
{
public:
    void Alarm(void) override
    {
        //std::cout << "Hello 1" << std::endl;
    }
};


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

/////////
ActionInfo Action::PRESS;
ActionInfo Action::REPEAT;
ActionInfo Action::RELEASE;

KeyBoardManager *KeyBoardManager::mInstance = nullptr;

KeyBoardManager *KeyBoardManager::Instance()
{
    if (nullptr == mInstance)
    {
        try
        {
            mInstance = new KeyBoardManager();

            /*
            // TODO : Place in correct place
            KeyTimer *timer = new KeyTimer();
            timer->Start(1000, true);
            KeyTimer1 *timer1 = new KeyTimer1();
            timer1->Start(2000, true);
            */

            // TODO : Move KeyManager to separate thread in case when standart timer has not time to process button;
            mInstance->Start(15, true);
        }
        catch(std::bad_alloc &ba)
        {
            std::cerr << ba.what() << " : Can't allcate KeyBoardManager" << std::endl;
            mInstance = nullptr;
        }
    }
    return mInstance;
}

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
    ;
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
