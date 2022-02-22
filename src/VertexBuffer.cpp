//
// Created by fgdou on 2/20/22.
//

#include "VertexBuffer.h"
#include "glm.hpp"

VertexBuffer::VertexBuffer()
    : m_bufferId(0)
{
    GL_CALL(glad_glGenBuffers(1, &m_bufferId));
}

VertexBuffer::~VertexBuffer() {
    GL_CALL(glad_glDeleteBuffers(1, &m_bufferId));
}

void VertexBuffer::bind() const {
    GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, m_bufferId));
}

template<> void VertexBuffer::setData<float>(const std::vector<float> &data) {
    bind();
    GL_CALL(glBufferData(GL_ARRAY_BUFFER, sizeof(float)*data.size(), data.data(), GL_STATIC_DRAW));
}
template<> void VertexBuffer::setData<glm::vec4>(const std::vector<glm::vec4> &data) {
    bind();
    std::vector<float> buff;
    buff.reserve(data.size()*4);

    for(auto& v : data) {
        buff.emplace_back(v.x);
        buff.emplace_back(v.y);
        buff.emplace_back(v.z);
        buff.emplace_back(v.w);
    }

    GL_CALL(glBufferData(GL_ARRAY_BUFFER, sizeof(float)*buff.size(), buff.data(), GL_STATIC_DRAW));
}