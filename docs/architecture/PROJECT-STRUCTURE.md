# UrbanFlow - Project Structure

## Source Directories

| Directory | Responsibility |
| --- | --- |
| src/core | Application lifecycle and window management |
| src/graphics | Rendering and viewing transformations |
| src/scene | Urban environment and graphical objects |
| src/simulation | Traffic logic and animation |
| src/input | Keyboard and mouse interaction |
| include/urbanflow | Public C++ headers |
| shaders | GLSL shader programs |
| external | Third-party source dependencies |
| assets/models | Three-dimensional models |
| assets/textures | Surface textures |
| assets/fonts | Interface fonts |
| tests | Automated validation |
| scripts | Build and development automation |
| docs | Project documentation |
| .github/workflows | Continuous integration |
| .vscode | Development environment configuration |

## Planned Graphics Components

- Application
- Window
- Renderer
- Shader
- Camera
- ViewingWindow
- Viewport
- Projection
- Mesh
- Scene

## Architecture Principles

- Separation of concerns.
- Explicit graphics transformations.
- Predictable resource ownership.
- Reusable rendering components.
- Independent simulation logic.
- Testable mathematical operations.

## Dependency Direction

Application coordinates the rendering, input and
simulation components.

Simulation logic should not depend directly on OpenGL.

Viewing mathematics should be independently testable
without creating an application window.

## Build Outputs

Generated build artifacts shall be stored in build/.

Generated binaries and temporary files shall not be
committed to the Git repository.

## Directory Tracking

Git does not track empty directories.

Directories will become tracked as their implementation
files are introduced.
