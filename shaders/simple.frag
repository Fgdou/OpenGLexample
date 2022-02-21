#version 450 core

layout (location = 0) out vec4 color;

uniform float u_r;

void main(){
    color = vec4(u_r, 1.0f, 0.0f, 1.0f);
}