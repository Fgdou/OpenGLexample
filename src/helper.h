//
// Created by fgdou on 2/20/22.
//

#ifndef OPENGL_HELPER_H
#define OPENGL_HELPER_H

#define GLEW_STATIC
#include "glad/glad.h"
#include "GLFW/glfw3.h"

#define GL_CALL(x) x; detectError(__LINE__, __FILE__)
void detectError(int line, const char* file);

#endif //OPENGL_HELPER_H
