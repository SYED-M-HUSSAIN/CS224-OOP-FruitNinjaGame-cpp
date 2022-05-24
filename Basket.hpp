#pragma once
#include<SDL.h>
#include "drawing.hpp"
#include "Collectibles.hpp"

class Basket: public Collectibles {
// declaring variables
    public:
        // calling the constructors, draw and fly functions  
        Basket();
        void operator--();
};