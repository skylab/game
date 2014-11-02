#ifndef KEYLISTENER_H
#define KEYLISTENER_H

#include "../System/keyboardmanager.h"
class KeyInfo;
class ActionInfo;

class KeyListener
{
public:
    KeyListener();
    virtual ~KeyListener();

    void SetKeyListenerEnable(bool val);
    bool GetKeyListenerEnable(void) const;

    virtual void NotifyKey(KeyInfo *key, ActionInfo *action, int &mods);

private:
    bool mbEnabled;
};

#endif // KEYLISTENER_H
