#include "objects/triangle.h"


Triangle::Triangle() : Object({
    -0.5f, -0.5f,  0.0f,  1.0f, 0.0f, 0.0f, 1.0f,
    0.5f, -0.5f,  0.0f,  0.0f, 1.0f, 0.0f, 1.0f,
    0.0f,  0.5f,  0.0f,  0.0f, 0.0f, 1.0f, 1.0f
}) {}



void Triangle::update() {
    double t = glfwGetTime();
    double sy = 0.125 * sin(t);
    double sx = 0.125 * cos(t);
    float y = (float) sy;
    float x = (float) sx;

    position.y = y;
    position.x = x;

}