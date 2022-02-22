//
// Created by fgdou on 2/22/22.
//

#include "Entity.h"
#include "gtc/matrix_transform.hpp"

Entity::Entity(const glm::vec3 &pos, const glm::vec2 &rot)
    : pos(pos), rot(rot)
{

}

glm::vec3 &Entity::getPos() {
    return pos;
}

glm::vec2 &Entity::getRot() {
    return rot;
}

glm::mat4 Entity::getMat() const {
    auto rotateY = glm::rotate(glm::mat4(1.0f), rot.y, {0, 1, 0});
    auto rotateX = glm::rotate(glm::mat4(1.0f),rot.x, {1, 0, 0});
    auto translate = glm::translate(glm::mat4(1.0f), pos);
    return translate*rotateX*rotateY;
}
