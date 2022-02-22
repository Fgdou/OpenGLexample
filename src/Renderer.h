//
// Created by fgdou on 2/21/22.
//
#ifndef OPENGL_RENDERER_H
#define OPENGL_RENDERER_H

#include "BufferDescriptor.h"
#include "Program.h"
#include "Window/Window.h"

class Renderer {
public:
    Renderer(const Window& window);
public:
    void initGlad(const Window& window);
    void render(const Window& window, const Program& prog, const BufferDescriptor& bf, const VertexBuffer& vb, const IndexBuffer& ib) const;
};


#endif //OPENGL_RENDERER_H
