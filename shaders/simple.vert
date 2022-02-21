#version 450 core

layout (location = 0) in vec2 position;
layout (location = 1) in vec2 aTexPos;
uniform mat4 MVP;

layout (location = 0) out vec2 texPos;

void main(){
    texPos = aTexPos;
    gl_Position = MVP*vec4(position, 0.0f, 1.0f);
}