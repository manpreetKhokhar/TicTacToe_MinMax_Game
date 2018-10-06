#include "AI.h"
#include<iostream>
#include<vector>
using namespace std;

void AI::makeMove(Board &board)
{
    Move m=AI::minMaxMove(board,this->aiPlayer);
    board.setVal(m.x,m.y,this->aiPlayer);
}
Move AI::minMaxMove(Board &board,int player)
{
   int checkWin=board.checkWin();
   if(checkWin==TIE_GAME) // Base Case of the recursion
   {
       Move m(0);
       return m;
   }
   else if(checkWin==this->aiPlayer){
        Move m(50);
        return m;
   }
   else if(checkWin==this->humanPlayer)
   {
       Move m(-50);
       return m;
   }
   else // Still None has won, recursive part of algorithm
   {
       vector<Move> moveStore;
       for(int row=0;row<3;row++)
       {
           for(int col=0;col<3;col++)
           {
               int val=board.getVal(row,col);
               if(val==BLANK)
               {
                   Move m;
                   board.setVal(row,col,player); // Changing the current Board, we will later restore it
                   if(player==this->aiPlayer)
                        m=AI::minMaxMove(board,this->humanPlayer);
                    else
                        m=AI::minMaxMove(board,this->aiPlayer);
                    m.x=row;
                    m.y=col;
                    moveStore.push_back(m);
                    board.setVal(row,col,BLANK); // Restoring original Board to it previous value
               }
           }
       }
       // Get the best Move out of moveStore vector
       vector<Move>::iterator it=moveStore.begin();
       int maxVal=1e4;
       int minVal=-1e4;
       vector<Move>::iterator bestMove=moveStore.begin(); // Will store reference to bestMove in the moveStore

       if(player==this->aiPlayer) // We will find a move with maximum Score
       {
           int bestScore=minVal;
            for(;it!=moveStore.end();it++)
                {
                    int score=(*it).score;
                    if(score>bestScore&&score<maxVal)
                        {
                            bestMove=it;
                            bestScore=(*it).score;
                        }
                }
       }
       else  // We will find a move with minimum score
       {
           int bestScore=maxVal;
           for(;it!=moveStore.end();it++)
                {
                    int score=(*it).score;
                    if(score<bestScore&&score>minVal)
                        {
                            bestMove=it;
                            bestScore=(*it).score;
                        }
                }
       }

       return (*bestMove);

   }//Recursive Part Ends

}

