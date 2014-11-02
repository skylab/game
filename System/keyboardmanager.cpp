#include "keyboardmanager.h"

KeyBoardManager *KeyBoardManager::mInstance = nullptr;

KeyBoardManager *KeyBoardManager::Instance()
{
    if (nullptr == mInstance)
    {
        try
        {
            mInstance = new KeyBoardManager();
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

bool KeyBoardManager::AddKey(int code, const char *name)
{
    Key *key = nullptr;
    try
    {
        key = new Key(code, name);
    }
    catch(std::bad_alloc &ba)
    {
        std::cerr << ba.what() << " : Can't create key" << std::endl;
        key = nullptr;
    }

    if (nullptr != key)
    {
        mKeyList[code] = key;
        return true;
    }
    else
    {
        return false;
    }
}

void KeyBoardManager::ProcessKey(int &key, int &scancode, int &action, int &mods)
{
    // Filter key and action.
    // Send key and action to object in according to filter options.

    for(std::list<KeyListener*>::iterator i = mKeyListeners.begin(); i != mKeyListeners.end(); ++i)
    {
        (*i)->NotifyKey(mKeyList[key], action, mods);
    }
}

KeyBoardManager::KeyBoardManager()
{
    ;
}
