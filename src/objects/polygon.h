#pragma once
#include "config.h"
#include "objects/object.h"


struct Polygon : Object {
    Polygon(float x, float y, float z, float radius, int edges);
    void update(float dt) override;

private:
    static std::vector<float> defVertices(float x, float y, float z, float radius, int edges);
};