//
// Created by fgdou on 2/21/22.
//

#ifndef OPENGL_CAMERA_H
#define OPENGL_CAMERA_H

#include "glm.hpp"

class Camera {
public:
    Camera(const glm::vec3& pos, const glm::vec2& rot, float fov, float frameRatio);

    const glm::vec3& getPos() const;
    const glm::vec2& getRot() const;
    glm::vec3& getPos();
    glm::vec2& getRot();
    glm::mat4 getMat() const;

    void updateRatio(float ratio);

private:
    glm::vec3 pos;
    glm::vec2 rot;
    float fov;
    float frameRatio;
};


#endif //OPENGL_CAMERA_H
