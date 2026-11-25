#pragma once

#include <glad/gl.h>

#include <vector>

namespace urbanflow {

struct Vertex {
    float x;
    float y;
    float z;

    float red;
    float green;
    float blue;
};

class Mesh {
  public:
    explicit Mesh(const std::vector<Vertex>& vertices);

    ~Mesh();

    Mesh(const Mesh&) = delete;
    Mesh& operator=(const Mesh&) = delete;

    void draw() const;

  private:
    GLuint vao_ = 0;
    GLuint vbo_ = 0;
    GLsizei vertexCount_ = 0;
};

} // namespace urbanflow
