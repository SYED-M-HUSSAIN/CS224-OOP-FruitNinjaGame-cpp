#include "Watermelon.hpp"
#include <iostream>


// pigeon implementation will go here.

Watermelon::Watermelon(): Fruits(80, 100){
    // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = {1505, 491, 212, 230};
    
    // it will display pigeon on x = 30, y = 40 location, the size of pigeon is 50 width, 60 height
}

void Watermelon::operator--()
{
    srcRect = {1138, 491, 289, 264};
}




