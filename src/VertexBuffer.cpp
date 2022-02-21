//
// Created by fgdou on 2/20/22.
//

#include "VertexBuffer.h"

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