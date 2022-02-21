//
// Created by fgdou on 2/20/22.
//

#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
#include <cassert>
#include "Program.h"

std::string Program::openShaderFile(const std::string& path){
    std::ifstream file(path);
    if(!file.is_open())
        throw std::runtime_error("failed to open shader");

    std::stringstream buff;
    buff << file.rdbuf();

    return buff.str();
}
uint32_t Program::compileShader(const std::string& path, GLenum type){
    auto str = openShaderFile(path);
    char* ptr = const_cast<char *>(str.c_str());
    auto size = str.size();

    GL_CALL(uint32_t shader_id = glCreateShader(type));
    GL_CALL(glShaderSource(shader_id, 1, &ptr, reinterpret_cast<const GLint *>(&size)));
    GL_CALL(glCompileShader(shader_id));

    int compiled;
    GL_CALL(glGetShaderiv(shader_id, GL_COMPILE_STATUS, &compiled));
    if(compiled != GL_TRUE){
        std::vector<char> buff(1024);
        GL_CALL(glGetShaderInfoLog(shader_id, buff.size(), nullptr, buff.data()));
        std::cerr << "Failed to compile " << ((type == GL_VERTEX_SHADER) ? "vertex" : "fragment") << " shader on file " << path << std::endl;
        std::cerr << buff.data() << std::endl;
        throw std::runtime_error("failed to compile shader");
    }

    return shader_id;
}

Program::Program()
    : m_compiled(false), m_programId(0)
{
    GL_CALL(m_programId = glCreateProgram());
}

Program::~Program() {
    GL_CALL(glDeleteProgram(m_programId));
}

void Program::addShader(const std::string &path, Program::ShaderType type) const {
    auto id = compileShader(path, type);
    GL_CALL(glAttachShader(m_programId, id));
    GL_CALL(glDeleteShader(id));
}

void Program::compile() {
    GL_CALL(glLinkProgram(m_programId));

    int compiled;
    GL_CALL(glGetProgramiv(m_programId, GL_LINK_STATUS, &compiled));
    if(compiled != GL_TRUE){
        std::vector<char> buff(1024);
        GL_CALL(glad_glGetProgramInfoLog(m_programId, buff.size(), nullptr, buff.data()));
        std::cerr << "Failed to link program" << std::endl;
        std::cerr << buff.data() << std::endl;
        throw std::runtime_error("failed to link program");
    }

    m_compiled = true;
}

void Program::bind() const {
    assert(m_compiled);
    GL_CALL(glUseProgram(m_programId));
}

int Program::getUniformAddr(const std::string &name) {

    if(m_location_buffer.find(name) != m_location_buffer.end())
        return m_location_buffer[name];

    GL_CALL(int loc = glGetUniformLocation(m_programId, name.data()));

    if(loc == -1)
        std::cerr << "Warning: uniform " << name << " not found" << std::endl;

    m_location_buffer[name] = loc;

    return loc;
}

void Program::setUniform(const std::string &name, float f0, float f1, float f2, float f3) {
    int loc = getUniformAddr(name);
    GL_CALL(glUniform4f(loc, f0, f1, f2, f3));
}
void Program::setUniform(const std::string &name, float f0, float f1, float f2) {
    int loc = getUniformAddr(name);
    GL_CALL(glUniform3f(loc, f0, f1, f2));
}
void Program::setUniform(const std::string &name, float f0) {
    int loc = getUniformAddr(name);
    GL_CALL(glUniform1f(loc, f0));
}

void Program::setUniform(const std::string &name, const glm::mat4x4 &mat) {
    int loc = getUniformAddr(name);
    GL_CALL(glUniformMatrix4fv(loc, 1, false, &mat[0][0]));
}
