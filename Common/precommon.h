#ifndef PRECOMMON_H
#define PRECOMMON_H

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

typedef unsigned char      UINT8;
typedef unsigned short     UINT16;
typedef unsigned int       UINT32;
typedef unsigned long long UINT64;

const float PI = atan(1)*4;

const glm::vec3 WORLD_AXIS_X = glm::vec3(1.0f, 0.0f, 0.0f);
const glm::vec3 WORLD_AXIS_Y = glm::vec3(0.0f, 1.0f, 0.0f);
const glm::vec3 WORLD_AXIS_Z = glm::vec3(0.0f, 0.0f, 1.0f);

#endif // PRECOMMON_H
