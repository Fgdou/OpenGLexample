//
// Created by fgdou on 2/21/22.
//

#ifndef OPENGL_BLOCK_H
#define OPENGL_BLOCK_H

#include "../helper.h"
#include "../Texture.h"
#include "../BufferDescriptor.h"
#include "../Program.h"
#include "../Camera.h"
#include "../Renderer.h"
#include "Entity.h"

class Block: public Entity {
public:
    Block(const glm::vec3& pos, const glm::vec2& rot);
    virtual void draw(const Window& window, const Renderer& renderer, const Camera& cam) override;

private:
    struct Face{
        std::vector<glm::vec4> points;
        std::vector<glm::vec2> texture;
        std::vector<uint32_t> indexes;
    };

    static Face getCube(const glm::mat4& rotation);
    std::vector<Face> getFaces();
    static Face getDefaultFace();

    Texture m_texture{"../assets/dirt.png"};
    Program m_program;
    BufferDescriptor m_bd;
    VertexBuffer m_vb;
    IndexBuffer m_ib;
};


#endif //OPENGL_BLOCK_H
