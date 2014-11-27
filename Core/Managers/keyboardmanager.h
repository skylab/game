#ifndef KEYBOARDMANAGER_H
#define KEYBOARDMANAGER_H

#include "../Infra/singleton.h"
#include "../Main/button.h"

class KeyboardManager : public Singleton<KeyboardManager>
{
public:
    KeyboardManager();
    virtual ~KeyboardManager() override;

    bool CheckPress(int buttonCode);
    bool CheckRelease(int buttonCode);
    bool CheckRepeat(int buttonCode);

public:
    static Button Escape;
    static Button Enter;
};

typedef KeyboardManager Key;

#endif // KEYBOARDMANAGER_H
