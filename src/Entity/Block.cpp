//
// Created by fgdou on 2/21/22.
//

#include "Block.h"
#include "gtc/matrix_transform.hpp"

Block::Block(const glm::vec3 &pos, const glm::vec2 &rot)
    : Entity(pos, rot)
{
    m_program.addShader("../shaders/simple.vert", Program::VERTEX);
    m_program.addShader("../shaders/simple.frag", Program::FRAGMENT);
    m_program.compile();

    auto faces = getFaces();
    std::vector<float> data;
    std::vector<uint32_t> indexes;

    uint32_t offset = 0;
    for(auto& f : faces){
        for(int i=0; i<f.points.size(); i++){
            data.emplace_back(f.points[i].x);
            data.emplace_back(f.points[i].y);
            data.emplace_back(f.points[i].z);
            data.emplace_back(f.points[i].w);
            data.emplace_back(f.texture[i].x);
            data.emplace_back(f.texture[i].y);
        }
        for(auto& v : f.indexes){
            indexes.push_back(v + offset);
        }
        offset += f.points.size();
    }
    m_vb.setData(data);
    m_ib.setData(indexes);

    m_bd.addType<glm::vec4>(1);
    m_bd.addType<glm::vec2>(1);
}

Block::Face Block::getCube(const glm::mat4 &rotation) {
    auto face = getDefaultFace();
    auto translate = glm::translate(glm::mat4(1.0f), glm::vec3{0, 0, .5f});

    auto mat = rotation*translate;

    for(auto& v : face.points) {
        v = mat * v;
    }

    return face;
}

Block::Face Block::getDefaultFace() {
    return {
            {
                    {-.5f, -.5f, .0f, 1.0f},
                    {-.5f,  .5f, .0f, 1.0f},
                    { .5f,  .5f, .0f, 1.0f},
                    { .5f, -.5f, .0f, 1.0f},
            },
            {
                    {0, 0},
                    {0, 1},
                    {1, 1},
                    {1, 0}
            },
            {
                    0, 1, 2,
                    2, 3, 0
            }
    };
}

std::vector<Block::Face> Block::getFaces() {
    std::vector<glm::mat4> sides = {
            glm::mat4(1.0f),
            glm::rotate(glm::mat4(1.0f), glm::pi<float>()/2.0f, {0, 1, 0}),
            glm::rotate(glm::mat4(1.0f), -glm::pi<float>()/2.0f, {0, 1, 0}),
            glm::rotate(glm::mat4(1.0f), glm::pi<float>(), {0, 1, 0}),
            glm::rotate(glm::mat4(1.0f), glm::pi<float>()/2.0f, {1, 0, 0}),
            glm::rotate(glm::mat4(1.0f), -glm::pi<float>()/2.0f, {1, 0, 0}),
    };

    std::vector<Face> vec;

    for(const auto& mat : sides){
        vec.emplace_back(getCube(mat));
    }

    return vec;
}

void Block::draw(const Window& window, const Renderer &renderer, const Camera &cam) {
    auto translate = glm::translate(glm::mat4(1.0f), cam.getPos());
    auto proj = cam.getMat();
    auto mvp = proj*translate*getMat();

    m_program.setUniform("MVP", mvp);
    renderer.render(window, m_program, m_bd, m_vb, m_ib);
}