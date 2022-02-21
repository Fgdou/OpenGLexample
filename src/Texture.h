//
// Created by fgdou on 2/21/22.
//

#ifndef OPENGL_TEXTURE_H
#define OPENGL_TEXTURE_H

#include "helper.h"
#include <string>
#include <vector>

class Texture {
public:
    explicit Texture(const std::string& path);
    ~Texture();

    void bind(int n) const;
private:
    void openPng(const std::string& path);

    friend std::ostream& operator<<(std::ostream& os, const Texture& txt);

    uint32_t m_shaderId;
    const std::string m_path;
    std::vector<uint8_t> m_data;
    int m_height, m_width;
};


#endif //OPENGL_TEXTURE_H
