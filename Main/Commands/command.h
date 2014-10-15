#ifndef COMMAND_H
#define COMMAND_H

class ObjectRaw;

class Command
{
public:
    Command();

    virtual void Run(void) = 0;
    virtual void Visit(ObjectRaw *object) = 0;
};

#endif // COMMAND_H
