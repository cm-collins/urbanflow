#include <glad/gl.h>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include "urbanflow/Mesh.hpp"
#include "urbanflow/Shader.hpp"

#include <algorithm>
#include <cstdlib>
#include <exception>
#include <filesystem>
#include <iostream>
#include <vector>

namespace {

constexpr int WINDOW_WIDTH = 1280;
constexpr int WINDOW_HEIGHT = 720;

void framebufferSizeCallback(GLFWwindow*, int width, int height) {
    const int size = std::min(width, height);

    const int x = (width - size) / 2;
    const int y = (height - size) / 2;

    glViewport(x, y, size, size);
}

void errorCallback(int error, const char* description) {
    std::cerr << "GLFW error " << error << ": " << description << '\n';
}

void processInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

} // namespace

int main(int argc, char* argv[]) {
    glfwSetErrorCallback(errorCallback);

    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW.\n";
        return EXIT_FAILURE;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

    GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT,
                                          "UrbanFlow | Geometry Rendering", nullptr, nullptr);

    if (!window) {
        glfwTerminate();
        return EXIT_FAILURE;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGL(glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD.\n";

        glfwDestroyWindow(window);
        glfwTerminate();

        return EXIT_FAILURE;
    }

    glfwSwapInterval(1);

    int width = 0;
    int height = 0;

    glfwGetFramebufferSize(window, &width, &height);

    framebufferSizeCallback(window, width, height);

    glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);

    int exitCode = EXIT_SUCCESS;

    try {
        const auto executableDirectory =
            std::filesystem::absolute(argc > 0 ? argv[0] : "UrbanFlow.exe").parent_path();

        const auto shaderDirectory = executableDirectory / "shaders";

        urbanflow::Shader shader(shaderDirectory / "basic.vert", shaderDirectory / "basic.frag");

        const std::vector<urbanflow::Vertex> vertices = {{0.0F, 0.6F, 0.0F, 1.0F, 0.0F, 0.0F},
                                                         {-0.6F, -0.6F, 0.0F, 0.0F, 1.0F, 0.0F},
                                                         {0.6F, -0.6F, 0.0F, 0.0F, 0.0F, 1.0F}};

        urbanflow::Mesh triangle(vertices);

        std::cout << "UrbanFlow initialized successfully.\n";

        std::cout << "OpenGL version: " << glGetString(GL_VERSION) << '\n';

        std::cout << "Graphics renderer: " << glGetString(GL_RENDERER) << '\n';

        std::cout << "Shader program initialized successfully.\n";

        std::cout << "Triangle mesh initialized successfully.\n";

        while (!glfwWindowShouldClose(window)) {
            processInput(window);

            glClearColor(0.06F, 0.10F, 0.16F, 1.0F);

            glClear(GL_COLOR_BUFFER_BIT);

            shader.use();
            triangle.draw();

            glfwSwapBuffers(window);
            glfwPollEvents();
        }

    } catch (const std::exception& exception) {
        std::cerr << "UrbanFlow error: " << exception.what() << '\n';

        exitCode = EXIT_FAILURE;
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    std::cout << "UrbanFlow closed successfully.\n";

    return exitCode;
}
