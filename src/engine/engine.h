#pragma once
#include "config.h"
#include "objects/triangle.h"
#include "objects/triangle_fan.h"
#include "objects/circle.h"
#include "engine/shader.h"

struct Engine {
    GLFWwindow* window;
    Triangle* triangle;
    Triangle_Fan* triangle_fan;
    Circle* circle;

    int WIDTH = 800;
    int HEIGHT = 600;
    unsigned int shader;
    double lastFrameTime;

    Engine();
    ~Engine();

    void run();
    void draw(float dt);
};