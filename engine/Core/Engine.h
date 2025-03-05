#ifndef ENGINE_H
#define ENGINE_H

class Engine {
public:
    virtual ~Engine() = default; // Ensures proper cleanup

    virtual bool Init() = 0;     // Must be implemented in derived classes
    virtual void Run() = 0;
    virtual void Shutdown() = 0;

protected:
    Engine() = default;  // Prevents direct instantiation of Engine
};

#endif // ENGINE_H
