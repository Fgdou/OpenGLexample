//
// Created by fgdou on 2/20/22.
//

#ifndef OPENGL_VERTEXBUFFER_H
#define OPENGL_VERTEXBUFFER_H

#include <vector>
#include <cassert>
#include "helper.h"

class VertexBuffer {
public:
    VertexBuffer();
    ~VertexBuffer();

    void bind() const;

    template<class T> void setData(const std::vector<T>& data){assert(false);}
private:
    uint32_t m_bufferId;
};


#endif //OPENGL_VERTEXBUFFER_H
