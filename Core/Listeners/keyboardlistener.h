#ifndef KEYBOARDLISTENER_H
#define KEYBOARDLISTENER_H

#include "../Main/button.h"
#include "../Infra/preinfra.h"
#include "../Infra/list.h"
#include "../Managers/keyboardmanager.h"

class KeyboardListener
{
    friend class KeyboardManager;
public:
    KeyboardListener();
    virtual ~KeyboardListener();

    static void SendNotification(void);

    virtual void CheckKeys(void);
private:
    static List<KeyboardListener *> mListenersList;
};

#endif // KEYBOARDLISTENER_H
