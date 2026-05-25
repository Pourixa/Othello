#ifndef interface_h
#define interface_h
#include "data.h"
#include "graphics.h"
#include "funcs.h"
using namespace std;

const int OFFSET = 5;

const int BUTTON_COLOR_MAIN = LIGHTGRAY;
const int BUTTON_COLOR_SECOND = DARKGRAY;
const int BUTTON_COLOR_TEXT = DARKGRAY;

const int BOARD_COLOR_MAIN = GREEN;
const int BOARD_COLOR_SECOND = DARKGRAY;
const int BOARD_COLOR_LINES = BLACK;

const int BOX_COLOR_MAIN = LIGHTGREEN;
const int BOX_COLOR_SECOND = DARKGRAY;
const int BOARD_X1 =100 , BOARD_Y1 = 20 , BOARD_X2 = 880 , BOARD_Y2 = 800;

void firstPositionBoard(int x1 ,int y1 , int x2 , int y2 ,int boardSize);
void secondPositionBoard(int x1 ,int y1 , int x2 , int y2 ,int boardSize);
void button(int x1 , int y1 , int x2 , int y2 ,int font ,int fontSize ,const char * text);

void box(int x1 , int y1 , int x2 , int y2 );

void showLegalMoves(const gameState& gs);
void playLegalInterface(const gameState&gs,int legalID);
void mesPages(UI &ui);
void dessinPage(const UI &ui, const gameState &game,int selectableZoneID);
bool unCLic(UI &ui, int x, int y, gameState &game,int& ID);

#endif