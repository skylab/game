#include "command.h"

#include "../../Common/objectraw.h"

Command::Command()
{
    ;
}

void Command::Run()
{
    std::cerr << "Command have empty run function body" << std::endl;
}

void Command::Visit(ObjectRaw *object)
{
    std::cerr << "Command have not visit function" << std::endl;
}
