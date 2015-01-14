#include "mouselistener.h"

List<MouseListener *> MouseListener::mListenersList;

MouseListener::MouseListener()
{
    mListenersList.push_back(this);
}

MouseListener::~MouseListener()
{
    mListenersList.remove(this);
}

void MouseListener::SendNotification(int &x, int &y)
{
    for (List<MouseListener*>::Iterator itr = mListenersList.begin(); itr != mListenersList.end(); ++itr)
    {
        MouseListener *listener = *itr;
        if (nullptr != listener)
            listener->NotifyMousePosition(x, y);
    }
}

void MouseListener::NotifyMousePosition(int &x, int &y)
{
    (void)x;
    (void)y;
}
