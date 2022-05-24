#include "Orange.hpp"
#include <iostream>

// pigeon implementation will go here.

Orange::Orange(): Fruits(50, 50){
    // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = {989, 99, 149, 148};
}


void Orange::operator--()
{
    srcRect = {659, 68, 205, 210};
}