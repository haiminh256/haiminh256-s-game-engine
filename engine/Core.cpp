#include <Core/Core.h>
#include <iostream>

Core::Core(int nWidth, int nHeight, const char* title)
    : window(nullptr), VAO(0), VBO(0), renderer(nullptr) { // Initialize renderer to nullptr
    if (!glfwInit()) {
        std::cerr << "GLFW initialization failed!" << std::endl;
        return;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(nWidth, nHeight, title, nullptr, nullptr);
    if (!window) {
        std::cerr << "OpenGL window creation failed!" << std::endl;
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "GLAD initialization failed!" << std::endl;
        glfwTerminate();
        return;
    }

    std::cout << "OpenGL Initialized: " << glGetString(GL_VERSION) << std::endl;
    glViewport(0, 0, nWidth, nHeight);
    glEnable(GL_DEPTH_TEST);

    // Initialize Renderer
    renderer = new Renderer();
    renderer->Init();
}

Core::~Core() {
    Shutdown();
}

bool Core::Init() {
    std::cout << "OpenGL Initialized: " << glGetString(GL_VERSION) << std::endl;
    return true;
}

void Core::Run() {
    while (!glfwWindowShouldClose(window)) {
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            glfwSetWindowShouldClose(window, true);
        }

        // Render using the Renderer class
        renderer->Render();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

void Core::Shutdown() {
    if (renderer) {
        delete renderer;
        renderer = nullptr;
    }

    if (window) {
        glfwDestroyWindow(window);
        window = nullptr;
    }
    glfwTerminate();
}
