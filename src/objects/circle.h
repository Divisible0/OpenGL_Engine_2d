#pragma once
#include "config.h"
#include "objects/object.h"


struct Circle : Object {
    Circle(float radius, int edges);
    void update(float dt) override;

private:
    static std::vector<float> defVertices(float radius, int edges);
};