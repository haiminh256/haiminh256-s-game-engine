cmake_minimum_required(VERSION 3.12)
project(opengl)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Include directories before adding subdirectories
include_directories(vendors/glfw/include vendors/glad vendors/glm engine)

# Add dependencies
add_subdirectory(vendors/glfw)
add_subdirectory(vendors/glm)

# Compile GLAD as a separate library
add_library(glad STATIC vendors/glad/glad.c)
target_include_directories(glad PUBLIC vendors/glad vendors/stb)

# Add executable
add_executable(${PROJECT_NAME} src/main.cpp engine/Core.cpp engine/Engine.cpp engine/Texture.cpp engine/stb_image.cpp engine/Renderer.cpp engine/Shader.cpp)

# Link libraries
target_link_libraries(${PROJECT_NAME} PRIVATE glfw glm glad opengl32)

# Ensure MinGW-w64 includes are available
target_include_directories(${PROJECT_NAME} PRIVATE
    "C:/mingw64/include"
    "C:/mingw64/x86_64-w64-mingw32/include"
    "C:/mingw64/lib/gcc/x86_64-w64-mingw32/14.2.0/include"
    "C:/mingw64/lib/gcc/x86_64-w64-mingw32/14.2.0/include-fixed"
    "C:/mingw64/x86_64-w64-mingw32/include/c++/14.2.0"
    "C:/mingw64/x86_64-w64-mingw32/include/c++/14.2.0/x86_64-w64-mingw32"
)
