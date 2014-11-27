#ifndef PHYSICLEVEL_H
#define PHYSICLEVEL_H

#include "../BaseLevel/baselevel.h"

class PhysicLevel : virtual public BaseLevel
{
protected:
    PhysicLevel();
    virtual ~PhysicLevel() override;
};

#endif // PHYSICLEVEL_H
