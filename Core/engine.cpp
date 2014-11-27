#include "engine.h"

#include "Infra/singletonmanager.h"

#include "Managers/windowmanager.h"
#include "Managers/keyboardmanager.h"

#include "Managers/scenemanager.h"

void RemoveAllSingletons()
{
    SingletonManager::Instance()->RemoveAllSingletons();
}

Engine::Engine()
{
    atexit(RemoveAllSingletons);
}

Engine::~Engine()
{
    ;
}

bool Engine::Execute(void)
{
    if (Init())
    {
        // Engine Draw Cycle
        WindowManager::Instance()->Draw();

        return true;
    }
    else
    {
        return false;
    }
}

bool Engine::Init(void)
{
    bool initializationSuccess = true;

    // Init basic core parts
    WindowManager *window = WindowManager::Instance();
    if (nullptr != window && window->GetWindowCreated())
    {
        window->SetWindowWindthHeight(1024, 768);
    }
    else
    {
        std::cerr << __PRETTY_FUNCTION__ << ": WindowManager is nullptr" << std::endl;
        initializationSuccess = false;
    }

    KeyboardManager *keyboard = KeyboardManager::Instance();
    if (initializationSuccess && nullptr != keyboard)
    {
        // Add some initialization of keyboard manager if needed.
    }
    else
    {
        std::cerr << __PRETTY_FUNCTION__ << ": KeyboardManager is nullptr" << std::endl;
        initializationSuccess = false;
    }

    // Init scene parts
    SceneManager *sceneManager = SceneManager::Instance();
    if (initializationSuccess && nullptr != sceneManager)
    {
        initializationSuccess = sceneManager->LoadFirstScene();
    }
    else
    {
        std::cerr << __PRETTY_FUNCTION__ << ": SceneManager is nullptr" << std::endl;
        initializationSuccess = false;
    }

    return initializationSuccess;
}
