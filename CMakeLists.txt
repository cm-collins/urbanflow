cmake_minimum_required(VERSION 3.24)

project(
    UrbanFlow
    VERSION 0.1.0
    DESCRIPTION "Interactive 3D urban traffic simulation"
    LANGUAGES C CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)

# Third-party OpenGL function loader.
add_library(glad STATIC
    external/glad/src/gl.c
)

target_include_directories(glad PUBLIC
    external/glad/include
)

# UrbanFlow application.
add_executable(UrbanFlow
    src/main.cpp
    src/graphics/Shader.cpp
    src/graphics/Mesh.cpp
)

target_include_directories(UrbanFlow PRIVATE
    include
)

target_link_libraries(UrbanFlow PRIVATE
    glad
    glfw
    glm::glm
    OpenGL::GL
)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(UrbanFlow PRIVATE
        -Wall
        -Wextra
        -Wpedantic
    )
endif()

set_target_properties(UrbanFlow PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)


include(CTest)

add_custom_command(
    TARGET UrbanFlow
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_SOURCE_DIR}/shaders"
        "$<TARGET_FILE_DIR:UrbanFlow>/shaders"
    COMMENT "Copying UrbanFlow shaders"
)
