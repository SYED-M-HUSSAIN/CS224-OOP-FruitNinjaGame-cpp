#include "Basket.hpp"
#include <iostream>

// pigeon implementation will go here.

Basket::Basket(): Collectibles(70, 70){
    // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = {1494, 888, 250, 349};
}


void Basket::operator--()
{
    srcRect = {1155, 862, 314, 388};
}