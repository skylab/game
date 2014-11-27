#ifndef SINGLETONABS_H
#define SINGLETONABS_H

class SingletonAbs
{
protected:
    SingletonAbs();

public:
    virtual ~SingletonAbs();

    // Used in Singleton Manager to prevent double deletion of object.
    bool mbInSingletonList;
};

#endif // SINGLETONABS_H
