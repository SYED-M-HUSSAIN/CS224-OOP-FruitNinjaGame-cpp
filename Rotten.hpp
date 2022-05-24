#pragma once
#include<SDL.h>
#include "drawing.hpp"
#include "Enemies.hpp"

class Rotten: public Enemies {
// declaring variables
    public:
        // calling the constructors, draw and fly functions  
        Rotten();
        void operator--();
};