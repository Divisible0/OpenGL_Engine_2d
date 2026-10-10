#pragma once
#include "config.h"
#include "engine/mesh.h"

struct Object {
    Mesh* mesh;
    
    glm::vec3 position = glm::vec3(0.0f);
    glm::vec3 scale = glm::vec3(1.0f);
    glm::vec3 rotation = glm::vec3(0.0f);

    Object(const std::vector<float>& vertices);
    virtual ~Object();

    void move(float x, float y, float z);
    void setPosition(float x, float y, float z);
    void setScale(float x, float y, float z);
    void rotate(float phi, float theta, float psi);

    virtual void update() {}
    void draw(unsigned int shader);

};