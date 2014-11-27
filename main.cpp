#include "Core/engine.h"

int main()
{
    Engine *engine = Engine::Instance();
    if (nullptr != engine)
    {
        engine->Execute();
        delete engine;
    }
    return 0;
}

