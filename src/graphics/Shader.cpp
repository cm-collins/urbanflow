#include "urbanflow/Shader.hpp"

#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>

namespace urbanflow {

namespace {

std::string readFile(const std::filesystem::path& path) {
    std::ifstream file(path);

    if (!file.is_open()) {
        throw std::runtime_error("Failed to open shader: " + path.string());
    }

    std::ostringstream stream;
    stream << file.rdbuf();

    return stream.str();
}

GLuint compileShader(GLenum type, const std::string& source) {
    GLuint shader = glCreateShader(type);

    const char* sourceCode = source.c_str();

    glShaderSource(shader, 1, &sourceCode, nullptr);
    glCompileShader(shader);

    GLint success = GL_FALSE;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

    if (success != GL_TRUE) {
        char log[2048]{};

        glGetShaderInfoLog(shader, sizeof(log), nullptr, log);

        glDeleteShader(shader);

        throw std::runtime_error(std::string("Shader compilation failed: ") + log);
    }

    return shader;
}

} // namespace

Shader::Shader(const std::filesystem::path& vertexPath, const std::filesystem::path& fragmentPath) {
    GLuint vertexShader = 0;
    GLuint fragmentShader = 0;

    try {
        vertexShader = compileShader(GL_VERTEX_SHADER, readFile(vertexPath));

        fragmentShader = compileShader(GL_FRAGMENT_SHADER, readFile(fragmentPath));

        programId_ = glCreateProgram();

        glAttachShader(programId_, vertexShader);
        glAttachShader(programId_, fragmentShader);
        glLinkProgram(programId_);

        GLint success = GL_FALSE;

        glGetProgramiv(programId_, GL_LINK_STATUS, &success);

        if (success != GL_TRUE) {
            char log[2048]{};

            glGetProgramInfoLog(programId_, sizeof(log), nullptr, log);

            throw std::runtime_error(std::string("Shader linking failed: ") + log);
        }
    } catch (...) {
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);

        if (programId_ != 0) {
            glDeleteProgram(programId_);
        }

        throw;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

Shader::~Shader() {
    if (programId_ != 0) {
        glDeleteProgram(programId_);
    }
}

void Shader::use() const {
    glUseProgram(programId_);
}

GLuint Shader::id() const {
    return programId_;
}

} // namespace urbanflow
