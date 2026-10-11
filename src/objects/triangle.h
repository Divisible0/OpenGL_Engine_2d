#pragma once
#include "config.h"
#include "objects/object.h"


struct Triangle : Object {
    Triangle();
    void update(float dt) override;
};