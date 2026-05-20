#include <array>
using namespace  std;

const int CLICKABLE_BUTTON_SIZE = 10;
const int SELECTABLE_BUTTON_SIZE = 10;
const int TEXT_SIZE = 10;
const int CLICKABLE_ZONE_SIZE = 10;
const int SELECTABLE_ZONE_SIZE = 10;
const int NAVIG_BUTTON_SIZE = 2;
const int NAVIG_ZONE_SIZE = 2;
const int BOARD_T1 = 8;
const int BOARD_T2 = 8 ;
const int PAGE_SIZE = 10;

const int CELL_SIZE = 64;
const int FLIP_CELL_SIZE = 64;
const int LEGALMOVE_SIZE = 34;

struct box
{
    int x1, y1 , x2 , y2;
};

struct text
{
    int x, y;
    char* t;
    int font;
    int fontSize;
};

struct textButton
{
    char* t ;
    int font ;
    int fontSize;
};

using textList = array<text,TEXT_SIZE>;

struct clickableButton
{
    int x1,x2,x3 ,x4;
    textButton t;
    int id;
};

using clickableButtonList = array<clickableButton,CLICKABLE_BUTTON_SIZE>;

struct clickableZone
{
    int x1,y1 , x2 ,y2;
    int n;
    clickableButtonList bl;
};
using clickableZoneList = array<clickableZone , CLICKABLE_ZONE_SIZE>;

struct selectableButton {
    clickableButton b;
    bool selected ;
};

using selectableButtonList = array<selectableButton,SELECTABLE_BUTTON_SIZE>;

struct selectableZone
{
    int x1,y1,x2,y2;
    int n;
    selectableButtonList bl;
};

using selectableZoneList = array<selectableZone , SELECTABLE_ZONE_SIZE>;

struct navigButton {
    clickableButton b;
    int toPage;
};

using navigButtonList = array<navigButton, NAVIG_BUTTON_SIZE>;

struct navigZone
{
 int x1,y1,x2,y2;
 int n;
 navigButtonList bs;
};

using navigZoneList = array<navigZone,NAVIG_ZONE_SIZE>;

struct page
{
box bgBox;
int nbTexts , nbClickableZones  , nbSelectableZones , nbNavigZones;
textList tl;
clickableZoneList cl;
navigZoneList nl;
selectableZoneList sl;
};
using pageList = array<page,PAGE_SIZE>;

struct UI{
    int pageID;
    pageList pl;
};

///////////////game
struct cell
{
    int id ;
    int color;
};
struct flipCell {
    int row, col;
};

struct emptyCell
{
    int row , col;
};


using boardArray = array<array<cell , BOARD_T2>,BOARD_T1>;
using emptyCellArray = array<emptyCell,CELL_SIZE>;
using flipArray = array<flipCell,FLIP_CELL_SIZE>;


struct emptyCells{
    emptyCellArray ec;
    int n;
};


struct legalMove
{
    int row , col;
    int flipCount;
    flipArray toFlip;
};

using legalArray = array<legalMove,LEGALMOVE_SIZE>;

struct legalMoves
{
    legalArray legals;
    int n;
};

using numberOfPions =array<int , 2>;

struct gameState {
    boardArray b;
    int n; //board size
    emptyCells ec;
    legalMoves legal;
    numberOfPions nbP; // 0 : black , 1 : white
    bool currentPlayer; // false : black , true: white
    bool gameOver;
};