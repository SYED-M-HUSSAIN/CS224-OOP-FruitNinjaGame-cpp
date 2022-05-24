#pragma once
#include<SDL.h>
#include "drawing.hpp"
#include "Fruits.hpp"


class Watermelon: public Fruits{
    
public:
    // add the fly function here as well.
    Watermelon();
    void operator--();
    // may add other overloaded constructors here... 
};
