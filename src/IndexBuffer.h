//
// Created by fgdou on 2/20/22.
//

#ifndef OPENGL_INDEXBUFFER_H
#define OPENGL_INDEXBUFFER_H

#include <cassert>
#include <vector>
#include "helper.h"

class IndexBuffer {
public:
    IndexBuffer();
    ~IndexBuffer();

    void bind() const;
    void setData(const std::vector<uint32_t>& indexes) const;
private:

    uint32_t m_bufferId;
};
#endif //OPENGL_INDEXBUFFER_H
