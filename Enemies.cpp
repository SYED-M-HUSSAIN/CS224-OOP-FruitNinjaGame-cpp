#include<iostream>
#include "Enemies.hpp"
#include <SDL.h>
#include <cmath>

using namespace std;

Enemies::Enemies(int w, int h) {
    // it will display pigeon on x , y location, the size of pigeon is 50 width, 60 height
    int x;
    x = 1 + (rand() % 1000);
    moverRect = {x, 600, w, h};
}

void Enemies::draw() {
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);      
}

void Enemies::timeTick() {
    time += 1;
}

bool Enemies::off_screen() {
    return not_on_screen;
}

void Enemies::fly() {
    if(moverRect.x < 500) 
    {
        v_y = y_o - (g*time);
        //std::cout<<"time "<<time<<std::endl; 
        //std::cout<<"v_x: "<<x_o<<" and v_y: "<<y_o<<std::endl;

        d_x = x_o * time;

        d_y = (v_y*time) - 0.5*g*(pow(time,2));

        //std::cout<<"The d_x: "<<d_x<<" and d_y:"<<d_y<<std::endl;

        moverRect.x += d_x;

        moverRect.y -= d_y;
    }

    else
    {
        v_y = y_o - (g*time);
        std::cout<<"time "<<time<<std::endl; 
        d_x = x_o * time;

        d_y = (v_y*time) - 0.5*g*(pow(time,2));
        //std::cout<<"The d_x: "<<d_x<<" and d_y:"<<d_y<<std::endl;

        moverRect.x -= d_x;

        moverRect.y -= d_y;
    }

    if (moverRect.y > 600) {
        not_on_screen = true;
    }

    
    timeTick();
    //std::cout<<"the distance covered in x-direction is: "<<moverRect.x<<" and y-direction is: "<<moverRect.y<<std::endl;
}

bool Enemies::getBurst()
{
    return burst;
}

void Enemies::setBurst()
{
    burst = true;
}

SDL_Rect Enemies::getLocation()
{
    return moverRect;
}

void Enemies::operator--(){}

bool Enemies::hit(int MouseX, int MouseY)
{   
    // int distance = sqrt(pow((MouseX - moverRect.x),2)+pow((MouseY - moverRect.y),2));
    // return distance;
    if (MouseX >= moverRect.x-moverRect.w && MouseX <= moverRect.x+moverRect.w &&
        MouseY >= moverRect.y-moverRect.h && MouseY <= moverRect.y+moverRect.h){
            return true;
        }
    return false;
}