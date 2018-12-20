#include <cmath>
#include <vector>
#include <iostream>
#include "glimac/common.hpp"
#include "glimac/Cube.hpp"

namespace glimac {

void Cube::build(GLfloat width, GLfloat height, GLfloat thickness) {

    float w,h,t;
    w = width/2;        // 0.5
    h = height/2;       // 0.5
    t = thickness/2;    // 0.5

    // Build all vertices
    // Front face
    _vertexBuffer[0].position = glm::vec3(-w, -h, t);     // Bottom Left
    _vertexBuffer[1].position = glm::vec3(w, -h, t);      // Bottom Right
    _vertexBuffer[2].position = glm::vec3(w, h, t);       // Up Right
    _vertexBuffer[3].position = glm::vec3(-w, h, t);      // Up Left
    // Back Face
    _vertexBuffer[4].position = glm::vec3(-w, -h, -t);     // Bottom Left
    _vertexBuffer[5].position = glm::vec3(w, -h, -t);      // Bottom Right
    _vertexBuffer[6].position = glm::vec3(w, h, -t);       // Up Right
    _vertexBuffer[7].position = glm::vec3(-w, h, -t);      // Up Left
    // Upper Face
    _vertexBuffer[8].position = glm::vec3(-w, h, t);     // Bottom Left
    _vertexBuffer[9].position = glm::vec3(w, h, t);      // Bottom Right
    _vertexBuffer[10].position = glm::vec3(w, h, -t);       // Up Right
    _vertexBuffer[11].position = glm::vec3(-w, h, -t);      // Up Left
    // Bottom Face
    _vertexBuffer[12].position = glm::vec3(-w, -h, t);     // Bottom Left
    _vertexBuffer[13].position = glm::vec3(w, -h, t);      // Bottom Right
    _vertexBuffer[14].position = glm::vec3(w, -h, -t);       // Up Right
    _vertexBuffer[15].position = glm::vec3(-w, h, -t);      // Up Left
    // Left Face
    _vertexBuffer[16].position = glm::vec3(-w, -h, t);     // Bottom Left
    _vertexBuffer[17].position = glm::vec3(-w, -h, -t);      // Bottom Right
    _vertexBuffer[18].position = glm::vec3(-w, h, -t);       // Up Right
    _vertexBuffer[19].position = glm::vec3(-w, h, t);      // Up Left
    // Right Face
    _vertexBuffer[20].position = glm::vec3(w, -h, t);     // Bottom Left
    _vertexBuffer[21].position = glm::vec3(w, -h, -t);      // Bottom Right
    _vertexBuffer[22].position = glm::vec3(w, h, -t);       // Up Right
    _vertexBuffer[23].position = glm::vec3(w, h, t);      // Up Left

    // Front Face
    _vertexBuffer[0].normal = glm::vec3(0, 0, 1);     // Bottom Left
    _vertexBuffer[1].normal = glm::vec3(0, 0, 1);      // Bottom Right
    _vertexBuffer[2].normal = glm::vec3(0, 0, 1);       // Up Right
    _vertexBuffer[3].normal = glm::vec3(0, 0, 1);      // Up Left
    // Back Face
    _vertexBuffer[4].normal = glm::vec3(0, 0, -1);     // Bottom Left
    _vertexBuffer[5].normal = glm::vec3(0, 0, -1);      // Bottom Right
    _vertexBuffer[6].normal = glm::vec3(0, 0, -1);       // Up Right
    _vertexBuffer[7].normal = glm::vec3(0, 0, -1);      // Up Left
    // Upper Face
    _vertexBuffer[8].normal = glm::vec3(0, 1, 0);     // Bottom Left
    _vertexBuffer[9].normal = glm::vec3(0, 1, 0);      // Bottom Right
    _vertexBuffer[10].normal = glm::vec3(0, 1, 0);       // Up Right
    _vertexBuffer[11].normal = glm::vec3(0, 1, 0);      // Up Left
    // Bottom Face
    _vertexBuffer[12].normal = glm::vec3(0, -1, 0);     // Bottom Left
    _vertexBuffer[13].normal = glm::vec3(0, -1, 0);      // Bottom Right
    _vertexBuffer[14].normal = glm::vec3(0, -1, 0);       // Up Right
    _vertexBuffer[15].normal = glm::vec3(0, -1, 0);      // Up Left
    // Left Face
    _vertexBuffer[16].normal = glm::vec3(-1, 0, 0);     // Bottom Left
    _vertexBuffer[17].normal = glm::vec3(-1, 0, 0);      // Bottom Right
    _vertexBuffer[18].normal = glm::vec3(-1, 0, 0);       // Up Right
    _vertexBuffer[19].normal = glm::vec3(-1, 0, 0);      // Up Left
        // Bottom Face
    _vertexBuffer[20].normal = glm::vec3(1, 0, 0);     // Bottom Left
    _vertexBuffer[21].normal = glm::vec3(1, 0, 0);      // Bottom Right
    _vertexBuffer[22].normal = glm::vec3(1, 0, 0);       // Up Right
    _vertexBuffer[23].normal = glm::vec3(1, 0, 0);      // Up Left

    // Texture Coordinates
    for (int i = 0; i < (int)this->getVertexCount(); i = i + 4)
    {
        _vertexBuffer[i].texCoords = glm::vec2(0,1);
        _vertexBuffer[i+1].texCoords = glm::vec2(1,1);
        _vertexBuffer[i+2].texCoords = glm::vec2(1,0);
        _vertexBuffer[i+3].texCoords = glm::vec2(0,0);
    }

    // Front face
    _indexBuffer[0] = 0;
    _indexBuffer[1] = 1;
    _indexBuffer[2] = 2;

    _indexBuffer[3] = 0;
    _indexBuffer[4] = 2;
    _indexBuffer[5] = 3;

    // Left face
    _indexBuffer[6] = 16;
    _indexBuffer[7] = 17;
    _indexBuffer[8] = 18;

    _indexBuffer[9] = 16;
    _indexBuffer[10] = 18;
    _indexBuffer[11] = 19;

    // Back Face
    _indexBuffer[12] = 4;
    _indexBuffer[13] = 7;
    _indexBuffer[14] = 5;

    _indexBuffer[15] = 5;
    _indexBuffer[16] = 6;
    _indexBuffer[17] = 7;

    // Right Face
    _indexBuffer[18] = 20;
    _indexBuffer[19] = 21;
    _indexBuffer[20] = 22;

    _indexBuffer[21] = 20;
    _indexBuffer[22] = 22;
    _indexBuffer[23] = 23;

    // Upper Face
    _indexBuffer[24] = 2;
    _indexBuffer[25] = 6;
    _indexBuffer[26] = 7;

    _indexBuffer[27] = 2;
    _indexBuffer[28] = 7;
    _indexBuffer[29] = 3;

    // Bottom Face
    _indexBuffer[30] = 0;
    _indexBuffer[31] = 1;
    _indexBuffer[32] = 4;

    _indexBuffer[33] = 1;
    _indexBuffer[34] = 4;
    _indexBuffer[35] = 5;

    // Upper Face
    _indexBuffer[24] = 8;
    _indexBuffer[25] = 9;
    _indexBuffer[26] = 10;

    _indexBuffer[27] = 8;
    _indexBuffer[28] = 10;
    _indexBuffer[29] = 11;

    // Bottom Face
    _indexBuffer[30] = 12;
    _indexBuffer[31] = 13;
    _indexBuffer[32] = 14;

    _indexBuffer[33] = 12;
    _indexBuffer[34] = 14;
    _indexBuffer[35] = 15;
}

void Cube::setVbo(){
    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, this->getVertexCount() * sizeof(Vertex3D), this->getVertexBuffer(), GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    _vbo = vbo;
}

void Cube::setIbo(){
    GLuint ibo;
    glGenBuffers(1, &ibo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->getVertexCount() * sizeof(uint32_t), this->getIndexBuffer(), GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    _ibo = ibo;
}


void Cube::setVao(){
    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ibo);

    const GLuint VERTEX_ATTR_POSITION = 0;
    const GLuint VERTEX_ATTR_NORMAL = 1;
    const GLuint VERTEX_ATTR_TEXCOORD = 2;
    glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
    glEnableVertexAttribArray(VERTEX_ATTR_NORMAL);
    glEnableVertexAttribArray(VERTEX_ATTR_TEXCOORD);

    glBindBuffer(GL_ARRAY_BUFFER, _vbo);
    glVertexAttribPointer(VERTEX_ATTR_POSITION, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex3D), (const GLvoid*) offsetof(Vertex3D, position));
    glVertexAttribPointer(VERTEX_ATTR_NORMAL, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex3D), (const GLvoid*) offsetof(Vertex3D, normal));
    glVertexAttribPointer(VERTEX_ATTR_TEXCOORD, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex3D), (const GLvoid*) offsetof(Vertex3D, texCoords));
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);
    _vao = vao;
}

GLuint Cube::getVbo()
{
    return _vbo;
}

GLuint Cube::getIbo()
{
    return _ibo;
}

GLuint Cube::getVao()
{
    return _vao;
}

}