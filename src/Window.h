//
// Created by fgdou on 2/21/22.
//

#ifndef OPENGL_WINDOW_H
#define OPENGL_WINDOW_H

#include "GLFW/glfw3.h"

#include <string>

class Window {
public:
    Window(int width, int height, const std::string& name);
    ~Window();

    int getWidth() const;
    int getHeight() const;

    bool shouldClose() const;

    void setVSync(bool activated);

    void draw();

private:
    GLFWwindow* m_window;
    bool m_shouldClose;
    int m_height, m_width;
};


#endif //OPENGL_WINDOW_H
