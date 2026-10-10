#include "object.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


Object::Object(const std::vector<float>& vertices) {
    mesh = new Mesh(vertices);
}

Object::~Object() {
    delete mesh;
}


void Object::move(float x, float y, float z) {
    position += glm::vec3(x, y, z);
}

void Object::setPosition(float x, float y, float z) {
    position = glm::vec3(x, y, z);
}

void Object::setScale(float x, float y, float z) {
    scale = glm::vec3(x, y, z);
}

void Object::rotate(float phi, float theta, float psi) {
    rotation += glm::vec3(phi, theta, psi);
}

void Object::draw(unsigned int shader) {
    glm::mat4 model(1.0f);
    model = glm::translate(model, position);
    model = glm::rotate(model, glm::radians(rotation[0]), glm::vec3(1, 0, 0));
    model = glm::rotate(model, glm::radians(rotation[1]), glm::vec3(0, 1, 0));
    model = glm::rotate(model, glm::radians(rotation[2]), glm::vec3(0, 0, 1));
    model = glm::scale(model, scale);

    glUniformMatrix4fv(glGetUniformLocation(shader, "model"), 1, GL_FALSE, glm::value_ptr(model));
    mesh->draw();

}