#pragma once
#include<SDL.h>
#include "drawing.hpp"

class Fruits{
    protected:
    //SDL_Rect srcRect, moverRect;
    int state = 0;
    //bool on_screen = true;
    double time = 0;
    int x_o = (rand() % (1 - 7 + 1)) + 1, y_o = (rand() % (70 - 95 + 1)) + 70;
    int v_y = 0; 
    int d_x = 0; int d_y = 0;
    double g = 9.8;
    int width, height;
    bool not_on_screen = false;
    //SDL_Rect src_1, src_2, src_3, src_4;
    bool burst;

    public:
    //SDL Rectangles
    SDL_Rect moverRect;
    SDL_Rect srcRect;

    //defining Constructors
    // add the fly function here as well.
    Fruits(); 
    Fruits(int, int);
    bool off_screen();
    void draw();
    void timeTick();
    virtual void operator--();
    bool getBurst();
    void setBurst();
    SDL_Rect getLocation();
    void fly();
    bool hit(int MouseX, int MouseY);
};