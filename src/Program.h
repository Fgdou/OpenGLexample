//
// Created by fgdou on 2/20/22.
//

#ifndef OPENGL_PROGRAM_H
#define OPENGL_PROGRAM_H

#include <memory>
#include "helper.h"
#include <unordered_map>
#include "glm.hpp"

class Program {
public:
    enum ShaderType{
        VERTEX = GL_VERTEX_SHADER,
        FRAGMENT = GL_FRAGMENT_SHADER
    };

    Program();
    ~Program();

    void addShader(const std::string& path, ShaderType type) const;
    void compile();
    void bind() const;

    void setUniform(const std::string &name, float f0, float f1, float f2, float f3);
    void setUniform(const std::string &name, float f0, float f1, float f2);
    void setUniform(const std::string &name, float f0);
    void setUniform(const std::string &name, const glm::mat4x4& mat);
private:
    uint32_t m_programId;
    bool m_compiled;
    std::unordered_map<std::string, int> m_location_buffer;

    int getUniformAddr(const std::string& name);

    static std::string openShaderFile(const std::string& path);
    static uint32_t compileShader(const std::string& path, GLenum type);
};


#endif //OPENGL_PROGRAM_H
