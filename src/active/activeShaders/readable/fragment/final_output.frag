#version 450

// Specify the layout location for the input texture coordinates
layout(location = 0) in vec2 texCords;  // Input texture coordinates from the vertex shader

// Specify the layout location for the output color
layout(location = 0) out vec4 FragColor; // Output color to the framebuffer

// Specify a binding point for the texture sampler
layout(binding = 0) uniform sampler2D textureSam; // Texture sampler with binding 0

void main() {
    // Sample the texture using the texture coordinates
    FragColor = texture(textureSam, texCords); // Set the output color to the sampled texture
}
