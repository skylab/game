#include "keyboardmanager.h"

__Key KeyBoardManager::PRESS;
__Key KeyBoardManager::REPEAT;
__Key KeyBoardManager::RELEASE;

__Key KeyBoardManager::ENTER;
__Key KeyBoardManager::ESCAPE;

__Key KeyBoardManager::UP;
__Key KeyBoardManager::DOWN;
__Key KeyBoardManager::LEFT;
__Key KeyBoardManager::RIGHT;

__Key KeyBoardManager::W;
__Key KeyBoardManager::A;
__Key KeyBoardManager::S;
__Key KeyBoardManager::D;

KeyBoardManager *KeyBoardManager::mInstance = nullptr;

KeyBoardManager *KeyBoardManager::Instance()
{
    if (nullptr == mInstance)
    {
        try
        {
            mInstance = new KeyBoardManager();
        }
        catch(std::bad_alloc &ba)
        {
            std::cerr << ba.what() << " : Can't allcate KeyBoardManager" << std::endl;
            mInstance = nullptr;
        }
    }
    return mInstance;
}

void KeyBoardManager::AssignKey(__Key &key, int value)
{
    key.mValue = value;
    std::cerr << "Key: " << (const char*)key << " set: " << (int)key << std::endl;
}

#define SET_KEY_NAME(name) name.mName = #name;
KeyBoardManager::KeyBoardManager()
{
    SET_KEY_NAME(PRESS);
    SET_KEY_NAME(REPEAT);
    SET_KEY_NAME(RELEASE);

    SET_KEY_NAME(ENTER);
    SET_KEY_NAME(ESCAPE);

    SET_KEY_NAME(UP);
    SET_KEY_NAME(DOWN);
    SET_KEY_NAME(LEFT);
    SET_KEY_NAME(RIGHT);

    SET_KEY_NAME(W);
    SET_KEY_NAME(A);
    SET_KEY_NAME(S);
    SET_KEY_NAME(D);
}
