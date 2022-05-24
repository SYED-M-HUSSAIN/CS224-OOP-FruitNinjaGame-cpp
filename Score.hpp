#pragma once

// Score class to implement total score during the game
// It only has one attribute of type int that stores the total score at any point in game

class Score
{
    int S;

public:
    // ScoreUpdate() is called whenever the fruit is cut
    // getScore is used to return the current value of score
    // it will be used to display the score on screen
    Score(int);
    void ScoreUpdate();
    int getScore();
};