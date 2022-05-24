#pragma once
#include<SDL.h>
#include "drawing.hpp"
#include "Fruits.hpp"


class Apple: public Fruits{
    // declaring variables

    public:
        // calling the constructors, draw and fly functions
        Apple();
        void operator--();
};
