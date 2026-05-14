#include <iostream>
#include "data.h"
#include "cmath"
using namespace std;

//gamePart

bool removeEmptyCell(emptyCells ec,int row , int col)
{
    bool flag = false;
    int i = 0;
    while (!flag && i<ec.n)
    {
        if(ec.ec[i].row == row && ec.ec[i].col == col)
        {
            ec.ec[i] = ec.ec[ec.n - 1];
            ec.n--;
            flag = true;
        }
        i++;
    }
    return flag;
}

//0 for standard position , 1 for 2 up 2 down pos
void initGame(gameState& gs , int n ,int choice)
{
gs.n = n;

for(int i = 0 ;i<gs.n ; i++)
{
    for(int j = 0 ; j<gs.n ; j++)
    {
        emptyCell e;
        e.row = i;
        e.col = j;
        gs.ec.ec[i * gs.n + j] = e;
        gs.b[i][j] = -1;
    }
    if(choice == 0)
    {
        gs.b[3][3] = 1;
        gs.b[3][4] = 0;
        gs.b[4][3] = 0;
        gs.b[4][4] = 1;
        removeEmptyCell(gs.ec,3,3);
        removeEmptyCell(gs.ec,3,4);
        removeEmptyCell(gs.ec,4,3);
        removeEmptyCell(gs.ec,4,4);
    }
    else
    {
        gs.b[3][3] = 0;
        gs.b[3][4] = 0;
        gs.b[4][3] = 1;
        gs.b[4][4] = 1;
        removeEmptyCell(gs.ec,3,3);
        removeEmptyCell(gs.ec,3,4);
        removeEmptyCell(gs.ec,4,3);
        removeEmptyCell(gs.ec,4,4);
    }
    gs.nbP[false] = 2;
    gs.nbP[true] = 2;
    gs.currentPlayer = false;
    gs.gameOver = false;
}

}



bool checkCell(const gameState& gs,int row , int col ,int color)
{
    return  gs.b[row][col] == color;
}

bool isEmptyCellLegalOneDirection(const gameState& gs ,legalMove& lm , const emptyCell& cell ,int rowDirection , int colDirection)
{
    lm.row = cell.row;
    lm.col = cell.col;
    int newRow = cell.row + rowDirection , newCol = cell.col + colDirection;
    int flipCountCopy = lm.flipCount;
    flipArray toFlipCopy = lm.toFlip;
    while((newRow>=0 && newRow<gs.n) && (newCol>=0 && newCol <gs.n) && checkCell(gs,newRow,newCol,!gs.currentPlayer))
    {
        flipCell fc;
        fc.row = newRow;
        fc.col = newCol;
        lm.toFlip[lm.flipCount] = fc;
        lm.flipCount++;
        newRow+=rowDirection;
        newCol+=colDirection;
    }
    if(gs.b[newRow][newCol] == gs.currentPlayer)
        return true;
    lm.flipCount = flipCountCopy;
    lm.toFlip =  toFlipCopy;
    return false;
}

bool isEmptyCellLegal(const gameState& gs ,legalMove& lm , const emptyCell& cell)
{
    return (
    isEmptyCellLegalOneDirection(gs,lm,cell,-1,0) ||
    isEmptyCellLegalOneDirection(gs,lm,cell,-1,1) ||
    isEmptyCellLegalOneDirection(gs,lm,cell,0,1) ||
    isEmptyCellLegalOneDirection(gs,lm,cell,1,1) ||
    isEmptyCellLegalOneDirection(gs,lm,cell,1,0) ||
    isEmptyCellLegalOneDirection(gs,lm,cell,1,-1) ||
    isEmptyCellLegalOneDirection(gs,lm,cell,0,-1) ||
    isEmptyCellLegalOneDirection(gs,lm,cell,-1,-1)
    );
}


void calculateLegalMoves(gameState& gs)
{
    legalMove lm;
    gs.legal.n = 0;
    lm.flipCount = 0;
    for(int i = 0 ; i<gs.ec.n ; i++)
    {
        if(isEmptyCellLegal(gs,lm,gs.ec.ec[i]))
        {
            gs.legal.legals[gs.legal.n] = lm;
            gs.legal.n++;
        }
        lm.flipCount = 0;
    }
}

bool verifyClick(const gameState& gs , int boardX1 ,int boardY1 , int boardX2 ,int boardY2 ,int xMouse , int yMouse , int& row ,int& col)
{
    if((xMouse>boardX1 && xMouse < boardX2) && (yMouse >boardY1 && yMouse<boardY2))
    {
        int dx = (boardX2 - boardX1) / gs.n;
        int dy = (boardY2 - boardY1) / gs.n;


        int xLoc = xMouse - dx;
        int xCount = 0;
        while(xLoc > 0)
        {
            xLoc -=dx;
            xCount++;
        }

        int yLoc = yMouse - dy;
        int yCount = 0;
        while(yLoc > 0)
        {
            yLoc -=dy;
            yCount++;
        }

        row = yCount;
        col = xCount;
        return true;
    }
    return false;
}

bool isClickLegal(const gameState& gs,int row , int col , int& id)
{
    int i = 0;
    bool flag = false;
    while(!flag && i<gs.legal.n)
    {
        if(gs.legal.legals[i].row == row && gs.legal.legals[i].col == col)
        {
            id = i;
            flag = true;
        }
        i++;
    }
    return flag;
}

void playLegal(gameState& gs,int id)
{
    legalMove lm  = gs.legal.legals[id];
    gs.b[lm.row][lm.col] = gs.currentPlayer;
    removeEmptyCell(gs.ec,lm.row,lm.col);
    for(int i = 0 ; i<lm.flipCount ; i++)
    {
        gs.b[lm.toFlip[i].row][lm.toFlip[i].col] = gs.currentPlayer;
    }
    gs.nbP[gs.currentPlayer] += lm.flipCount;
}

bool playMove(gameState& gs  , int boardX1 ,int boardY1 , int boardX2 ,int boardY2 ,int xMouse , int yMouse )
{
    int row,col;
    int id;
    if(verifyClick(gs,boardX1,boardY1,boardX2,boardY2,xMouse,yMouse,row,col))
    {
        if(isClickLegal(gs,row,col,id))
        {
            playLegal(gs,id);
            return true;
        }
        return false;
    }
    return false;
}