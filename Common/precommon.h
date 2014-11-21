#ifndef PRECOMMON_H
#define PRECOMMON_H

#include <new>
#include <typeinfo>
#include <list>
#include <map>
#include <cstring>
#include <iostream>

#define GLM_FORCE_RADIANS
#include "System/glm/glm.hpp"
#include "System/glm/gtc/matrix_transform.hpp"
#include "System/glm/gtc/quaternion.hpp"

//To graphic level, should be included before gl.h
#ifdef __linux__
    #include <GL/glew.h>
#else
    #define GLEW_STATIC
    #include "System/glew/glew.h"
#endif

const float PI = atan(1)*4;

enum MoveDirection
{
    FORWARD,
    BACK,
    LEFT,
    RIGHT,
    UP,
    DOWN
};

#endif // PRECOMMON_H
