# UrbanFlow - Graphics Architecture

## Overview

UrbanFlow uses modern OpenGL to render an interactive
three-dimensional urban environment.

The graphics architecture separates geometry, shaders,
viewing transformations and rendering operations.

## Rendering Pipeline

1. Vertex input.
2. Model transformation.
3. View transformation.
4. Projection transformation.
5. Clipping.
6. Perspective division.
7. Viewport transformation.
8. Rasterization.
9. Fragment processing.
10. Framebuffer output.

## Coordinate Systems

- Local coordinates
- World coordinates
- View coordinates
- Clip coordinates
- Normalized device coordinates
- Screen coordinates

## Transformation Model

ClipPosition = Projection * View * Model * LocalPosition

## Viewing Window

The viewing window defines the coordinate region selected
for display.

The viewport defines the destination region within the
application framebuffer.

The implementation shall explicitly demonstrate the
relationship between these two concepts.

## Projection

UrbanFlow shall support:

- Orthographic projection.
- Perspective projection.
- Configurable near and far clipping planes.
- Aspect ratio preservation.
- Runtime projection switching.

## Rendering Components

### Renderer

Coordinates OpenGL rendering operations.

### Shader

Compiles and manages GLSL shader programs.

### Mesh

Stores vertex and index information.

### Camera

Controls viewing position and orientation.

### ViewingWindow

Defines visible coordinate boundaries.

### Viewport

Manages screen coordinate mapping and framebuffer dimensions.

### Projection

Calculates orthographic and perspective projection matrices.

## Graphics Resource Management

OpenGL resources must be released before destroying
the associated OpenGL context.

Resource ownership should follow RAII principles.

## Graphics Validation

- Verify OpenGL context creation.
- Verify shader compilation and linking.
- Verify basic geometry rendering.
- Verify coordinate transformation mathematics.
- Verify clipping behaviour.
- Verify viewport resizing.
- Verify projection switching.
