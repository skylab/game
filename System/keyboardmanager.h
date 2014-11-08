#ifndef KEYBOARDMANAGER_H
#define KEYBOARDMANAGER_H

#include "../Common/precommon.h"

#include "../Infra/timer.h"

#include "../Main/keylistener.h"
class KeyListener;

#include "windowmanager.h"

class KeyInfo
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

    bool operator ==(const KeyInfo &info)
    {
        return (info.mCode == mCode);
    }

    KeyInfo()
    {
        ;
    }

    bool Press(void);
    bool Release(void);
    bool Repeat(void);

private:
    KeyInfo(const KeyInfo&) {}

    int mCode;
    const char* mName;
};

class Key
{
public:
    static KeyInfo ENTER;
    static KeyInfo ESCAPE;
    static KeyInfo SPACE;
    static KeyInfo LEFT_CONTROL;

    static KeyInfo W;
    static KeyInfo A;
    static KeyInfo S;
    static KeyInfo D;

    static KeyInfo UP;
    static KeyInfo DOWN;
    static KeyInfo LEFT;
    static KeyInfo RIGHT;
};

class ActionInfo
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

    bool operator ==(const ActionInfo &info)
    {
        return (info.mCode == mCode);
    }

    ActionInfo()
    {
        ;
    }

private:
    ActionInfo(const ActionInfo&) {}
    int mCode;
    const char* mName;
};

class Action
{
public:
    static ActionInfo PRESS;
    static ActionInfo REPEAT;
    static ActionInfo RELEASE;
};

class KeyBoardManager : public Timer
{
public:
    static KeyBoardManager *Instance(void);

    void AssignKeyInfo(KeyInfo &key, int code, const char *name);
    void AssignActionInfo(ActionInfo &action, int code, const char *name);

    void AddKeyListener(KeyListener *listener);

    //void ProcessKey(int &key, int &scancode, int &action, int &mods);

    void Alarm(void) override;

private:
    KeyBoardManager();
    static KeyBoardManager *mInstance;

    std::list<KeyListener*> mKeyListeners;

    std::map<int,KeyInfo*> mKeyList;
    std::map<int,ActionInfo*> mActionList;
};

#endif // KEYBOARDMANAGER_H
