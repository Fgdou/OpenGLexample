//
// Created by fgdou on 2/21/22.
//

#ifndef OPENGL_WINDOW_H
#define OPENGL_WINDOW_H

#include "../helper.h"

#include <string>

class Window {
public:
    Window(int width, int height, const std::string& name);
    virtual ~Window(){};

    int getWidth() const;
    int getHeight() const;

    bool shouldClose() const;
    bool hasResized();

    virtual void setVSync(bool activated) = 0;
    virtual void draw() = 0;
    virtual void clear() const = 0;

    float getRatio() const;

protected:
    bool m_shouldClose;
    bool m_hasResized;
    int m_height, m_width;
};


#endif //OPENGL_WINDOW_H
