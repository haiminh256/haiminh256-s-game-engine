#include <Core/Texture.h>
#include <glad/glad.h>
#include <stb_image.h>
#include <iostream>

Texture::Texture(const char* filePath) {
    // Load image data
    data = stbi_load(filePath, &width, &height, &nrChannels, 0);
    if (!data) {
        std::cerr << "Failed to load texture: " << filePath << std::endl;
        textureID = 0; // Mark as invalid
        return;
    }

    std::cout << "Loaded texture: " << filePath << " (" << width << "x" << height << ") Channels: " << nrChannels << std::endl;

    // Determine image format
    GLenum format = (nrChannels == 1) ? GL_RED :
                    (nrChannels == 3) ? GL_RGB :
                    (nrChannels == 4) ? GL_RGBA : 0;

    if (format == 0) {
        std::cerr << "Unsupported format!" << std::endl;
        stbi_image_free(data);
        return;
    }

    // Generate OpenGL texture
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);

    // Set texture parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // Upload texture to OpenGL
    glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);

    // Unbind and cleanup
    glBindTexture(GL_TEXTURE_2D, 0);
    stbi_image_free(data);
}

Texture::~Texture() {
    freeTexture();
}

void Texture::freeTexture() {
    if (textureID) {
        glDeleteTextures(1, &textureID);
        textureID = 0;
    }
}

void Texture::bind() const {
    glBindTexture(GL_TEXTURE_2D, textureID);
}

void Texture::unbind() const {
    glBindTexture(GL_TEXTURE_2D, 0);
}
