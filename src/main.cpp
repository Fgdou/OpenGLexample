#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "helper.h"
#include "Program.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "BufferDescriptor.h"
#include "Texture.h"

#include "gtc/matrix_transform.hpp"
#include "Window.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    Window window(500, 500, "OpenGL");


    if(!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        throw std::runtime_error("failed to init glad");
    }

    std::cout << "OpenGL " << glGetString(GL_VERSION)
        << ' ' << glGetString(GL_RENDERER)
        << std::endl;

    glViewport(0, 0, 500, 500);


    {
        VertexBuffer vb;
        vb.setData(std::vector<float>{
                -0.5f, -0.5f, 0.0f, 0.0f,
                0.5f, -0.5f, 1.0f, 0.0f,
                -0.5f, 0.5f, 0.0f, 1.0f,
                0.5f, 0.5f, 1.0f, 1.0f,
        });

        IndexBuffer ib;
        ib.setData(std::vector<uint32_t>{
                0, 1, 2,
                1, 2, 3,
        });

        BufferDescriptor bd;
        bd.addType<float>(2);
        bd.addType<float>(2);

        bd.sendData(ib, vb);

        Program program;
        program.addShader("../shaders/simple.vert", Program::VERTEX);
        program.addShader("../shaders/simple.frag", Program::FRAGMENT);
        program.compile();
        program.bind();

        Texture texture("../assets/dirt.png");

        float i = 0;
        float di = .01;

        while (!window.shouldClose()) {
            i += di;

            GL_CALL(glClear(GL_COLOR_BUFFER_BIT));

            bd.bind();
            texture.bind(0);

            auto rotate = glm::rotate(glm::mat4(1.0f), i, glm::vec3{0.0, 1.0, 0.0});
            auto translate = glm::translate(glm::mat4(1.0f), glm::vec3{0.0f, 0.0f, 0.0f});
            auto mvp = rotate * translate;

            program.setUniform("MVP", mvp);
            GL_CALL(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0));

            window.draw();
        }
    }



    glfwTerminate();

    return 0;
}
