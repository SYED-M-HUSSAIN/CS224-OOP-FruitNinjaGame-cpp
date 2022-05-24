#include "Score.hpp"
#include <iostream>

Score::Score(int initialScore) : S(initialScore) {}

void Score::ScoreUpdate()
{
    S += 10;
}

int Score::getScore()
{
    return S;
}