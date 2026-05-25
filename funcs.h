#include <iostream>
#include "data.h"
#include "cmath"
#include <random>
using namespace std;

//gamePart

bool addEmptyCell(gameState& gs , int row , int col);
bool removeEmptyCell(gameState& gs,int row , int col);
//0 for standard position , 1 for 2 up 2 down pos
void initGame(gameState& gs);
bool checkCell(const gameState& gs,int row , int col ,int color);
bool isEmptyCellLegalOneDirection(const gameState& gs ,legalMove& lm , const emptyCell& cell ,int rowDirection , int colDirection);
bool isEmptyCellLegal(const gameState& gs ,legalMove& lm , const emptyCell& cell);
void calculateLegalMoves(gameState& gs);
bool verifyClick(const gameState& gs , int boardX1 ,int boardY1 , int boardX2 ,int boardY2 ,int xMouse , int yMouse , int& row ,int& col);
bool isClickLegal(const gameState& gs,int row , int col , int& id);
void playLegal(gameState& gs,int id);
void addEmptyCellOneDirection(gameState&gs ,int row , int col, int rowDirection , int colDirection);
void addEmptyCellAllDirections(gameState& gs , int row , int col);
bool playMove(gameState& gs  , int row , int col,int &id);
bool isGameOver(gameState gs);

int evaluateState(const gameState &gs);

void printBoard(const gameState &gs) ;

int minimax(const gameState &gs, int level, int depth,int alpha ,int beta, int &row, int &col);

void botLogic(const gameState &gs, int difficulty, int &row, int &col);

void playConsoleGameVSPlayer();

void playConsoleGameVSBot() ;

void playConsoleBotVSBot();

