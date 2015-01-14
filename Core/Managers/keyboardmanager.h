#ifndef KEYBOARDMANAGER_H
#define KEYBOARDMANAGER_H

#include "../Infra/singleton.h"
#include "../Infra/timer.h"
#include "../Main/button.h"
#include "../Listeners/keyboardlistener.h"

class KeyboardManager : public Singleton<KeyboardManager>, public Timer
{
public:
    KeyboardManager();
    virtual ~KeyboardManager() override;

    const char *GetName(void) const override;

    bool CheckPress(int buttonCode);
    bool CheckRelease(int buttonCode);
    bool CheckRepeat(int buttonCode);

    void AddButton(Button *button);

    virtual void Timeout(void);

public:
    static Button F1;
    static Button F2;
    static Button F3;

    static Button Escape;
    static Button Enter;
    static Button LCtrl;
    static Button RCtrl;
    static Button Space;

    static Button W;
    static Button A;
    static Button S;
    static Button D;

private:
    std::list<Button *> mButtonList;
};

typedef KeyboardManager Key;

#endif // KEYBOARDMANAGER_H
