#pragma once
#include "Health.hpp"
#include <iostream>

Health::Health(int initialHealth): health(initialHealth) {}

void Health::addHealth() {
    health += 1;
}

void Health::delHealth() {
    health -= 1;
}

int Health::getHealth() {
    return health;
}