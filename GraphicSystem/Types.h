#ifndef TYPES_H
#define TYPES_H

#include "pregraphic.h"

class Vertex3f
{
public:
    Vertex3f(GLfloat _x=0, GLfloat _y=0, GLfloat _z=0)
    {
        mCoordinates[0]=_x;
        mCoordinates[1]=_y;
        mCoordinates[2]=_z;
    }

    Vertex3f &operator=(const Vertex3f &obj)
    {
        if (this != &obj)
        {
            mCoordinates[0]=obj.mCoordinates[0];
            mCoordinates[1]=obj.mCoordinates[1];
            mCoordinates[2]=obj.mCoordinates[2];
        }
        return *this;
    }

    Vertex3f(const Vertex3f &obj)
    {
        *this = obj;
    }

    operator GLfloat *()
    {
        return &mCoordinates[0];
    }

    void SetCoordinates(GLfloat _x=0, GLfloat _y=0, GLfloat _z=0)
    {
        mCoordinates[0]=_x;
        mCoordinates[1]=_y;
        mCoordinates[2]=_z;
    }

private:
    GLfloat mCoordinates[3];
};

#endif // TYPES_H
