//
// Created by fgdou on 2/21/22.
//

#include "Camera.h"
#include "gtc/matrix_transform.hpp"

Camera::Camera(const glm::vec3 &pos, const glm::vec2 &rot, float fov, float fr)
    : fov(fov), pos(pos), rot(rot), frameRatio(fr)
{}

const glm::vec3& Camera::getPos() const {
    return pos;
}

const glm::vec2 &Camera::getRot() const {
    return rot;
}
glm::vec3& Camera::getPos() {
    return pos;
}

glm::vec2 &Camera::getRot() {
    return rot;
}

glm::mat4 Camera::getMat() const {
    auto proj = glm::perspective(glm::radians(fov), frameRatio, 0.1f, 100.0f);
    auto rotY = glm::rotate(glm::mat4(1.0f), rot.y, {0, 1, 0});
    auto rotX = glm::rotate(glm::mat4(1.0f), rot.x, {1, 0, 0});
    auto translate = glm::translate(glm::mat4(1.0f), pos);

    return proj*rotX*rotY*translate;
}

void Camera::updateRatio(float ratio) {
    frameRatio = ratio;
}
