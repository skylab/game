#ifndef PREGRAPHIC_H
#define PREGRAPHIC_H

#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glext.h>
#include <GL/freeglut.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Types.h"

#include <iostream>

#define _DEBUG

#ifdef _DEBUG
    //Shaders debug
    #define DEBUG_SHADER
    #define DEBUG_SHADER_PROGRAMM
#endif

#endif // PREGRAPHIC_H
