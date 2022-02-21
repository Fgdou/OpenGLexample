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

int main() {
    std::cout << "Hello, World!" << std::endl;

    if(glfwInit() != GLFW_TRUE)
        throw std::runtime_error("failed to init glfw");

    glfwWindowHint(GLFW_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_VERSION_MINOR, 3);

    auto window = glfwCreateWindow(500, 500, "Test", nullptr, nullptr);

    if(window == nullptr) {
        const char* desc;
        glfwGetError(&desc);
        std::cout << "Error: " << desc << std::endl;
        throw std::runtime_error("failed to create window");
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    if(!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        throw std::runtime_error("failed to init glad");
    }

    std::cout << "OpenGL " << glGetString(GL_VERSION)
        << ' ' << glGetString(GL_RENDERER)
        << std::endl;

    glViewport(0, 0, 500, 500);


    {
        std::vector<float> vecs = {
                -0.5f, -0.5f, 0.0f, 0.0f,
                0.5f, -0.5f, 1.0f, 0.0f,
                -0.5f, 0.5f, 0.0f, 1.0f,
                0.5f, 0.5f, 1.0f, 1.0f,
        };
        std::vector<uint32_t> indexes = {
                0, 1, 2,
                1, 2, 3,
        };

        BufferDescriptor bd;
        bd.addType<float>(2);
        bd.addType<float>(2);

        VertexBuffer vb;
        vb.setData(vecs);

        IndexBuffer ib;
        ib.setData(indexes);

        bd.sendData(ib, vb);

        Program program;
        program.addShader("../shaders/simple.vert", Program::VERTEX);
        program.addShader("../shaders/simple.frag", Program::FRAGMENT);
        program.compile();
        program.bind();

        Texture texture("../assets/dirt.png");

        while (!glfwWindowShouldClose(window)) {
            GL_CALL(glClear(GL_COLOR_BUFFER_BIT));

            bd.bind();
            texture.bind(0);

            GL_CALL(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0));


            glfwSwapBuffers(window);
            glfwPollEvents();
        }
    }



    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
