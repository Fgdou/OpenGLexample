//
// Created by fgdou on 2/21/22.
//

#include <stdexcept>
#include <iostream>
#include "WindowGLFW.h"

static bool glfw_initiated = false;

WindowGLFW::WindowGLFW(int width, int height, const std::string &name)
    : Window(width, height, name), m_window(nullptr)
{
    if(!glfw_initiated){
        if(glfwInit() != GLFW_TRUE)
            throw std::runtime_error("failed to init glfw");

        glfwWindowHint(GLFW_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_VERSION_MINOR, 3);
        glfw_initiated = true;
    }

    m_window = glfwCreateWindow(width, height, name.c_str(), nullptr, nullptr);

    if(m_window == nullptr) {
        const char* desc;
        glfwGetError(&desc);
        std::cout << "Error: " << desc << std::endl;
        throw std::runtime_error("failed to create window");
    }
    glfwMakeContextCurrent(m_window);
    glfwSetWindowUserPointer(m_window, this);
    setVSync(true);

    glfwSetWindowSizeCallback(m_window, resized);
}

void WindowGLFW::setVSync(bool activated) {
    glfwMakeContextCurrent(m_window);
    if(activated)
        glfwSwapInterval(1);
    else
        glfwSwapInterval(0);
}

void WindowGLFW::draw() {
    glfwPollEvents();
    glfwSwapBuffers(m_window);

    if(glfwWindowShouldClose(m_window))
        m_shouldClose = true;
}

WindowGLFW::~WindowGLFW() {
    glfwDestroyWindow(m_window);
}

void WindowGLFW::clear() const {
    GL_CALL(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
}
void WindowGLFW::resized(GLFWwindow *window, int width, int height) {
    auto w = reinterpret_cast<WindowGLFW*>(glfwGetWindowUserPointer(window));
    w->m_width = width;
    w->m_height = height;

    glViewport(0, 0, width, height);
    w->m_hasResized = true;
}
