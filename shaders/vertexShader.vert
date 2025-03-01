#version 430 core

layout(location = 0) in vec3 aPos;


out vec3 Color;

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;
uniform vec3 color;

void main()
{
    gl_Position = projection*view*model*vec4(aPos,1.0f);
    Color = color;
}
