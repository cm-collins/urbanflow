# UrbanFlow - Project Requirements Document

## 1. Project Overview

UrbanFlow is an interactive 3D urban traffic simulation
developed using C++ and OpenGL for the Computer Graphics unit.

The project demonstrates computer graphics principles through
a simulated urban environment containing roads, buildings,
vehicles, traffic lights and interactive viewing controls.

## 2. Project Objectives

- Demonstrate real-time 3D graphics rendering.
- Implement viewing window and viewport transformations.
- Demonstrate orthographic and perspective projections.
- Apply translation, rotation and scaling.
- Implement real-time vehicle animation.
- Simulate basic urban traffic management.
- Demonstrate lighting, shading and geometry clipping.

## 3. Functional Requirements

| ID | Requirement | Priority |
| --- | --- | --- |
| FR-001 | Initialize OpenGL 3.3 Core | Mandatory |
| FR-002 | Create a resizable application window | Mandatory |
| FR-003 | Render a 3D urban environment | Mandatory |
| FR-004 | Animate vehicles along defined routes | Mandatory |
| FR-005 | Implement traffic light sequences | Mandatory |
| FR-006 | Provide interactive camera controls | Mandatory |
| FR-007 | Implement lighting and shading | Mandatory |
| FR-008 | Support simulation pause and resume | Mandatory |
| FR-009 | Implement vehicle collision prevention | High |
| FR-010 | Implement day and night transitions | High |
| FR-011 | Implement pedestrian animation | Optional |
| FR-012 | Implement emergency vehicle priority | Optional |
| FR-013 | Implement environmental weather effects | Optional |

## 4. Viewing Window Requirements

The viewing window is a mandatory academic requirement.

| ID | Requirement |
| --- | --- |
| VW-001 | Define explicit viewing window boundaries |
| VW-002 | Implement window-to-viewport mapping |
| VW-003 | Implement orthographic projection |
| VW-004 | Implement perspective projection |
| VW-005 | Demonstrate geometry clipping |
| VW-006 | Preserve aspect ratio during resizing |
| VW-007 | Support camera movement and zoom |
| VW-008 | Support switching between projection modes |

## 5. Non-Functional Requirements

- Target smooth rendering at 60 frames per second.
- Provide responsive keyboard and mouse controls.
- Maintain a modular and readable codebase.
- Handle initialization failures gracefully.
- Release allocated graphics resources correctly.
- Provide reproducible build instructions.
- Support execution on Windows with compatible OpenGL drivers.

## 6. Minimum Viable Product

The minimum viable product shall contain:

- One functional 3D road intersection.
- Buildings and basic urban infrastructure.
- Multiple animated vehicles.
- Functional traffic lights.
- Interactive camera controls.
- Orthographic and perspective viewing modes.
- Viewing window and viewport demonstrations.
- Basic lighting and shading.

## 7. Out of Scope

- Real-world GPS integration.
- Multiplayer functionality.
- Online traffic data integration.
- Photorealistic city rendering.
- Large-scale traffic engineering analysis.
- Advanced vehicle physics.

## 8. Project Deliverables

- Working UrbanFlow desktop application.
- Complete C++ source code.
- GitHub repository.
- Project and technical documentation.
- Computer graphics architecture documentation.
- Testing and validation results.
- Installation and execution instructions.
- Academic presentation and live demonstration.

## 9. Expected Outcomes

The completed application should demonstrate an interactive
urban environment with animated traffic and clearly observable
computer graphics transformations.

The project should provide a practical demonstration of viewing
windows, viewport mapping, projection, clipping, lighting,
3D transformations and real-time rendering.

## 10. Success Criteria

- The application builds and executes successfully.
- All mandatory functional requirements are satisfied.
- All viewing window requirements are demonstrated.
- Vehicles respond correctly to traffic signals.
- Camera controls operate correctly.
- Window resizing does not distort the rendered scene.
- The application remains stable during demonstrations.
- The source code and documentation are complete.
