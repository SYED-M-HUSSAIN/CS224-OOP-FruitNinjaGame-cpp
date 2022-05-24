#pragma once
#include <SDL.h>


class Health {
    int health = 3;

    public:
    Health(int);
    int getHealth();
    void addHealth();
    void delHealth();
};