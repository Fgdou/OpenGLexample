//
// Created by fgdou on 2/21/22.
//

#ifndef OPENGL_WINDOW_GLFW_H
#define OPENGL_WINDOW_GLFW_H

#include "../helper.h"
#include "Window.h"

#include <string>

class WindowGLFW: public Window {
public:
    WindowGLFW(int width, int height, const std::string& name);
    virtual ~WindowGLFW() override;

    virtual void setVSync(bool activated) override;
    virtual void draw() override;
    virtual void clear() const override;
private:
    static void resized(GLFWwindow *window, int width, int height);

    GLFWwindow* m_window;
};


#endif //OPENGL_WINDOW_H
