#include "objects/triangle_fan.h"


Triangle_Fan::Triangle_Fan() : Object({
    0.0f,    0.0f,    0.0f,   1.0f, 1.0f, 1.0f, 1.0f,
     0.5f,    0.0f,    0.0f,   1.0f, 1.0f, 1.0f, 1.0f,
     0.25f,   0.433f,  0.0f,   1.0f, 1.0f, 1.0f, 1.0f,
    -0.25f,   0.433f,  0.0f,   1.0f, 1.0f, 1.0f, 1.0f,
    -0.5f,    0.0f,    0.0f,   1.0f, 1.0f, 1.0f, 1.0f,
    -0.25f,  -0.433f,  0.0f,   1.0f, 1.0f, 1.0f, 1.0f,
     0.25f,  -0.433f,  0.0f,   1.0f, 1.0f, 1.0f, 1.0f,
     0.5f,    0.0f,    0.0f,   1.0f, 1.0f, 1.0f, 1.0f

}, GL_TRIANGLE_FAN) {}

void Triangle_Fan::update() {
    double t = glfwGetTime();
    double s = 0.125 * sin(t * 2);
    float sc = (float) s;

    scale.x = sc;
    scale.y = sc;
}