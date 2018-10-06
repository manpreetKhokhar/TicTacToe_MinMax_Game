#include "Board.h"
#include<stdio.h>
#include<iostream>
using namespace std;


void Board::clearBoard()
{
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            board[i][j]=BLANK;

}

int Board::getVal(int x,int y)
{
    return board[x][y];
}

void Board::setVal(int x,int y,int player)
{
    board[x][y]=player;

}

void Board::print()
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
            {
                int val=getVal(i,j);
                if(val==X_VAL)
                    printf("X ");
                else if(val==O_VAL)
                    printf("O ");
                else
                    printf("_ ");

            }
        cout<<endl;
    }
    cout<<endl;

}

bool Board::isMoveValid(int x,int y)
{
    // Bound Checking for Move
    if(x<0||x>2||y<0||y>2)
        return false;
    // if already occupied or not
    if(getVal(x,y)!=BLANK)
        return false;
    return true;
}
int Board::checkWin()
{   // Checking the rows first
    //cout<<"Checking Rows first for victory"<<endl;
    for(int row=0;row<3;row++)
    {   bool victory=true;
        int rowFirstVal=getVal(row,0);
        if(rowFirstVal==BLANK)
            continue;
        for(int col =0;col <3;col++)
           {
               int val=getVal(row,col);
               if(val!=rowFirstVal)
               {   victory=false;
                   break;
               }
           }
        if(victory)
            return rowFirstVal;
    }

    // Checking the columns
    //cout<<"Checking the columns for victory"<<endl;
    for(int col=0;col<3;col++)
    {
        bool victory=true;
        int colFirstVal=getVal(0,col);
        if(colFirstVal==BLANK)
            continue;
        for(int row =0;row <3;row++)
           {
               int val=getVal(row,col);
               if(val!=colFirstVal)
               {
                   victory=false;
                   break;
               }
           }
        if(victory)
            return colFirstVal;
    }
    // Checking the first diagonal
    //cout<<"Checking the first diagonal for victory"<<endl;
    int diagFirstVal=getVal(0,0);
    bool victory=true;
    if(diagFirstVal)
    {
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
                {
                    if(i==j)
                    {
                        int val=getVal(i,j);
                        if(val!=diagFirstVal)
                        {
                            victory=false;
                            break;
                        }
                    }

                }

        }
    }
    if(victory)
        return diagFirstVal;
    // Checking Diagonal 2 for victory
    //cout<<"Checking Diagonal 2 for victory"<<endl;
    int diag2FirstVal=getVal(2,0);
    victory=true;
    if(diag2FirstVal)
    {
            for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
                {
                    if(i+j==2)
                    {
                        int val=getVal(i,j);
                        if(val!=diag2FirstVal)
                        {
                            victory=false;
                            break;
                        }
                    }

                }

        }
    }
    if(victory)
        return diag2FirstVal;

    // Checking For Tie
    //cout<<"Checking for Tie"<<endl;
    bool tieFlag=true;
    for(int i=0;i<3;i++)
        {for(int j=0;j<3;j++)
            {
                int val=getVal(i,j);
                if(val==BLANK)
                    {
                        tieFlag=false;
                        break;
                    }
            }
        }
    if(tieFlag)
        return TIE_GAME;
    else
        return BLANK;

}

bool Board::isBlank(int x ,int y)
{
	int val=Board::getVal(x,y);
	if(val==BLANK)
		return true;
	else
		return false;


}

