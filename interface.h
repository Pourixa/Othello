#include "graphics.h"

using namespace std;

const int BUTTON_COLOR_MAIN = LIGHTGRAY;
const int BUTTON_COLOR_SECOND = DARKGRAY;
const int BUTTON_COLOR_TEXT = DARKGRAY;

const int BOARD_COLOR_MAIN = GREEN;
const int BOARD_COLOR_SECOND = DARKGRAY;
const int BOARD_COLOR_LINES = BLACK;

void firstPositionBoard(int x1 ,int y1 , int x2 , int y2 ,int boardSize);
void secondPositionBoard(int x1 ,int y1 , int x2 , int y2 ,int boardSize);
void button(int x1 , int y1 , int x2 , int y2 ,int font ,int fontSize ,const char * text);