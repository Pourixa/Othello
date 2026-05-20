#include <iostream>
#include "data.h"
#include "cmath"
using namespace std;

//gamePart

bool addEmptyCell(gameState& gs , int row , int col);
bool removeEmptyCell(gameState& gs,int row , int col);
//0 for standard position , 1 for 2 up 2 down pos
void initGame(gameState& gs , int n ,int choice);
bool checkCell(const gameState& gs,int row , int col ,int color);
bool isEmptyCellLegalOneDirection(const gameState& gs ,legalMove& lm , const emptyCell& cell ,int rowDirection , int colDirection);
bool isEmptyCellLegal(const gameState& gs ,legalMove& lm , const emptyCell& cell);
void calculateLegalMoves(gameState& gs);
bool verifyClick(const gameState& gs , int boardX1 ,int boardY1 , int boardX2 ,int boardY2 ,int xMouse , int yMouse , int& row ,int& col);
bool isClickLegal(const gameState& gs,int row , int col , int& id);
void playLegal(gameState& gs,int id);
void addEmptyCellOneDirection(gameState&gs ,int row , int col, int rowDirection , int colDirection);
void addEmptyCellAllDirections(gameState& gs , int row , int col);
bool playMove(gameState& gs  , int row , int col);
bool isGameOver(gameState gs);

