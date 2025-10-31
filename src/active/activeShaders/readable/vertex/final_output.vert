#version 450 core

// Define the positions of a fullscreen quad
vec2 fullScreenQuadPos[4] = vec2[4](
    vec2(-1, -1),  // Bottom-left
    vec2(1, -1),   // Bottom-right
    vec2(1, 1),    // Top-right
    vec2(-1, 1)    // Top-left
);

// Define the texture coordinates for the quad
vec2 fullScreenQuadTex[4] = vec2[4](
    vec2(0, 0),    // Bottom-left
    vec2(1, 0),    // Bottom-right
    vec2(1, 1),    // Top-right
    vec2(0, 1)     // Top-left
);

// Output texture coordinates
layout(location = 0) out vec2 texCords;

void main() {
    // Set the position of the vertex
    gl_Position = vec4(fullScreenQuadPos[gl_VertexIndex], 0.0, 1.0);
    // Pass the corresponding texture coordinates
    texCords = fullScreenQuadTex[gl_VertexIndex];
}
