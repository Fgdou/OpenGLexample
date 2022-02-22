//
// Created by fgdou on 2/21/22.
//

#ifndef OPENGL_APPLICATION_H
#define OPENGL_APPLICATION_H

#include "Window/WindowGLFW.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "BufferDescriptor.h"
#include "Program.h"
#include "Texture.h"
#include "Renderer.h"
#include <memory>

class Application {
public:
    Application();
    ~Application() = default;

    void run();

private:
    std::unique_ptr<Window> window = std::make_unique<WindowGLFW>(1000, 600, "My OpenGL App");
    Renderer renderer{*window};
    VertexBuffer vb;
    IndexBuffer ib;
    BufferDescriptor bd;
    Program program;
    Texture texture{"../assets/dirt.png"};

    float i = 0;
    float di = .01;
};


#endif //OPENGL_APPLICATION_H
