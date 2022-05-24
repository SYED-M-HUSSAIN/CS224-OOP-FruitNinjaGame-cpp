// #pragma once
// #include "Fruits.hpp"
// #include "Watermelon.hpp"
// #include "Apple.hpp"
// #include "Mango.hpp"
// #include "Bomb.hpp"
// #include "Basket.hpp"
// #include "Orange.hpp"

// class ObjectCreator{
//     public:
//     static Fruits* getObject();
// };

#pragma once
#include "Fruits.hpp"
#include "Collectibles.hpp"
#include "Enemies.hpp"
#include "Watermelon.hpp"
#include "Apple.hpp"
#include "Mango.hpp"
#include "Bomb.hpp"
#include "Rotten.hpp"
#include "Heart.hpp"
#include "Basket.hpp"
#include "Orange.hpp"

class ObjectCreator{
    public:
    static Fruits* getFruit();
    static Enemies* getEnemy();
    static Collectibles* getCollectible();
};