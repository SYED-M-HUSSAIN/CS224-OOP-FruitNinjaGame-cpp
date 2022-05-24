#include <iostream>
#include <Windows.h>
#include "HUMania.hpp"
#include "ObjectCreator.hpp"

HUMania::HUMania(SDL_Renderer *renderer, SDL_Texture *asst, Score &totalScore, Health &totalHealth) : gRenderer(renderer), assets(asst), totalScore(totalScore), totalHealth(totalHealth)
{
}
void HUMania::drawObjects()
{
    // call draw functions of all the objects here
    static int del_count = 0;

    for (Fruits* i: objFrut ) {
        i->draw();
        i->fly();
        
        if (i->off_screen()) 
        {
            objFrut.remove(i);
            delete i;

//            cout<<"Item no: "<<del_count<<" is removed."<<endl;
            del_count ++;
        }    
    }

    for (Enemies* e: objEnem ) {
        e->draw();
        e->fly();
        
        if (e->off_screen()) 
        {
            objEnem.remove(e);
            delete e;

//            cout<<"Item no: "<<del_count<<" is removed."<<endl;
            del_count ++;
        }    
    }

    for (Collectibles* c: objColl ) {
        c->draw();
        c->fly();
        
        if (c->off_screen()) 
        {
            objColl.remove(c);
            delete c;

//            cout<<"Item no: "<<del_count<<" is removed."<<endl;
            del_count ++;
        }    
    }
}

void HUMania::displayHealth() 
{
    if (totalHealth.getHealth() > 0)
    {
        SDL_Rect srcRect = {918, 1946, 355, 335};
        SDL_Rect moverRect = {150, 50, 30, 30};
        for (int i = 0; i < totalHealth.getHealth(); i++)
        {
            if (i % 3 == 0)
            {
                moverRect.x = 150;
                moverRect.y += 40;
            }
            SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
            moverRect.x += 40;
        }
    }
    else no_health_left = true;
}

bool HUMania::if_health_left() {
    return no_health_left;
}

void HUMania::displayScore()
{
    // Score is already updated.
    // Current Score can be retrieved using totalScore.getScore()
    // Uncomment line 228
    TTF_Init();
    //Initialize SDL_ttf
    //this opens a font style and sets a size
    TTF_Font *font = TTF_OpenFont("arial.ttf", 28);

    // this is the color in rgb format,
    // maxing out all would give you the color white,
    // and it will be your text's color
    SDL_Color color = {255, 255, 255};

    // as TTF_RenderText_Solid could only be used on
    // SDL_Surface then you have to create the surface first
    // string text_to_display = to_string();
    std::string score_text = std::to_string(totalScore.getScore());
    SDL_Surface *surfaceMessage =
        TTF_RenderText_Solid(font, score_text.c_str(), color);

    // now you can convert it into a texture
    SDL_Texture *Message = SDL_CreateTextureFromSurface(gRenderer, surfaceMessage);

    SDL_Rect Message_rect; //create a rect
    Message_rect.x = 30; //controls the rect's x coordinate
    Message_rect.y = 80;   // controls the rect's y coordinte
    Message_rect.w = 50;   // controls the width of the rect
    Message_rect.h = 50;   // controls the height of the rect

      
    SDL_RenderCopy(gRenderer, Message, NULL, &Message_rect);
      

    // Don't forget to free your surface and texture
    SDL_DestroyTexture(Message);
    SDL_FreeSurface(surfaceMessage);
    TTF_CloseFont(font);

    TTF_Quit();
}

void HUMania::controlGameplay(int MouseX, int MouseY)
{
	SDL_Rect loc;
    bool isclicked;
    for (Fruits* F: objFrut)
    {
        isclicked = F->getBurst();
        loc = F->getLocation();
        if (((MouseY + 90) > loc.y && (MouseY - 90) < loc.y) && ((MouseX + 70) > loc.x && (MouseX - 70) < loc.x))
        //if (F->hit(MouseX, MouseY))
        {
            if (!isclicked)
            {
                F->setBurst();
                F--;
                totalScore.ScoreUpdate();
                // return;
            }
        }
    }
    for (Enemies* E: objEnem)
    {
        isclicked = E->getBurst();
        loc = E->getLocation();
        if (((MouseY + 90) > loc.y && (MouseY - 90) < loc.y) && ((MouseX + 70) > loc.x && (MouseX - 70) < loc.x))
        //if (E->hit(MouseX, MouseY))
        {
            if (!isclicked)
            {
                E->setBurst();
                E--;
                totalHealth.delHealth();
                // return;
            }
        }
    }
    for (Collectibles* C: objColl)
    {
        isclicked = C->getBurst();
        loc = C->getLocation();
        if (((MouseY + 90) > loc.y && (MouseY - 90) < loc.y) && ((MouseX + 70) > loc.x && (MouseX - 70) < loc.x))
        //if (C->hit(MouseX, MouseY))
        {
            if (!isclicked)
            {
                C->setBurst();
                C--;
                totalHealth.addHealth();
                // return;
            }
        }
    }
}

void HUMania::createObject(){
    // Sleep(10);
    //std::cout << "Mouse clicked at: " << x << " -- " << y << std::endl;
    int n = 1+(rand()%10);
    if (n==1)
    {
        int choice = rand() % 5;
        if (choice == 0)
        {
            Enemies* objE;
            objE = ObjectCreator::getEnemy();
            (objEnem).push_back(objE);
        }
        else if (choice == 1)
        {
            Collectibles* objC;
            objC = ObjectCreator::getCollectible();
            (objColl).push_back(objC);
        }
        else
        {
            Fruits* objF;
            objF = ObjectCreator::getFruit();
            (objFrut).push_back(objF);
        }

        SDL_Delay(100);
    }    
}

HUMania::~HUMania() {
    for (Fruits* F : objFrut)
    {
        delete F;
    }
    objFrut.clear();
    for (Enemies* E : objEnem)
    {
        delete E;
    }
    objEnem.clear();
    for (Collectibles* C : objColl)
    {
        delete C;
    }
    objColl.clear();
    std::cout << "Objects deleted";
}


