# UrbanFlow - Testing Strategy

## Objectives

Ensure that UrbanFlow is stable, mathematically correct
and compliant with the computer graphics requirements.

## Testing Categories

- Environment validation
- Build validation
- Unit testing
- Graphics mathematics testing
- Visual rendering testing
- Integration testing
- Performance testing
- Regression testing

## Test Cases

| ID | Test Case | Expected Result |
| --- | --- | --- |
| TC-001 | Application compilation | Successful build |
| TC-002 | GLFW initialization | Initialization succeeds |
| TC-003 | OpenGL context creation | Compatible context available |
| TC-004 | GLAD initialization | OpenGL functions loaded |
| TC-005 | Shader compilation | No compilation errors |
| TC-006 | Basic geometry rendering | Geometry appears correctly |
| TC-007 | Viewing window boundaries | Correct visible region |
| TC-008 | Coordinate mapping | Expected viewport coordinates |
| TC-009 | Invalid viewing boundaries | Invalid input rejected |
| TC-010 | Orthographic projection | Correct parallel projection |
| TC-011 | Perspective projection | Correct depth perception |
| TC-012 | Geometry clipping | External geometry clipped |
| TC-013 | Framebuffer resizing | No unintended distortion |
| TC-014 | Camera navigation | Correct viewing transformation |
| TC-015 | Projection switching | Both modes operate correctly |
| TC-016 | Vehicle movement | Correct animation |
| TC-017 | Traffic signal sequence | Correct state transitions |
| TC-018 | Simulation pause | Simulation updates stop |
| TC-019 | Resource cleanup | Clean application termination |
| TC-020 | Performance | Responsive real-time rendering |

## Viewing Window Validation

For a world window ranging from (0, 0) to (100, 100)
and a viewport ranging from (0, 0) to (800, 600):

- (0, 0) maps to (0, 0).
- (50, 50) maps to (400, 300).
- (100, 100) maps to (800, 600).

These expected results assume independent axis scaling.

Aspect-ratio-preserving mapping shall be tested separately.

## Automated Testing

CTest shall execute mathematical and simulation tests.

Graphics rendering shall additionally be validated through
manual application execution and visual inspection.

## Acceptance Criteria

- Successful compilation.
- No unresolved critical defects.
- All mandatory viewing requirements demonstrated.
- Relevant automated tests pass.
- Stable execution during the academic demonstration.

## Current Status

The development compiler has been verified.

Application-level tests remain pending implementation.
