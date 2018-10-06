#ifndef AI_H
#define AI_H
#include "Board.h"

class Move
{
public:
    int x,y,score;
    Move(int Score)
    {
        score=Score;
    }
    Move(){};
};

class AI
{
public:
	int aiPlayer;
    int humanPlayer;
    AI(int aiPlayer)
    {
        this->aiPlayer=aiPlayer;
        humanPlayer=this->aiPlayer==X_VAL?O_VAL:X_VAL;

    }
    void makeMove(Board & board);
    Move minMaxMove(Board & board,int player);
};
#endif
