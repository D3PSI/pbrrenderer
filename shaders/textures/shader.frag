/**
 * @file main/shader.frag
 * @brief Implements a fragment shader for all major calculations of a fragment's color
 * @author D3PSI
 */
#version 330 core
in vec3 vertCol;
in vec2 vertTex;

out vec4 outColor;

uniform sampler2D textureSampler1;


void main() {
    outColor = texture(textureSampler1, vertTex);
}
 