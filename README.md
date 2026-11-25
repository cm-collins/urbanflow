@'
# UrbanFlow

An interactive 3D urban traffic simulation built using C++ and OpenGL.

## Overview

UrbanFlow is an academic computer graphics project designed
to demonstrate real-time rendering, 3D modelling, viewing
transformations, animation and interactive simulation.

The application simulates an urban environment containing
roads, buildings, vehicles, traffic lights and other city
infrastructure.

## Project Objectives

- Implement a functional OpenGL rendering application.
- Demonstrate viewing window and viewport transformations.
- Implement orthographic and perspective projections.
- Demonstrate translation, rotation and scaling.
- Develop an interactive 3D urban environment.
- Simulate vehicle movement and traffic management.
- Apply lighting, shading and animation techniques.

## Core Features

- Interactive 3D urban environment
- Resizable OpenGL application window
- Viewing window and viewport mapping
- Orthographic and perspective camera modes
- Geometry clipping
- Animated vehicles
- Traffic light simulation
- Camera navigation and zoom
- Simulation pause and resume

## Technology Stack

| Technology | Purpose |
| --- | --- |
| C++17 | Application development |
| OpenGL 3.3 Core | Graphics rendering |
| GLFW | Window management and input |
| GLAD | OpenGL function loading |
| GLM | Graphics mathematics |
| GCC / MinGW-w64 | Compilation |
| CMake | Build configuration |
| Ninja | Build automation |
| GDB | Debugging |
| MSYS2 UCRT64 | Dependency management |
| Visual Studio Code | Development environment |

## Project Structure

- src/ - Application source code
- include/ - C++ header files
- assets/ - Models, textures and fonts
- shaders/ - GLSL shader programs
- external/ - Third-party dependencies
- tests/ - Automated tests
- docs/ - Project documentation
- scripts/ - Development and validation scripts

## Documentation

- [Project Requirements](docs/PRD.md)
- [Technical Requirements](docs/TRD.md)
- [Graphics Architecture](docs/architecture/GRAPHICS.md)
- [Viewing Window](docs/architecture/VIEWING-WINDOW.md)
- [Development Roadmap](ROADMAP.md)
- [Contribution Guidelines](CONTRIBUTING.md)

## Development Status

UrbanFlow is currently in Sprint 0: Project Foundation.

The application is not yet ready for distribution.
Build and execution instructions will be added after the
initial rendering application has been implemented.

## Academic Context

This project is developed for the Computer Graphics unit
to demonstrate practical applications of computer graphics
principles using C++ and OpenGL.
'@ | Set-Content -Encoding UTF8 README.md