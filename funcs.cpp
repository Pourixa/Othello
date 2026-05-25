#include "funcs.h"
#include <fstream>
using namespace std;

bool addEmptyCell(gameState& gs , int row , int col)
{
    if(checkCell(gs,row,col,-1) && gs.b[row][col].id == -1) {
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
    gs.b[row][col].id = -1;
    if(i != -1) {
        gs.ec.n--;
        gs.ec.ec[i] = gs.ec.ec[gs.ec.n];
        int cRow = gs.ec.ec[i].row , cCol = gs.ec.ec[i].col;
        gs.b[cRow][cCol].id = i;
        return true;
    }
    return false;
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
    int r1 = n/2 , r2 = r1-1;
    int c1 = n/2 , c2 = c1-1;
    if(choice == 0)
    {
        gs.b[r1][c1].color = 1;
        gs.b[r1][c2].color = 0;
        gs.b[r2][c1].color = 0;
        gs.b[r2][c2].color = 1;

    }
    else
    {
        gs.b[r1][c1].color = 0;
        gs.b[r1][c2].color = 0;
        gs.b[r2][c1].color = 1;
        gs.b[r2][c2].color = 1;
    }

    for(int i = c2 - 1 ; i<= c1 + 1 ; i++)
        addEmptyCell(gs,r2 - 1,i);
    for(int i = c2 - 1 ; i<=c1 + 1 ; i++)
        addEmptyCell(gs,r1+1,i);
    for(int i = r2 ; i<=r1 ; i++)
        addEmptyCell(gs,i,c2 - 1);
    for(int i = r2 ; i<=r1 ; i++)
        addEmptyCell(gs,i,c1 + 1);
    gs.nbP[false] = 2;
    gs.nbP[true] = 2;
    gs.currentPlayer = false;
    ifstream config("config.cfg");
    string trash;
    config >> trash>> gs.diffs[0]
    >> trash >> gs.diffs[1]
    >> trash>> gs.diffs[2];
    config.close();
    if(n == 4)
        gs.difficulty = gs.diffs[0];
    else if (n == 6)
        gs.difficulty = gs.diffs[1];
    else
        gs.difficulty = gs.diffs[2];
}






bool checkCell(const gameState& gs,int row , int col ,int color)
{
    if(row < 0 || row >= gs.n || col < 0 || col >= gs.n)
        return false;
    return  gs.b[row][col].color == color;
}

bool isEmptyCellLegalOneDirection(const gameState& gs ,legalMove& lm , const emptyCell& cell ,int rowDirection , int colDirection)
{
    lm.row = cell.row;
    lm.col = cell.col;
    int newRow = cell.row + rowDirection , newCol = cell.col + colDirection , i = 0;
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
        i++;
    }
    if(checkCell(gs,newRow,newCol,gs.currentPlayer) && i > 0)
        return true;
    lm.flipCount = flipCountCopy;
    lm.toFlip =  toFlipCopy;
    return false;
}

bool isEmptyCellLegal(const gameState& gs ,legalMove& lm , const emptyCell& cell)
{
    lm.flipCount = 0;
    bool flag =  isEmptyCellLegalOneDirection(gs,lm,cell,-1,0) ;
    flag = isEmptyCellLegalOneDirection(gs,lm,cell,-1,1) || flag;
    flag = isEmptyCellLegalOneDirection(gs,lm,cell,0,1) || flag;
    flag = isEmptyCellLegalOneDirection(gs,lm,cell,1,1) || flag;
    flag = isEmptyCellLegalOneDirection(gs,lm,cell,1,0) || flag;
    flag = isEmptyCellLegalOneDirection(gs,lm,cell,1,-1) || flag;
    flag = isEmptyCellLegalOneDirection(gs,lm,cell,0,-1) || flag;
    flag = isEmptyCellLegalOneDirection(gs,lm,cell,-1,-1) || flag;
    return flag;
}


