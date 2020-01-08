/**
 * @file default/shader.frag
 * @brief Implements a fragment shader for all major calculations of a fragment's color
 * @author D3PSI
 */
#version 330 core
in vec3 vertCol;

out vec4 outColor;


void main() {
    outColor = vec4(vertCol, 1.0);
}
 