#ifndef PRECOMMON_H
#define PRECOMMON_H

//#define _LINUX
#define _WINDOWS

#include <new>
#include <typeinfo>
#include <list>
#include <map>
#include <cstring>

#include <iostream>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>

//To graphic level, should be included before gl.h
#ifdef _WINDOWS
    #define GLEW_STATIC
    #include "System/glew/glew.h"
#endif

#ifdef _LINUX
    #include <GL/glew.h>
#endif

const float PI = atan(1)*4;

typedef unsigned char      UINT8;
typedef unsigned short     UINT16;
typedef unsigned int       UINT32;
typedef unsigned long long UINT64;

/*
const glm::vec3 WORLD_AXIS_X = glm::vec3(1.0f, 0.0f, 0.0f);
const glm::vec3 WORLD_AXIS_Y = glm::vec3(0.0f, 1.0f, 0.0f);
const glm::vec3 WORLD_AXIS_Z = glm::vec3(0.0f, 0.0f, 1.0f);
*/

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
