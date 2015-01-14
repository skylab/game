#ifndef MOUSELISTENER_H
#define MOUSELISTENER_H

#include "../Infra/preinfra.h"
#include "../Infra/list.h"

class MouseListener
{
public:
    MouseListener();
    virtual ~MouseListener();

    static void SendNotification(int &x, int &y);

    virtual void NotifyMousePosition(int &x, int &y);

private:
    static List<MouseListener *> mListenersList;
};

#endif // MOUSELISTENER_H
