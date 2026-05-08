#include <array>
using namespace  std;

const int BUTTON_SIZE = 10;
const int SELECTABLE_BUTTON_SIZE = 10;
const int TEXT_SIZE = 10;
const int ZONE_SIZE = 10;
const int SELECTABLE_ZONE_SIZE = 10;

const int BOARD_T1 = 8;
const int BOARD_T2 = 8 ;

const int CELL_SIZE = 64;
const int FLIP_CELL_SIZE = 64;
const int LEGALMOVE_SIZE = 34;


struct box
{
    int x1, y1 , x2 , y2;
};

struct text
{
    double x, y;
    char* t;
    int font;
    int fontSize;
};

using texts = array<text,TEXT_SIZE>;

struct button
{
    int x1,x2,x3 ,x4;
    text t;
};

using buttons = array<button,BUTTON_SIZE>;

struct selectableButton {
    button b;
    bool selected ;
};

using selectableButtons = array<selectableButton,SELECTABLE_BUTTON_SIZE>;

struct zone
{
    int x1,y1 , x2 ,y2;
    int n;
    buttons bs;
};

using zones = array<zone , ZONE_SIZE>;

struct selectableZone
{
    int x1,y1,x2,y2;
    int n;
    selectableButtons bs;
};

using selectableZones = array<selectableZone , SELECTABLE_ZONE_SIZE>;

struct page
{
box bgBox;
int nbTexts , nbZones , nbSelectableZones;
texts ts;
zones zs;
selectableZones szs;
};
struct cell
{
    int row , col;
    int color; // -1 : empty , 0 : black , 1 : white
};

struct flipCell {
    int row, col;
};

using boardArray = array<array<cell , BOARD_T2>,BOARD_T1>;
using cellArray = array<cell,CELL_SIZE>;
using flipArray = array<flipCell,FLIP_CELL_SIZE>;

struct emptyCells{
    cellArray empty;
    int n;
};


struct legalMove
{
    int row , col;
    int flipCount;
    flipCell toFlip;
};

using legalArray = array<legalMove,CELL_SIZE>;

struct legalMoves
{
    legalArray legals;
    int n;
};

struct gameState {
    boardArray b;
    int n; //board size
    emptyCells empty;
    legalMoves legal;
    int whiteScore;
    int blackScore;
    int currentPlayer;
    bool gameOver;
};