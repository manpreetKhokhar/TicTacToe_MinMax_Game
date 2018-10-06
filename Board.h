#ifndef BOARD_H
#define BOARD_H

const int X_VAL=3;
const int O_VAL=5;
const int BLANK=2;
const int TIE_GAME=0;

class Board
{
private:
    int board[3][3];
public:
    Board(){
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            board[i][j]=2;
    };
    void clearBoard();
    int getVal(int x,int y);
    void setVal(int x,int y,int player);
    bool isMoveValid(int x,int y);
	bool isBlank(int x,int y);
    int checkWin();
    void print();
};

#endif
