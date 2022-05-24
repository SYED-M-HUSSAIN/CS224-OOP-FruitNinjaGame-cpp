#include "Heart.hpp"
#include <iostream>

// pigeon implementation will go here.

Heart::Heart(): Collectibles(70, 70){
    // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = {918, 1946, 355, 355};
}


void Heart::operator--()
{
    srcRect = {918, 1946, 355, 355};
}