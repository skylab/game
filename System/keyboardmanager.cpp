#include "keyboardmanager.h"

#include "../Infra/timer.h"

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
        std::cout << "Hello 1" << std::endl;
    }
};


KeyInfo Key::ENTER;
KeyInfo Key::ESCAPE;

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

            // TODO : Place in correct place
            //KeyTimer *timer = new KeyTimer();
            //timer->Start(1000, true);
            KeyTimer *timer = new KeyTimer();
            timer->Start(1000, true);
            KeyTimer1 *timer1 = new KeyTimer1();
            timer1->Start(3000, true);
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

    //std::cerr << "KeyBoardManager::AssignKeyInfo: " << key.mName << " " << key.mCode << std::endl;
}

void KeyBoardManager::AssignActionInfo(ActionInfo &action, int code, const char *name)
{
    action.mCode = code;
    action.mName = name;
    mActionList[code] = &action;
}

void KeyBoardManager::ProcessKey(int &key, int &scancode, int &action, int &mods)
{
    for(std::list<KeyListener*>::iterator i = mKeyListeners.begin(); i != mKeyListeners.end(); ++i)
    {
        if (mKeyList.find(key) != mKeyList.end() && mActionList.find(action) != mActionList.end())
        {
            if ((*i)->GetKeyListenerEnable())
            {
                (*i)->NotifyKey(mKeyList[key], mActionList[action], mods);
            }
        }
        else
        {
            std::cout << "Unknown key or action" << std::endl;
        }
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
