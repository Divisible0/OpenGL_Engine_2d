#pragma once
#include "config.h"

struct Mesh {
    unsigned int VAO; 
    unsigned int VBO;
    int vertexCount;
    GLenum mode;

    Mesh(const std::vector<float>& vertices, GLenum mode);
    ~Mesh();

    void draw();
};