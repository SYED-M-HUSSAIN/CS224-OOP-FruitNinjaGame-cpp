#include "Apple.hpp"
#include "drawing.hpp"


Apple::Apple(): Fruits(60, 80){
    // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = {389, 90, 139, 188};
}

// functionalities

void Apple::operator--()
{
    srcRect = {74, 43, 207, 235};
}

