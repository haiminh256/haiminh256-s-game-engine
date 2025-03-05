#include <Core/Core.h>
#include <Core/Texture.h>

int main() {
    // Create Core engine instance
    Core* engine = new Core(800, 800, "OpenGL Engine");
    Texture* amongusTex = new Texture("../res/amongus.png");

    if(!engine->Init()) 
    {
      return -1;
    }
    engine->Run();

    // Cleanup
    delete engine;
    delete amongusTex;
    return 0;
}
