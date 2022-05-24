#include "Mango.hpp"
#include <iostream>

// pigeon implementation will go here.

Mango::Mango(): Fruits(70, 90){
    // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = {1534, 56, 183, 328};
}


void Mango::operator--()
{
    srcRect = {1241, 43, 220, 341};
}