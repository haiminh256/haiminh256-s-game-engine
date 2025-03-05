# Haiminh256's Game Engine

![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)
![OpenGL](https://img.shields.io/badge/OpenGL-4.6-blue.svg)

An open-source game engine built using **C++** and **OpenGL**, designed for flexibility and performance.

## Features
✅ **Cross-platform** (Windows, Linux, macOS)  
✅ **OpenGL 4.6 rendering pipeline**  
✅ **Custom shader support**  
✅ **Texture loading with stb_image**  
✅ **Entity-Component-System (ECS) (Planned)**  
✅ **Physics Engine (Planned)**  

## Getting Started
### **Prerequisites**
Make sure you have the following installed:
- **CMake** (for build configuration)
- **GLFW** (for window and input handling)
- **GLAD** (for OpenGL function loading)
- **MinGW-w64** (if on Windows)

### **Building the Engine**
```sh
mkdir build
cd build
cmake ..
make
```

### **Running a Demo**
```sh
./game_engine_demo
```

## Folder Structure
```
├── src/                 # Engine source code
│   ├── Core/            # Core engine files
│   ├── Renderer/        # Rendering system
│   ├── Shaders/         # Shader management
│   ├── Textures/        # Texture handling
│   ├── Physics/         # (Planned) Physics engine
│   └── Game/            # Example game implementation
├── include/             # Header files
├── res/              # Textures, models, shaders
├── CMakeLists.txt       # Build system
└── README.md            # Project documentation
```

## Contributing
Contributions are welcome! Feel free to submit pull requests or open issues.

## License
This project is licensed under the **MIT License** - see the [LICENSE](LICENSE) file for details.

