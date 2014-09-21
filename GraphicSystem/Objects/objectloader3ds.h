#ifndef OBJECTLOADER3DS_H
#define OBJECTLOADER3DS_H

class ObjectAbs;

class ObjectLoader3ds
{
public:
    ObjectLoader3ds();
    bool LoadObject(ObjectAbs *object, const char *objectFile);
};

#endif // OBJECTLOADER3DS_H
