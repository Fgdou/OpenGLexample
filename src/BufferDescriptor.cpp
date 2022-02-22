//
// Created by fgdou on 2/20/22.
//

#include "BufferDescriptor.h"
#include "glm.hpp"

BufferDescriptor::BufferDescriptor()
    : m_id(0)
{
    GL_CALL(glGenVertexArrays(1, &m_id));
}
BufferDescriptor::~BufferDescriptor() {
    GL_CALL(glDeleteVertexArrays(1, &m_id));
}

void BufferDescriptor::bind() const {
    GL_CALL(glBindVertexArray(m_id));
}

size_t BufferDescriptor::getSize() const {
    size_t size = 0;

    for(auto& e : m_elements){
        size += e.size;
    }

    return size;
}

void BufferDescriptor::sendData(const IndexBuffer& ib, const VertexBuffer& vb) const {
    bind();
    ib.bind();
    vb.bind();

    auto stride = getSize();
    uint32_t i = 0;
    size_t offset = 0;

    for(const auto& e : m_elements){
        GL_CALL(glEnableVertexAttribArray(i));
        GL_CALL(glVertexAttribPointer(i, e.count, e.type, GL_FALSE, stride, (void*)offset));
        i++;
        offset += e.size;
    }
}


template<>
void BufferDescriptor::addType<float>(int count) {
    m_elements.push_back({
                                 sizeof(float)*count,
                                 GL_FLOAT,
                                 count
                         });
}
template<>
void BufferDescriptor::addType<glm::vec4>(int count) {
    addType<float>(4*count);
}
template<>
void BufferDescriptor::addType<glm::vec2>(int count) {
    addType<float>(2*count);
}
template<>
void BufferDescriptor::addType<uint32_t>(int count) {
    m_elements.push_back({
                                 sizeof(uint32_t),
                                 GL_UNSIGNED_INT,
                                 count
                         });
}
template<>
void BufferDescriptor::addType<uint8_t>(int count) {
    m_elements.push_back({
                                 sizeof(uint8_t),
                                 GL_UNSIGNED_BYTE,
                                 count
                         });
}