void calculateLegalMoves(gameState& gs)
{
    legalMove lm;
    gs.legal.n = 0;
    for(int i = 0 ; i<gs.ec.n ; i++)
    {
        if(isEmptyCellLegal(gs,lm,gs.ec.ec[i]))
        {
            gs.legal.legals[gs.legal.n] = lm;
            gs.legal.n++;
        }
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
    gs.nbP[gs.currentPlayer] += lm.flipCount + 1;
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

bool playMove(gameState& gs  , int row , int col)
{
    int id;
//    if(verifyClick(gs,boardX1,boardY1,boardX2,boardY2,xMouse,yMouse,row,col))
//    {
        if(isClickLegal(gs,row,col,id))
        {
            playLegal(gs,id);
            addEmptyCellAllDirections(gs,row,col);
            return true;
        }
        return false;
//    }
    return false;
}

bool isGameOver(gameState gs)
{
       if(gs.ec.n == 0) {
           return true;
       }
       if (gs.legal.n == 0)
       {
        gs.currentPlayer = !gs.currentPlayer;
           calculateLegalMoves(gs);
           if(gs.legal.n ==0)
           {
               return true;
           }
           }
    return false;
    }

int evaluateState(const gameState &gs) {
    return gs.nbP[true] - gs.nbP[false];
}

void printBoard(const gameState &gs) {
    // Print column numbers
    cout << "  ";
    for (int j = 0; j < gs.n; j++)
        cout << j << " ";
    cout << endl;

    // Print board rows
    for (int i = 0; i < gs.n; i++) {
        cout << i << " "; // row number

        for (int j = 0; j < gs.n; j++) {
            if (checkCell(gs, i, j, -1))
                cout << ". ";   // empty
            else if (checkCell(gs, i, j, 0))
                cout << "B ";   // black
            else if (checkCell(gs, i, j, 1))
                cout << "W ";   // white
        }

        cout << endl;
    }

    cout << endl;
}

int minimax(const gameState &gs, int level, int depth,int alpha ,int beta, int &row, int &col) {

    if (isGameOver(gs) || level >= depth)
        return evaluateState(gs);

    if (gs.legal.n == 0) {
        gameState gsCopy = gs;
        gsCopy.currentPlayer = !gsCopy.currentPlayer;
        calculateLegalMoves(gsCopy);
        return minimax(gsCopy, level + 1, depth,alpha,beta, row, col);
    }
    if (gs.currentPlayer) {
        int value = -1000, tValue, j=0;

        int Trow, Tcol;
        gameState gsCopy;
        int i =0;
        while(i<gs.legal.n && alpha < beta) {
            gsCopy = gs;
            Trow = gs.legal.legals[i].row;
            Tcol = gs.legal.legals[i].col;
            playMove(gsCopy, Trow, Tcol);
            calculateLegalMoves(gsCopy);
            tValue = minimax(gsCopy, level + 1, depth,alpha,beta, row, col);
            if (tValue > value) {
                j = i;
                value = tValue;
            }
            if(alpha < value)
                alpha =value;
            i++;
        }
        row = gs.legal.legals[j].row;
        col = gs.legal.legals[j].col;
        return value;
    } else {
        int value = 1000, tValue, j = 0;
        int Trow, Tcol;
        gameState gsCopy;
        int i = 0;
        while(i<gs.legal.n && beta>alpha) {
            gsCopy = gs;
            Trow = gs.legal.legals[i].row;
            Tcol = gs.legal.legals[i].col;
            playMove(gsCopy, Trow, Tcol);
            calculateLegalMoves(gsCopy);
            tValue = minimax(gsCopy, level + 1, depth,alpha,beta, row, col);
            if (tValue < value) {
                j = i;
                value = tValue;
            }
            if(beta > value)
                beta =value;
            i++;
        }
        row = gs.legal.legals[j].row;
        col = gs.legal.legals[j].col;
        return value;
    }
}

void botLogic(const gameState &gs, int difficulty, int &row, int &col) {
    if (difficulty == 0) {
        int i = rand() % gs.legal.n;
        row = gs.legal.legals[i].row;
        col = gs.legal.legals[i].col;
    } else
        minimax(gs, 0, difficulty,-1000,1000, row, col);
}

void playConsoleGameVSPlayer() {
    gameState gs;
    int input1, input2;
    cout << "entrez votre choix de la taile: ";
    cin >> input1;
    cout << "entrez votre choix de la position depart: ";
    cin >> input2;
    initGame(gs, input1, input2);
    calculateLegalMoves(gs);
    while (!isGameOver(gs)) {
        printBoard(gs);
        int row, col;
        if (gs.legal.n == 0)
            gs.currentPlayer = !gs.currentPlayer;
        else {
            if (gs.currentPlayer) {
                do {
                    cout << "entrez le choix de la ligne du blanc: ";
                    cin >> row;
                    cout << "entrez le choix de la colonne du blanc: ";
                    cin >> col;
                } while (!playMove(gs, row, col));

            } else {
                do {
                    cout << "entrez le blanc de la ligne du blanc: ";
                    cin >> row;
                    cout << "entrez le b de la colonne du blanc: ";
                    cin >> col;
                } while (!playMove(gs, row, col));
            }
        }
        calculateLegalMoves(gs);
    }
    printBoard(gs);


    if (gs.nbP[false] > gs.nbP[true])
        cout << "NOIR A GAGNE";
    else if (gs.nbP[false] < gs.nbP[true])
        cout << "BLANC A GAGNE";
    else
        cout << "PERSONNE A GAGNE";
}

void playConsoleGameVSBot() {
    gameState gs;
    int input1, input2, playerTurn;
    cout << "entrez votre choix de la taile: ";
    cin >> input1;
    cout << "entrez votre choix de la position depart: ";
    cin >> input2;
    cout << "Entrez votre coleur prefere: ";
    cin >> playerTurn;
    initGame(gs, input1, input2);
    calculateLegalMoves(gs);
    while (!isGameOver(gs)) {
        printBoard(gs);
        int row, col;
        if (gs.legal.n == 0)
            gs.currentPlayer = !gs.currentPlayer;
        else {
            if (gs.currentPlayer == playerTurn) {
                do {
                    cout << "entrez le choix de la ligne: ";
                    cin >> row;
                    cout << "entrez le choix de la colonne: ";
                    cin >> col;
                } while (!playMove(gs, row, col));
            } else {
                botLogic(gs, gs.difficulty, row, col);
                playMove(gs, row, col);
            }
        }
        calculateLegalMoves(gs);
    }
    printBoard(gs);
    if (gs.nbP[false] > gs.nbP[true])
        cout << "NOIR A GAGNE! ";
    else if (gs.nbP[false] < gs.nbP[true])
        cout << "BLANC A GAGNE! ";
    else
        cout << " EGALITE! ";


}

void playConsoleBotVSBot()
{
    gameState gs;
    int input1, input2, playerTurn;
    cout << "entrez votre choix de la taile: ";
    cin >> input1;
    cout << "entrez votre choix de la position depart: ";
    cin >> input2;
    initGame(gs, input1, input2);
    calculateLegalMoves(gs);
    while (!isGameOver(gs)) {
        printBoard(gs);
        int row, col;
        if (gs.legal.n == 0)
            gs.currentPlayer = !gs.currentPlayer;
        else {
            botLogic(gs, gs.difficulty , row, col);
            playMove(gs, row, col);
        }
        calculateLegalMoves(gs);
    }
    printBoard(gs);
    if (gs.nbP[false] > gs.nbP[true])
        cout << "NOIR A GAGNE! ";
    else if (gs.nbP[false] < gs.nbP[true])
        cout << "BLANC A GAGNE! ";
    else
        cout << " EGALITE! ";
}
