#pragma once

#include <vector>
#include <GL/glew.h>
#include "common.hpp"
#include "glm.hpp"

namespace glimac {

class Cube {

    struct ShapeVertex {
        glm::vec3 position;
        glm::vec3 normal;
        glm::vec2 texCoords;
    };

    struct Vertex3D {
        glm::vec3 position;
        glm::vec3 normal;
        glm::vec2 texCoords;
    };

    void build(GLfloat width, GLfloat height, GLfloat thickness);

public:
    Cube() { build (1,1,1); }
    Cube(GLfloat width, GLfloat height, GLfloat thickness)
    {
        build(width, height, thickness);
    }

    void setVbo();
    void setIbo();
    void setVao();

    const Vertex3D* getVertexBuffer() const {
        return &_vertexBuffer[0];
    }

    size_t getVertexCount() const {
        return 24;
    }

    const unsigned int* getIndexBuffer() const {
        return &_indexBuffer[0];
    }

    size_t getIndexCount() const {
        return 36;
    }

    void drawCube() const
    {
        glDrawElements(GL_TRIANGLES, this->getIndexCount()-6, GL_UNSIGNED_INT, 0);
    }

    GLuint getVbo();
    GLuint getIbo();
    GLuint getVao();

private:
    GLuint _vao;
    GLuint _vbo;
    GLuint _ibo;
    Vertex3D _vertexBuffer[24];
    uint32_t _indexBuffer[36];
};

}