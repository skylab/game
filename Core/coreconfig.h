#ifndef CORECONFIG_H
#define CORECONFIG_H

// Include GLM library to the project
#define GLM_FORCE_RADIANS
#include "Libs/glm/glm.hpp"
#include "Libs/glm/gtc/matrix_transform.hpp"
#include "Libs/glm/gtc/quaternion.hpp"

//To graphic level, should be included before gl.h
#define GLEW_STATIC
#include "Libs/glew/glew.h"

const float PI = atan(1)*4;

enum MoveDirection
{
    DIRECTION_FORWARD,
    DIRECTION_BACK,
    DIRECTION_LEFT,
    DIRECTION_RIGHT,
    DIRECTION_UP,
    DIRECTION_DOWN
};

#endif // CORECONFIG_H
