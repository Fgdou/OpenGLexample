//
// Created by fgdou on 2/21/22.
//

#ifndef OPENGL_APPLICATION_H
#define OPENGL_APPLICATION_H

#include "Window.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "BufferDescriptor.h"
#include "Program.h"
#include "Texture.h"
#include "Renderer.h"

class Application {
public:
    Application();
    ~Application() = default;

    void run();

private:
    Window window{500, 500, "My OpenGL App"};
    Renderer renderer;
    VertexBuffer vb;
    IndexBuffer ib;
    BufferDescriptor bd;
    Program program;
    Texture texture{"../assets/dirt.png"};

    float i = 0;
    float di = .01;
};


#endif //OPENGL_APPLICATION_H
