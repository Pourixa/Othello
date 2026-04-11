#include "interface.h"
using namespace std;


void button(int x1 , int y1 , int x2 , int y2 ,int font ,int fontSize ,const char * text)
{
    int midx = x1 + (x2-x1)/2;
    int midy = y1 + (y2-y1)/2;
    setcolor(BUTTON_COLOR_SECOND);
    setfillstyle(SOLID_FILL,BUTTON_COLOR_SECOND);
    bar(x1-5,y1-5,x2+5,y2+5);
    setfillstyle(SOLID_FILL,BUTTON_COLOR_MAIN);
    setcolor(BUTTON_COLOR_MAIN);
    bar(x1,y1,x2,y2);

    setbkcolor( BUTTON_COLOR_MAIN );
    setcolor(BUTTON_COLOR_TEXT);

    settextjustify(CENTER_TEXT, CENTER_TEXT);
    settextstyle(font,0,fontSize);
    outtextxy(midx,midy,text);
}

void firstPositionBoard(int x1 ,int y1 , int x2 , int y2 ,int boardSize)
{
    int dy = (y2-y1)/boardSize;
    int dx = (x2-x1)/boardSize;
    int rad = dx/2 - boardSize/4;
    setfillstyle(SOLID_FILL,BOARD_COLOR_SECOND);
    bar(x1-5,y1-5,x2+5,y2+5);
    setfillstyle(SOLID_FILL,BOARD_COLOR_MAIN);
    bar(x1,y1,x2,y2);

    setcolor(BOARD_COLOR_LINES);
    for(int i = 0 ; i<boardSize-1; i++)
    {
        int x = x1 + dx * (i+1);
        int y = y1 + dy * (i+1);
        line(x , y1,x, y2);
        line(x1,y,x2,y);
    }
    setcolor(WHITE);
    int midX =  x1 + dx * boardSize/2 ;
    int midY = y1 + dy * boardSize/2;
    int cX1 = midX - dx/2 ;
    int cX2 = midX + dx/2;
    int cY1 = midY -  dy/2;
    int cY2 = midY + dy/2;
    //white tokens

    setcolor(BLACK);
    setfillstyle(SOLID_FILL,WHITE);
    fillellipse(cX1,cY1 ,rad,rad);
    fillellipse(cX2 ,cY2 ,rad,rad);

    //black token

    setcolor(WHITE);
    setfillstyle(SOLID_FILL,BLACK);
    fillellipse(cX2 ,cY1 ,rad,rad);
    fillellipse(cX1 ,cY2,rad,rad);
}

void secondPositionBoard(int x1 ,int y1 , int x2 , int y2 ,int boardSize)
{
    int dy = (y2-y1)/boardSize;
    int dx = (x2-x1)/boardSize;
    int rad = dx/2 - boardSize/4;
    setfillstyle(SOLID_FILL,BOARD_COLOR_SECOND);
    bar(x1-5,y1-5,x2+5,y2+5);
    setfillstyle(SOLID_FILL,BOARD_COLOR_MAIN);
    bar(x1,y1,x2,y2);

    setcolor(BOARD_COLOR_LINES);
    for(int i = 0 ; i<boardSize-1; i++)
    {
        int x = x1 + dx * (i+1);
        int y = y1 + dy * (i+1);
        line(x , y1,x, y2);
        line(x1,y,x2,y);
    }
    setcolor(WHITE);
    int midX =  x1 + dx * boardSize/2 ;
    int midY = y1 + dy * boardSize/2;
    int cX1 = midX - dx/2 ;
    int cX2 = midX + dx/2;
    int cY1 = midY -  dy/2;
    int cY2 = midY + dy/2;
    //white tokens

    setcolor(BLACK);
    setfillstyle(SOLID_FILL,WHITE);
    fillellipse(cX2 ,cY2 ,rad,rad);
    fillellipse(cX1 ,cY2,rad,rad);


    //black token

    setcolor(WHITE);
    setfillstyle(SOLID_FILL,BLACK);

    fillellipse(cX1,cY1 ,rad,rad);
    fillellipse(cX2 ,cY1 ,rad,rad);
}
