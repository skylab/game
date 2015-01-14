#ifndef SINGLETONABS_H
#define SINGLETONABS_H

class SingletonAbs
{
protected:
    SingletonAbs();

public:
    virtual ~SingletonAbs();

    virtual const char *GetName(void) const = 0;
};

#endif // SINGLETONABS_H
