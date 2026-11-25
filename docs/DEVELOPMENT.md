# UrbanFlow - Development Guide

## Development Environment

UrbanFlow uses Visual Studio Code and the MSYS2 UCRT64
development toolchain on Windows.

## Required Tools

- GCC and G++ 16.2.0
- CMake 4.5.1
- Ninja 1.13.2
- GDB 18.1
- ClangFormat
- Clang-Tidy
- Git

## Graphics Dependencies

- GLFW 3.5.1
- GLM 1.0.3
- GLAD (pending integration)
- OpenGL 3.3 Core

## Environment Configuration

Add the following directory to the Windows user PATH:

C:\msys64\ucrt64\bin

Verify the environment using:

    g++ --version
    cmake --version
    ninja --version
    gdb --version

## Development Workflow

1. Select a development task.
2. Create a dedicated Git branch.
3. Implement the required functionality.
4. Format the source code.
5. Build the application.
6. Execute relevant tests.
7. Update documentation.
8. Commit and push changes.

## Planned Build Commands

After CMake presets have been implemented:

    cmake --preset debug
    cmake --build --preset debug
    ctest --preset debug

## Graphics Development

The viewing window and rendering foundation must be
implemented before developing the urban environment.

Validate each graphics component independently before
integrating it into the main application.

## Dependency Management

Use MSYS2 UCRT64 to manage system dependencies.

Do not mix MSVC, MINGW64 and UCRT64 compiled libraries.
