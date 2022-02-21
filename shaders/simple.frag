#version 450 core

layout (location = 0) out vec4 color;
layout (location = 0) in vec2 texPos;

uniform sampler2D tex;

void main(){
    color = texture(tex, texPos);
}