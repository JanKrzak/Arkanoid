#pragma once
#include <SFML/Graphics.hpp>
#include "config.h"

class Shape {
public:
     Shape();
    virtual ~Shape();

    virtual float x() = 0;
    virtual float y() = 0;
    virtual float left() = 0;
    virtual float right() = 0;
    virtual float top() = 0;
    virtual float bottom() = 0;
};

