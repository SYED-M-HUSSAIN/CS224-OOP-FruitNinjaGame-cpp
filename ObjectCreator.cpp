
#include<iostream>
#include "ObjectCreator.hpp"



Fruits* ObjectCreator::getFruit() {
    int choice; // this is the choice variable which stores the random number between 1 to 3

    choice = 1 + (rand() % 4); // generates no.s b/w 1 to 3

    std::cout<<" Choice no. "<<choice<<std::endl; // for checking the random logic

    if(choice == 1){ // if choice is 1, then we push bee into bees vector at the 
    // specific location on screen and a starting state of 0 in state variable
        Fruits *w = new Watermelon();// creating dynamic object and pushing it into its vector
        return  w;
    }

    else if(choice == 2){ // if choice is 1, then we push pigeon into pigeons vector at the 
    // specific location on screen and a starting state of 0 in state variable
        Fruits *a = new Apple(); // creating dynamic object and pushing it into its vector
        return  a;
    }

    else if(choice == 3){ // if choice is 1, then we push pigeon into pigeons vector at the 
    // specific location on screen and a starting state of 0 in state variable
        Fruits *m = new Mango(); // creating dynamic object and pushing it into its vector
        return  m;
    }
    
    else {
    // specific location on screen and a starting state of 0 in state variable
        Fruits *o = new Orange(); // creating dynamic object and pushing it into its vector
        return  o;
    }
}


Enemies* ObjectCreator::getEnemy() {
    int choice; // this is the choice variable which stores the random number between 1 to 3

    choice = rand() % 2; // generates no.s b/w 1 to 3

    std::cout<<" Choice no. "<<choice<<std::endl; // for checking the random logic

    if(choice == 0){ // if choice is 1, then we push bee into bees vector at the 
    // specific location on screen and a starting state of 0 in state variable
        Enemies *w = new Bomb();// creating dynamic object and pushing it into its vector
        return w;
    }

    else{ // if choice is 1, then we push pigeon into pigeons vector at the 
    // specific location on screen and a starting state of 0 in state variable
        Enemies *a = new Rotten(); // creating dynamic object and pushing it into its vector
        return a;
    }
}

Collectibles* ObjectCreator::getCollectible() {
    int choice; // this is the choice variable which stores the random number between 1 to 3

    choice = rand() % 2; // generates no.s b/w 1 to 3

    std::cout<<" Choice no. "<<choice<<std::endl; // for checking the random logic

    if(choice == 0){ // if choice is 1, then we push bee into bees vector at the 
    // specific location on screen and a starting state of 0 in state variable
        Collectibles *h = new Heart();// creating dynamic object and pushing it into its vector
        return h;
    }

    else{ // if choice is 1, then we push pigeon into pigeons vector at the 
    // specific location on screen and a starting state of 0 in state variable
        Collectibles *a = new Basket(); // creating dynamic object and pushing it into its vector
        return a;
    }
}