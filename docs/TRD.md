# UrbanFlow - Technical Requirements Document

## 1. Technical Overview

UrbanFlow is a native desktop graphics application implemented
using C++17 and modern OpenGL.

The system follows a modular architecture separating rendering,
viewing transformations, scene management, input handling and
traffic simulation.

## 2. Technology Stack

| Technology | Purpose |
| --- | --- |
| C++17 | Primary programming language |
| OpenGL 3.3 Core | Graphics API |
| GLSL 330 | Shader programming |
| GLFW | Window and input management |
| GLAD | OpenGL function loading |
| GLM | Graphics mathematics |
| GCC | C++ compilation |
| CMake | Build configuration |
| Ninja | Build execution |
| GDB | Debugging |
| ClangFormat | Code formatting |
| Clang-Tidy | Static analysis |
| CTest | Automated testing |
| MSYS2 UCRT64 | Development toolchain |
| Git and GitHub | Version control |
| GitHub Actions | Continuous integration |
| Visual Studio Code | Development environment |

## 3. System Architecture

### Core

Responsible for application lifecycle, initialization,
window management, timing and resource cleanup.

### Graphics

Responsible for OpenGL rendering, shader management,
geometry, textures, lighting and viewing transformations.

### Scene

Responsible for organizing roads, buildings, vehicles,
traffic lights and urban infrastructure.

### Simulation

Responsible for vehicle movement, traffic signal logic,
animation and simulation state.

### Input

Responsible for keyboard, mouse and camera controls.

## 4. Graphics Architecture

The rendering pipeline shall implement:

1. Model transformation.
2. View transformation.
3. Projection transformation.
4. Geometry clipping.
5. Perspective division.
6. Viewport transformation.
7. Rasterization and fragment processing.
8. Framebuffer output.

## 5. Viewing System

The viewing system shall support:

- Explicit viewing window boundaries.
- Configurable orthographic projection.
- Configurable perspective projection.
- Near and far clipping planes.
- Window-to-viewport coordinate mapping.
- Camera translation and rotation.
- Camera zoom.
- Aspect ratio correction.
- Framebuffer resize handling.

The graphics viewing window shall be treated separately
from the operating system application window.

## 6. Proposed Components

| Component | Responsibility |
| --- | --- |
| Application | Application lifecycle |
| Window | GLFW window and context |
| Renderer | OpenGL rendering operations |
| Shader | GLSL shader management |
| Camera | Viewing transformations |
| ViewingWindow | Visible coordinate boundaries |
| Viewport | Screen coordinate mapping |
| Projection | Projection matrix management |
| Mesh | Geometry representation |
| Scene | Scene object management |
| Vehicle | Vehicle representation and movement |
| TrafficLight | Traffic signal state management |
| Simulation | Simulation update management |
| InputManager | Keyboard and mouse interactions |

## 7. Build Requirements

- C++17 compatible compiler.
- CMake 3.24 or later.
- Ninja build system.
- OpenGL 3.3 compatible graphics driver.
- GLFW, GLAD and GLM dependencies.

Debug and Release build configurations shall be supported.

## 8. Coding Standards

- Use descriptive identifiers.
- Separate declarations and implementations where appropriate.
- Prefer RAII for resource ownership.
- Use standard C++ containers and smart pointers.
- Avoid unnecessary global mutable state.
- Enable compiler warnings.
- Format code using ClangFormat.
- Validate source code using Clang-Tidy.

## 9. Testing Requirements

- Application initialization tests.
- Graphics mathematics tests.
- Viewing window coordinate mapping tests.
- Projection matrix tests.
- Viewport resizing tests.
- Traffic light state tests.
- Vehicle movement tests.
- Manual graphics rendering validation.

## 10. Error Handling

The application shall report failures involving:

- GLFW initialization.
- OpenGL context creation.
- GLAD initialization.
- Shader compilation and linking.
- Asset loading.
- Invalid graphics configuration.

Application resources shall be released correctly when
initialization fails or the application terminates.

## 11. Deployment

The primary target platform is Windows x64.

The application shall be built using the MSYS2 UCRT64
toolchain and executed as a native Windows application.

Required runtime libraries shall be documented and included
in the distribution process where redistribution permits.
