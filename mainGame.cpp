#include "mainGame.h"
#include "AI.h"
#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
using namespace std;

MainGame::MainGame()
{
	cout<<"################  WELCOME TO TIC-TAC-TOE BY MANPREET SINGH  #################"<<endl;
}
MainGame::~MainGame()
{   cout<<"#############################################################################"<<endl;
    cout<<"THANK YOU! FOR PLAYING THE GAME...."<<endl;
    cout<<"CREDITS :: MANPREET SINGH CSE SECTION-I "<<endl;
}
void MainGame::startGame()
{
    MainGame::gameState=RUNNING;
    MainGame::turnCount=0;
    MainGame::tieFlag=false;
}
void MainGame::endGame()
{
    MainGame::gameState=END_GAME;
    if(MainGame::winner==BLANK && MainGame::tieFlag==true)
        MainGame::declareTie();
    else
        MainGame::declareWinner();
}
void MainGame::declareWinner()
{
    if(MainGame::winner == X_VAL)
       cout<<"Player X wins"<<endl;
    else
        cout<<"Player O wins"<<endl;
}
void MainGame::declareTie()
{
    if(MainGame::winner == BLANK || MainGame::tieFlag)
        cout<<"Game is a Tie!!"<<endl;
}

void MainGame::clearScreen()  // Utility function to clear the screen
{
	if (system("CLS"))
		system("clear");
}

void MainGame::switchPlayer()
{
    if(MainGame::currentPlayer == X_VAL)
        MainGame::currentPlayer = O_VAL;
    else
        MainGame::currentPlayer = X_VAL;
}

void MainGame::firstMoves(int aiPlayer)
{
    switch(MainGame::turnCount)
        {
            case 1: // If pc has turn 1, occupy the top left corner first
            {
                MainGame::board.setVal(0,0,aiPlayer);
                break;
            }
            case 2: // If second turn, check if center is blank
            {           // If yes, insert the symbol
                        // else occupy the top left corner
                if(MainGame::board.isBlank(1,1))
                    MainGame::board.setVal(1,1,aiPlayer);
                else
                    MainGame::board.setVal(0,0,aiPlayer);
                break;
            }
            case 3:     // If pc has to execute third move
            {           // Check if the bottom right corner is not occupied
                if (MainGame::board.isBlank(2,2))// if free, insert the symbol
                    MainGame::board.setVal(2,2,aiPlayer);
                else    // else, insert the symbol at top right corner
                    MainGame::board.setVal(0,2,aiPlayer);
                break;
            }
    }
}

void MainGame::turnReminder()
{
    printf("%s Turn\n",(MainGame::currentPlayer==X_VAL?"X's":"O's"));
}

pair<int,int> MainGame::cellMapping(int cellNo)
{
    int y=(cellNo-1)%3;
    int x=(cellNo-1-y)/3;
    return make_pair(x,y);
}

void MainGame::gamePlay()
{
    MainGame::startGame();
    char symbol;
    cout<<"Choose your Symbol"<<endl;
    bool choice=true;
    int aiPlayer;
    do
    {
        cin>>symbol;
        if(symbol== 'X'||symbol=='x')
            {aiPlayer=O_VAL;choice=true;}
        else if(symbol=='O'||symbol=='o')
            {aiPlayer=X_VAL;choice=true;}
        else
        {
            cout<<"Illegal Symbol: Please Choose between 'X' or 'O' "<<endl;
            choice=false;
        }
    }while(!choice);
    AI ai(aiPlayer);
    cout<<"Symbol Locked!!"<<endl;
    cout<<"Choose who will play first Move"<<endl;
    cout<<"Enter your Symbol for your Turn"<<endl;
    cin>>symbol;
    if(((symbol=='X'||symbol=='x' )&& ai.aiPlayer==X_VAL)||((symbol=='O'||symbol=='o' )&& ai.aiPlayer==O_VAL))
        MainGame::currentPlayer=ai.aiPlayer;
    else
        MainGame::currentPlayer=ai.humanPlayer;
    MainGame::turnCount++;
    MainGame::board.print();
    // Game Loop Starts
    while(MainGame::gameState !=END_GAME)
    {
        MainGame::turnReminder(); // Reminds the turn of the players
        if(MainGame::currentPlayer == ai.aiPlayer)  // If AI turn
        {
            if(MainGame::turnCount<=3)
                MainGame::firstMoves(ai.aiPlayer);
            else
                ai.makeMove(MainGame::board);

        }
        else                               // If User turn
        {
        	bool result=true;
            cout<<"Enter your move "<<endl;
            int x,y;
            int cellNo;
            do{
                cin>>cellNo;
                pair<int,int> coordinates;
                coordinates=MainGame::cellMapping(cellNo);
                x=coordinates.first;
                y=coordinates.second;
                result=MainGame::board.isMoveValid(x,y);
                if(!result)
                    cout<<"Sorry,Wrong Move!!"<<endl<<"Please Re-Enter your move "<<endl;
            }while(!result);
            MainGame::board.setVal(x,y,ai.humanPlayer);

        }
        MainGame::clearScreen();
        MainGame::board.print();
        int victoryResult=MainGame::board.checkWin();
        if(victoryResult==TIE_GAME)
            {
                MainGame::tieFlag=true;
                MainGame::winner=BLANK;
                MainGame::endGame();
                continue;
            }
        else if(victoryResult==X_VAL)
        {
            MainGame::winner=X_VAL;
            MainGame::endGame();
        }
        else if(victoryResult==O_VAL)
        {
            MainGame::winner=O_VAL;
            MainGame::endGame();
        }
        else   // Still , None has achieved the win..
        {
            cout<<"Still None has won!!"<<endl;
            cout<<"Switching to next turn"<<endl;
            MainGame::turnCount++;
            MainGame::switchPlayer();
        }

    }

}
