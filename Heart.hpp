#pragma once
#include<SDL.h>
#include "drawing.hpp"
#include "Collectibles.hpp"

class Heart: public Collectibles {
// declaring variables
    public:
        // calling the constructors, draw and fly functions  
        Heart();
        void operator--();
};