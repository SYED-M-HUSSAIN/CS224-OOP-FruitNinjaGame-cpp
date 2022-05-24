#pragma once
#include<SDL.h>
#include "drawing.hpp"
#include "Enemies.hpp"

class Bomb: public Enemies {
// declaring variables
    public:
        // calling the constructors, draw and fly functions  
        Bomb();
        void operator--();
};