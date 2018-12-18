#pragma once

#include <GL/glew.h>
#include "glm.hpp"

namespace glimac {

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

float norm(glm::vec3 V);

glm::vec3 normalize(glm::vec3 V);

// Returns the VBO, IBO and VAO of an object made with Vertex3D
GLuint VBO(GLsizeiptr size, const GLvoid* data);
GLuint IBO(GLsizeiptr size, const GLvoid* data);
GLuint VAO(GLuint* ibo, GLuint* vbo);

}