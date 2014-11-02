#ifndef KEYBOARDMANAGER_H
#define KEYBOARDMANAGER_H

#include "../Common/precommon.h"

//class KeyBoardManager;
class __Key
{
    friend class KeyBoardManager;
public:
    __Key()
    {
        ;
    }

    operator int()
    {
        return mValue;
    }

    operator const char *()
    {
        return mName;
    }

private:
    int mValue;
    const char *mName;
};

class KeyBoardManager
{
public:
    static KeyBoardManager *Instance(void);

    void AssignKey(__Key &key, int value);

// Keylist
    static __Key PRESS;
    static __Key REPEAT;
    static __Key RELEASE;

    static __Key ENTER;
    static __Key ESCAPE;

    static __Key UP;
    static __Key DOWN;
    static __Key LEFT;
    static __Key RIGHT;

    static __Key W;
    static __Key A;
    static __Key S;
    static __Key D;

private:
    KeyBoardManager();
    static KeyBoardManager *mInstance;
};

typedef KeyBoardManager Key;

#endif // KEYBOARDMANAGER_H
