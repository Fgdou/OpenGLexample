//
// Created by fgdou on 2/21/22.
//

#include "Renderer.h"

static bool glad_initiated = false;

void Renderer::render(const Window& window, const Program& prog, const BufferDescriptor& bd, const VertexBuffer& vb, const IndexBuffer& ib) const {
    bd.bind();
    prog.bind();
    bd.sendData(ib, vb);
    GL_CALL(glDrawElements(GL_TRIANGLES, ib.count(), GL_UNSIGNED_INT, 0));
}

void Renderer::initGlad(const Window& window) {
    if(glad_initiated)
        return;
    glad_initiated = true;
    if(!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        throw std::runtime_error("failed to init glad");
    }
    std::cout << "OpenGL " << glGetString(GL_VERSION)
              << ' ' << glGetString(GL_RENDERER)
              << std::endl;
    glViewport(0, 0, window.getWidth(), window.getHeight());
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
}

Renderer::Renderer(const Window &window) {
    initGlad(window);
}
