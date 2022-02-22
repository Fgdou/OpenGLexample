//
// Created by fgdou on 2/21/22.
//

#include <stdexcept>
#include <iostream>
#include "Window.h"

static bool glfw_initiated = false;
static bool glad_initiated = false;

Window::Window(int width, int height, const std::string &name)
    : m_shouldClose(false), m_window(nullptr), m_width(width), m_height(height), m_hasResized(false)
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

    initGlad();
}

void Window::setVSync(bool activated) {
    glfwMakeContextCurrent(m_window);
    if(activated)
        glfwSwapInterval(1);
    else
        glfwSwapInterval(0);
}

void Window::draw() {
    glfwPollEvents();
    glfwSwapBuffers(m_window);

    if(glfwWindowShouldClose(m_window))
        m_shouldClose = true;
}

bool Window::shouldClose() const {
    return m_shouldClose;
}

int Window::getHeight() const {
    return m_height;
}

int Window::getWidth() const {
    return m_width;
}

Window::~Window() {
    glfwDestroyWindow(m_window);
}

void Window::clear() const {
    GL_CALL(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
}

void Window::initGlad() {
    if(glad_initiated)
        return;
    glad_initiated = true;
    if(!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        throw std::runtime_error("failed to init glad");
    }
    std::cout << "OpenGL " << glGetString(GL_VERSION)
              << ' ' << glGetString(GL_RENDERER)
              << std::endl;
    glViewport(0, 0, getWidth(), getHeight());
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
}

float Window::getRatio() const {
    return (float)m_width/(float)m_height;
}

void Window::resized(GLFWwindow *window, int width, int height) {
    auto w = reinterpret_cast<Window*>(glfwGetWindowUserPointer(window));
    w->m_width = width;
    w->m_height = height;

    glViewport(0, 0, width, height);
    w->m_hasResized = true;
}

bool Window::hasResized() {
    if(m_hasResized){
        m_hasResized = false;
        return true;
    }
    return false;
}
