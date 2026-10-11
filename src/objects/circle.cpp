#include "objects/circle.h"


std::vector<float> Circle::defVertices(float radius, int edges) {

    std::vector<float> vertices = {0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f}; //origin
    for(int i = 0; i <= edges; i += 1) {
        
        float theta = 2.0f * 3.1415926f * float(i) / float(edges);
        float x = radius * cos(theta);
        float y = radius * sin(theta);

        vertices.push_back(x);
        vertices.push_back(y);
        vertices.push_back(0.0f);
        vertices.push_back(1.0f);
        vertices.push_back(1.0f);
        vertices.push_back(1.0f);
        vertices.push_back(1.0f);
    }

    return vertices;
}

Circle::Circle(float radius, int edges)
    : Object(defVertices(radius, edges), GL_TRIANGLE_FAN) {}

void Circle::update(float dt) {
    double t = glfwGetTime();
    double s = sin(t * 2);
    float sc = (float) s;

    scale.x = sc;
    scale.y = sc;
}