#ifndef BUTTON_H
#define BUTTON_H

class Button
{
public:
    Button(int code, const char *name);
    ~Button();

    bool Press(void);
    bool Release(void);
    bool Repeat(void);

    operator int();
    operator const char *();

private:
    int mButtonCode;
    const char *mButtonName;
};

#endif // BUTTON_H
