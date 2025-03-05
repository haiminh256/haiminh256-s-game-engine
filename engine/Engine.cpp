#include <Core/Engine.h>
#include <iostream>

void Engine::Run() {
    std::cerr << "Engine::Run() should be overridden by derived class" << std::endl;
}

void Engine::Shutdown() {
    std::cerr << "Engine::Shutdown() should be overridden by derived class" << std::endl;
}
