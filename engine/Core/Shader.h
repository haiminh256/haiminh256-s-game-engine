#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <glad/glad.h>

class Shader {
public:
    GLuint ID; // Shader program ID

    Shader(const char* vertexPath, const char* fragmentPath);
    ~Shader();

    void Use(); // Activate the shader program
    void SetUniform1i(const std::string& name, int value);
    void SetUniform1f(const std::string& name, float value);
    void SetUniform3f(const std::string& name, float x, float y, float z);
    void SetUniform4f(const std::string& name, float x, float y, float z, float w);
    void SetUniformMat4(const std::string& name, const float* matrix);

private:
    std::string LoadShaderSource(const char* filepath);
    GLuint CompileShader(GLenum type, const char* source);
};

#endif // SHADER_H
