//
// Created by fgdou on 2/21/22.
//

#include <fstream>
#include "Texture.h"

#include "stb_image.h"

void Texture::openPng(const std::string &path) {
    stbi_set_flip_vertically_on_load(true);
    auto data = stbi_load(path.c_str(), &m_width, &m_height, nullptr, 4);

    if(data == nullptr)
        throw std::runtime_error("failed to open texture file : " + path);

    m_data.clear();
    m_data.reserve(m_height*m_width*4);
    m_data.insert(m_data.end(), data, data+m_height*m_width*4);
}

Texture::Texture(const std::string &path)
    : m_shaderId(0), m_height(0), m_width(0), m_path(path)
{
    openPng(path);
    glGenTextures(1, &m_shaderId);
    glBindTexture(GL_TEXTURE_2D, m_shaderId);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_data.data());
    //glGenerateMipmap(GL_TEXTURE_2D);
}

Texture::~Texture() {
    glad_glDeleteTextures(1, &m_shaderId);
}

std::ostream &operator<<(std::ostream &os, const Texture &txt) {
    return os << "Texture("<<txt.m_width<<"x"<<txt.m_height<<"): " << txt.m_path;
}

void Texture::bind(int n) const {
    glActiveTexture(GL_TEXTURE0+n);
    glBindTexture(GL_TEXTURE_2D, m_shaderId);
}
