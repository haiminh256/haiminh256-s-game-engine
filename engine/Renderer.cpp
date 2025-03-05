#include <Core/Renderer.h>
#include <iostream>

Renderer::Renderer() : VAO(0), VBO(0) {}

Renderer::~Renderer() {
    Shutdown();
}

bool Renderer::Init() {
    // Define triangle vertices
    float vertices[] = {
        // Positions         // Colors
         0.0f,  0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  
        -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  
         0.5f, -0.5f, 0.0f,  0.0f, 0.0f, 1.0f   
    };

    // Generate and bind VAO & VBO
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Define vertex attributes
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    std::cout << "Renderer Initialized" << std::endl;
    return true;
}

void Renderer::Render() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // Bind VAO and draw
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindVertexArray(0);
}

void Renderer::Shutdown() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    std::cout << "Renderer Shutdown" << std::endl;
}
