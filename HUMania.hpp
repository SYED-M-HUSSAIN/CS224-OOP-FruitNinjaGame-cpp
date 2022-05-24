#pragma once
#include<SDL.h>
#include "Fruits.hpp"
#include "Enemies.hpp"
#include "Collectibles.hpp"
#include<vector>
#include<list>
#include <SDL_mixer.h>
#include "Score.hpp"
#include "Health.hpp"
#include<SDL_ttf.h>
using namespace std;

class HUMania{


    // In the solution you have to create vectors of pigeons, eggs, and nests    
    list<Fruits*> objFrut;
    list<Enemies*> objEnem;
    list<Collectibles*> objColl;
    SDL_Renderer *gRenderer;
    SDL_Texture *assets;
    Score totalScore;
    Health totalHealth;
    bool no_health_left = false;

    public:
    
    HUMania(SDL_Renderer *, SDL_Texture *, Score&, Health&);
    void drawObjects();
    void displayScore();
    void createObject();
    void controlGameplay(int MouseX, int MouseY);
    void displayHealth();
    bool if_health_left();
    ~HUMania();
 
};
