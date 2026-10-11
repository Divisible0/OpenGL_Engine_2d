#pragma once
#include "config.h"
#include "objects/object.h"

struct Triangle_Fan : Object {
    Triangle_Fan();
    void update(float dt) override;
};