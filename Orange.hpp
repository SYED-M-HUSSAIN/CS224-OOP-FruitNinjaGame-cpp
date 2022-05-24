#pragma once
#include<SDL.h>
#include "drawing.hpp"
#include "Fruits.hpp"

class Orange: public Fruits {
// declaring variables
    public:
        // calling the constructors, draw and fly functions  
        Orange();
        void operator--();
};