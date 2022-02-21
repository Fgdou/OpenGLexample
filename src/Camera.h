//
// Created by fgdou on 2/21/22.
//

#ifndef OPENGL_CAMERA_H
#define OPENGL_CAMERA_H

#include "glm.hpp"

class Camera {
public:
    const glm::vec3 getPos() const;
    const glm::vec3 getRot() const;
    const glm::mat4 getMat() const;
private:
    glm::vec3 pos;
    glm::vec2 rot;
    float fov;
};


#endif //OPENGL_CAMERA_H
