# UrbanFlow - Development Guidelines

## Coding Standards

- Use C++17.
- Follow the configured ClangFormat style.
- Use meaningful identifiers.
- Keep functions focused and manageable.
- Separate application logic from rendering logic.
- Prefer RAII for resource management.
- Avoid unnecessary global mutable state.
- Document complex graphics mathematics.
- Avoid committing generated build files.

## Branch Naming

- feature/short-description
- fix/short-description
- docs/short-description
- chore/short-description
- test/short-description

## Commit Message Format

Every project commit should contain:

1. An appropriate icon.
2. A descriptive commit type and title.
3. A body explaining the changes.

Supported commit types:

- feat: New functionality
- fix: Bug fixes
- docs: Documentation
- refactor: Code restructuring
- test: Testing
- chore: Maintenance
- build: Build configuration
- ci: Continuous integration
- perf: Performance improvements
- style: Formatting

## Validation Requirements

Before committing implementation changes:

- Ensure the project builds successfully.
- Resolve compiler warnings introduced by the changes.
- Run relevant automated tests.
- Format modified C++ files.
- Update relevant documentation.

## Graphics Requirements

Changes involving the viewing system must preserve:

- Correct viewing window boundaries.
- Correct viewport transformations.
- Correct projection behaviour.
- Geometry clipping.
- Aspect ratio preservation.

## Dependency Management

Use the MSYS2 UCRT64 development environment.

Do not mix incompatible compiler toolchains or
third-party library architectures.

Document all additional dependencies.
