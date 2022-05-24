#include "Rotten.hpp"
#include <iostream>

// Rotten item implementation will go here.

Rotten::Rotten(): Enemies(70, 70){
    // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = {522, 545, 244, 232};
}

void Rotten::operator--()
{
    srcRect = {106, 415, 298, 405};
}