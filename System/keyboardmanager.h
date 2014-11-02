#ifndef KEYBOARDMANAGER_H
#define KEYBOARDMANAGER_H

#include "../Common/precommon.h"

#include "../Main/keylistener.h"
class KeyListener;

class Key
{
    friend class KeyBoardManager;
public:
    operator int()
    {
        return mCode;
    }

    operator const char*()
    {
        return mName;
    }

private:
    Key(int code, const char* name) : mCode(code), mName(name)
    {
        ;
    }

    int mCode;
    const char* mName;
};

class KeyBoardManager
{
public:
    static KeyBoardManager *Instance(void);

    void AddKeyListener(KeyListener *listener);
    bool AddKey(int code, const char*name);

    void ProcessKey(int &key, int &scancode, int &action, int &mods);

private:
    KeyBoardManager();
    static KeyBoardManager *mInstance;

    std::list<KeyListener*> mKeyListeners;
    std::map<int,Key*> mKeyList;
};

#endif // KEYBOARDMANAGER_H
