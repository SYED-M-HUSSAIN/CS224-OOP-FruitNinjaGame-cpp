#pragma once
#include<SDL.h>
#include "drawing.hpp"
#include "Fruits.hpp"

class Mango: public Fruits {
// declaring variables
    public:
        // calling the constructors, draw and fly functions  
        Mango();
        void operator--();
};