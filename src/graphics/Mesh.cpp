#include "urbanflow/Mesh.hpp"

#include <cstddef>
#include <limits>
#include <stdexcept>

namespace urbanflow {

Mesh::Mesh(const std::vector<Vertex>& vertices) {
    if (vertices.empty() || vertices.size() % 3 != 0 ||
        vertices.size() > static_cast<std::size_t>(std::numeric_limits<GLsizei>::max())) {
        throw std::invalid_argument("Invalid triangle mesh vertex count.");
    }

    vertexCount_ = static_cast<GLsizei>(vertices.size());

    glGenVertexArrays(1, &vao_);
    glGenBuffers(1, &vbo_);

    glBindVertexArray(vao_);
    glBindBuffer(GL_ARRAY_BUFFER, vbo_);

    glBufferData(GL_ARRAY_BUFFER, static_cast<GLsizeiptr>(vertices.size() * sizeof(Vertex)),
                 vertices.data(), GL_STATIC_DRAW);

    // Vertex position.
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                          reinterpret_cast<void*>(offsetof(Vertex, x)));

    glEnableVertexAttribArray(0);

    // Vertex colour.
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                          reinterpret_cast<void*>(offsetof(Vertex, red)));

    glEnableVertexAttribArray(1);

    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

Mesh::~Mesh() {
    if (vbo_ != 0) {
        glDeleteBuffers(1, &vbo_);
    }

    if (vao_ != 0) {
        glDeleteVertexArrays(1, &vao_);
    }
}

void Mesh::draw() const {
    glBindVertexArray(vao_);

    glDrawArrays(GL_TRIANGLES, 0, vertexCount_);

    glBindVertexArray(0);
}

} // namespace urbanflow
