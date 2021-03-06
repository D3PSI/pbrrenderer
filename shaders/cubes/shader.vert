/**
 * @file cubes/shader.vert
 * @brief Implements a vertex shader for all major calculations of a vertex' color
 * @author D3PSI
 */
#version 330 core
layout(location = 0) in vec3 _pos;
layout(location = 1) in vec3 _col;

out vec3 vertCol;

uniform mat4 m;
uniform mat4 v;
uniform mat4 p;


void main() {
    gl_Position = p * v * m * vec4(_pos, 1.0);
    vertCol = _col;
}