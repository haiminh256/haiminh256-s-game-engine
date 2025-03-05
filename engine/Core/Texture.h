#ifndef TEXTURE_H
#define TEXTURE_H

#include <glad/glad.h>
#include <stb_image.h>

class Texture {
public:
    Texture(const char* filePath);
    ~Texture();

    void bind() const;
    void unbind() const;
    void freeTexture();

private:
    GLuint textureID; // OpenGL texture handle
    int width, height, nrChannels;
    unsigned char* data;
};

#endif // TEXTURE_H
