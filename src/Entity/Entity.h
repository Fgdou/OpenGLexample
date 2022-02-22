//
// Created by fgdou on 2/22/22.
//

#ifndef OPENGL_ENTITY_H
#define OPENGL_ENTITY_H

#include "../helper.h"
#include "../Window/Window.h"
#include "../Renderer.h"
#include "../Camera.h"
#include "../Texture.h"


class Entity {
public:
    Entity(const glm::vec3& pos, const glm::vec2& rot);
    virtual ~Entity(){};

    virtual void draw(const Window& window, const Renderer& renderer, const Camera& cam) = 0;
    glm::vec3& getPos();
    glm::vec2& getRot();

    virtual glm::mat4 getMat() const;

protected:
    glm::vec3 pos;
    glm::vec2 rot;
};


#endif //OPENGL_ENTITY_H
