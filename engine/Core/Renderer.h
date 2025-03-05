#ifndef RENDERER_H
#define RENDERER_H

#include <glad/glad.h>
#include <glm/glm.hpp> // For transformations
#include <Core/Shader.h> // Assuming you have a Shader class
#include <Core/Texture.h> // Assuming you have a Texture class

class Renderer {
public:
    Renderer();
    ~Renderer();

    bool Init(); // Set up VAO, VBO, shaders, etc.
    void Render(); // Draw objects
    void Shutdown(); // Clean up OpenGL resources

private:
    GLuint VAO, VBO;
    Shader* shaderProgram; // Shader object
};

#endif // RENDERER_H
