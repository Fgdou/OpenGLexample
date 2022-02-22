//
// Created by fgdou on 2/20/22.
//

#ifndef OPENGL_HELPER_H
#define OPENGL_HELPER_H

#define GLEW_STATIC
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#define GLM_FORCE_RADIANS
#include "glm.hpp"
#include <iostream>

#define GL_CALL(x) x; detectError(__LINE__, __FILE__)
void detectError(int line, const char* file);

std::ostream& operator<<(std::ostream& os, const glm::vec3& vec);
std::ostream& operator<<(std::ostream& os, const glm::vec4& vec);

#endif //OPENGL_HELPER_H
