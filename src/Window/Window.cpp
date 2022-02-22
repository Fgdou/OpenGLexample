//
// Created by fgdou on 2/21/22.
//

#include <stdexcept>
#include <iostream>
#include "Window.h"

Window::Window(int width, int height, const std::string &name)
    : m_shouldClose(false), m_width(width), m_height(height), m_hasResized(false)
{}
bool Window::shouldClose() const {
    return m_shouldClose;
}
int Window::getHeight() const {
    return m_height;
}
int Window::getWidth() const {
    return m_width;
}
float Window::getRatio() const {
    return (float)m_width/(float)m_height;
}

bool Window::hasResized() {
    if(m_hasResized){
        m_hasResized = false;
        return true;
    }
    return false;
}
