#ifndef ENGINE_H
#define ENGINE_H

#include "Infra/singleton.h"

class Engine : public Singleton<Engine>
{
public:
    Engine();
    virtual ~Engine() override;

    bool Execute(void);

private:
    bool Init(void);
};

#endif // ENGINE_H
