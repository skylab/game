#include "keyboardlistener.h"
#include "../Infra/preinfra.h"
#include "../Managers/keyboardmanager.h"

List<KeyboardListener *> KeyboardListener::mListenersList;

KeyboardListener::KeyboardListener()
{
    mListenersList.push_back(this);
}

KeyboardListener::~KeyboardListener()
{
    mListenersList.remove(this);
}

void KeyboardListener::SendNotification()
{
    for (List<KeyboardListener*>::Iterator itr = mListenersList.begin(); itr != mListenersList.end(); ++itr)
    {
        KeyboardListener *listener = *itr;
        if (nullptr != listener)
            listener->CheckKeys();
    }
}

void KeyboardListener::CheckKeys(void)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}
