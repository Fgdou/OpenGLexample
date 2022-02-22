//
// Created by fgdou on 2/21/22.
//

#include "Renderer.h"

void Renderer::render(const Window& window, const Program& prog, const BufferDescriptor& bd, const VertexBuffer& vb, const IndexBuffer& ib) const {
    bd.bind();
    prog.bind();
    bd.sendData(ib, vb);
    GL_CALL(glDrawElements(GL_TRIANGLES, ib.count(), GL_UNSIGNED_INT, 0));
}
