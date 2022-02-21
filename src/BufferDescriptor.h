//
// Created by fgdou on 2/20/22.
//

#ifndef OPENGL_BUFFERDESCRIPTOR_H
#define OPENGL_BUFFERDESCRIPTOR_H

#include <vector>
#include <cassert>
#include "helper.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"

class BufferDescriptor {
public:
    BufferDescriptor();
    ~BufferDescriptor();

    template<class T> void addType(int count){assert(false);}
    void bind() const;
    void sendData(const IndexBuffer& ib, const VertexBuffer& vb);
    size_t getSize() const;
private:
    struct Element{
        size_t size;
        GLenum type;
        int count;
    };

    uint32_t m_id;
    std::vector<Element> m_elements;
};

#endif //OPENGL_BUFFERDESCRIPTOR_H
