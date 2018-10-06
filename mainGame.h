#ifndef MAINGAME_H
#define MAINGAME_H

# include "Board.h"
#include<iostream>
using namespace std;
const int  RUNNING=12;
const int END_GAME=13;
class MainGame
{
   private:
	int gameState;
    int currentPlayer;
    int turnCount; // To be used for firstMoves() function ..
    int winner;
    bool tieFlag;
    Board board;
   public:
    MainGame();
    ~MainGame();
    void startGame();
    void endGame();
    void declareWinner();
    void declareTie();
    void gamePlay();
    void firstMoves(int aiPlayer);
    void clearScreen();
    void switchPlayer();
    void turnReminder();
    pair<int,int> cellMapping(int cellNo);
};
#endif
