#include "funcs.h"
using namespace std;

bool addEmptyCell(gameState& gs , int row , int col)
{
    if(checkCell(gs,row,col,-1)) {
        emptyCell c;
        c.row = row;
        c.col = col;
        gs.ec.ec[gs.ec.n] = c;
        gs.b[row][col].id = gs.ec.n;
        gs.ec.n++;
        return true;
    }
    return false;
}


bool removeEmptyCell(gameState& gs,int row , int col)
{
    int i = gs.b[row][col].id;
    if(i != -1) {
        gs.ec.n--;
        gs.ec.ec[i] = gs.ec.ec[gs.ec.n];
        int cRow = gs.ec.ec[i].row , cCol = gs.ec.ec[i].col;
        gs.b[cRow][cCol].id = i;
        return true;
    }
}

//0 for standard position , 1 for 2 up 2 down pos
void initGame(gameState& gs , int n ,int choice)
{
    gs.n = n;
    gs.ec.n =0;

    for(int i = 0 ;i<gs.n ; i++) {
        for (int j = 0; j < gs.n; j++) {
            gs.b[i][j].color = -1;
            gs.b[i][j].id = -1;
        }
    }

    if(choice == 0)
    {
        gs.b[3][3].color = 1;
        gs.b[3][4].color = 0;
        gs.b[4][3].color = 0;
        gs.b[4][4].color = 1;

    }
    else
    {
        gs.b[3][3].color = 0;
        gs.b[3][4].color = 0;
        gs.b[4][3].color = 1;
        gs.b[4][4].color = 1;
    }

    for(int i = 2 ; i<=5 ; i++)
        addEmptyCell(gs,2,i);
    for(int i = 2 ; i<=5 ; i++)
        addEmptyCell(gs,5,i);
    for(int i = 3 ; i<=4 ; i++)
        addEmptyCell(gs,i,2);
    for(int i = 3 ; i<=4 ; i++)
        addEmptyCell(gs,i,5);
    gs.nbP[false] = 2;
    gs.nbP[true] = 2;
    gs.currentPlayer = false;
    gs.gameOver = false;
}




bool checkCell(const gameState& gs,int row , int col ,int color)
{
    return  gs.b[row][col].color == color;
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
    if(checkCell(gs,newRow,newCol,gs.currentPlayer))
        return true;
    lm.flipCount = flipCountCopy;
    lm.toFlip =  toFlipCopy;
    return false;
}

bool isEmptyCellLegal(const gameState& gs ,legalMove& lm , const emptyCell& cell)
{
    lm.flipCount = 0;
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
    gs.b[lm.row][lm.col].color = gs.currentPlayer;
    removeEmptyCell(gs,lm.row,lm.col);
    for(int i = 0 ; i<lm.flipCount ; i++)
    {
        gs.b[lm.toFlip[i].row][lm.toFlip[i].col].color = gs.currentPlayer;
    }
    gs.nbP[gs.currentPlayer] += lm.flipCount;
    gs.currentPlayer = !gs.currentPlayer;
}

void addEmptyCellOneDirection(gameState&gs ,int row , int col, int rowDirection , int colDirection)
{
    addEmptyCell(gs,row+rowDirection , col + colDirection);
}

void addEmptyCellAllDirections(gameState& gs , int row , int col)
{
    addEmptyCellOneDirection(gs,row,col,-1,0);
    addEmptyCellOneDirection(gs,row,col,-1,1);
    addEmptyCellOneDirection(gs,row,col,0,1);
    addEmptyCellOneDirection(gs,row,col,1,1);
    addEmptyCellOneDirection(gs,row,col,1,0);
    addEmptyCellOneDirection(gs,row,col,1,-1);
    addEmptyCellOneDirection(gs,row,col,0,-1);
    addEmptyCellOneDirection(gs,row,col,-1,-1);
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
            addEmptyCellAllDirections(gs,row,col);
            return true;
        }
        return false;
    }
    return false;
}

bool isGameOver(gameState& gs)
{
    gs.currentPlayer = !gs.currentPlayer;
    calculateLegalMoves(gs);
    return gs.legal.n == 0;
}

