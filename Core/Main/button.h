#ifndef BUTTON_H
#define BUTTON_H

class Button
{
    friend class KeyboardManager;
public:
    Button();
    ~Button();

    bool Press(void);
    bool Release(void);
    bool Repeat(void);

    operator int();

private:
    int mButtonCode;
    const char *mButtonName;
};

#endif // BUTTON_H
