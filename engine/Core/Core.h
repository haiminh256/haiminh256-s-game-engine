#pragma once
#include <Core/Engine.h>
#include <Core/Renderer.h> // Include the Renderer class
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Core : public Engine {
public:
    Core(int nWidth, int nHeight, const char* title);
    virtual ~Core();
    virtual bool Init() override;
    virtual void Run() override;
    virtual void Shutdown() override;

private:
    GLFWwindow* window;
    unsigned int VBO, VAO;
    Renderer* renderer; // Add Renderer instance
};
