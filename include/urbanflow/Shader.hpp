#pragma once

#include <filesystem>
#include <glad/gl.h>

namespace urbanflow {

class Shader {
  public:
    Shader(const std::filesystem::path& vertexPath, const std::filesystem::path& fragmentPath);

    ~Shader();

    Shader(const Shader&) = delete;
    Shader& operator=(const Shader&) = delete;

    void use() const;

    [[nodiscard]] GLuint id() const;

  private:
    GLuint programId_ = 0;
};

} // namespace urbanflow
