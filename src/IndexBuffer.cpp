//
// Created by fgdou on 2/20/22.
//

#include "IndexBuffer.h"

IndexBuffer::IndexBuffer()
    : m_bufferId(0)
{
    GL_CALL(glGenBuffers(1, &m_bufferId));
}

IndexBuffer::~IndexBuffer() {
    GL_CALL(glDeleteBuffers(1, &m_bufferId));
}

void IndexBuffer::bind() const {
    GL_CALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_bufferId));
}

int IndexBuffer::count() const{
    return m_count;
}

void IndexBuffer::setData(const std::vector<uint32_t> &indexes) {
    bind();
    GL_CALL(glad_glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(uint32_t)*indexes.size(), indexes.data(), GL_STATIC_DRAW));
    m_count = indexes.size();
}
