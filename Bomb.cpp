#include "Bomb.hpp"
#include <iostream>

// pigeon implementation will go here.

Bomb::Bomb(): Enemies(70, 70){
    // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = {1459, 1372, 280, 242};
}


void Bomb::operator--()
{
    srcRect = {1095, 1308, 310, 378};
}