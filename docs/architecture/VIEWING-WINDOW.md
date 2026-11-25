# Viewing Window Specification

## Purpose

The viewing window is a mandatory requirement of the
Computer Graphics assignment.

It defines the coordinate region of the virtual environment
that is selected for display.

## Viewing Window and Viewport

The viewing window defines the visible coordinate boundaries.
The viewport defines the destination region in screen coordinates.

These concepts are distinct from the operating system window
created using GLFW.

## Viewing Window Boundaries

- X minimum
- X maximum
- Y minimum
- Y maximum

Three-dimensional viewing additionally requires near and far
clipping boundaries.

## Window-to-Viewport Mapping

Sx = (Vxmax - Vxmin) / (Wxmax - Wxmin)

Sy = (Vymax - Vymin) / (Wymax - Wymin)

Xv = Vxmin + (Xw - Wxmin) * Sx

Yv = Vymin + (Yw - Wymin) * Sy

The implementation shall reject invalid viewing boundaries
and handle aspect ratio preservation.

## Projection Modes

### Orthographic Projection

Displays objects without perspective-based size reduction.

Suitable for top-down traffic monitoring and demonstrating
explicit viewing window boundaries.

### Perspective Projection

Displays distant objects smaller than nearby objects.

Suitable for immersive three-dimensional city visualization.

## Clipping

Geometry outside the viewing volume shall be clipped using
the OpenGL graphics pipeline.

A dedicated demonstration shall show objects entering and
leaving the visible viewing region.

## Resizing

The application shall update the OpenGL viewport when the
framebuffer dimensions change.

Projection parameters shall be recalculated to preserve
the intended aspect ratio.

## Planned Controls

| Control | Action |
| --- | --- |
| W/A/S/D | Move camera |
| Mouse | Rotate camera |
| Scroll | Zoom |
| O | Orthographic projection |
| P | Perspective projection |
| V | Toggle viewing boundary visualization |
| Space | Pause or resume simulation |
| R | Reset camera |
| Escape | Close application |

## Acceptance Criteria

- Viewing boundaries are explicitly defined.
- Coordinate mapping produces correct results.
- Orthographic and perspective modes operate correctly.
- Projection switching works during execution.
- Geometry clipping is visually demonstrated.
- Resizing does not cause unintended distortion.
- Camera movement and zoom operate correctly.
- Coordinate mapping is covered by automated tests.
