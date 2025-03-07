#version 430 core

layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aColor;

out vec3 Color;

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;
uniform vec3 color;

void main()
{
    gl_Position = model*view*projection*vec4(aPos,1.0f);
    Color = color;
}
