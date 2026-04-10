#include "interface.h"
using namespace std;

void button(int x1 , int y1 , int x2 , int y2 ,int font ,int fontSize , int boxColor,int textColor,const char * text)
{
    int midx = x1 + (x2-x1)/2;
    int midy = y1 + (y2-y1)/2;
    setfillstyle(SOLID_FILL,boxColor);
    setcolor(boxColor);
    bar(x1,y1,x2,y2);
    setbkcolor( boxColor );
    setcolor(textColor);
    settextjustify(CENTER_TEXT, CENTER_TEXT);
    settextstyle(font,0,fontSize);
    outtextxy(midx,midy,text);
}

void firstPositionDepart(int x1 , int y1 , int x2 , int y2)
{
    int dx = (x2 - x1);
    int dy = (y2 - y1);
    int midx  = x1 + dx/2;
    int midy = y1 + dy/2;
    int rad = dx/4 -1;
    setcolor(WHITE);
    setfillstyle(SOLID_FILL,GREEN);
    bar(x1,y1,x2,y2);
    setcolor(BLACK);
    rectangle(x1,y1,x2,y2); //for outline
    line(midx,y1,midx,y2);
    line(x1,midy,x2,midy);
    //white tokens

    setcolor(BLACK);
    setfillstyle(SOLID_FILL,WHITE);
    fillellipse(x1+dx/4 + 1,y1+dy/4 + 1,rad,rad);
    fillellipse(x2-dx/4 ,y2-dy/4 ,rad,rad);

    //black token

    setcolor(WHITE);
    setfillstyle(SOLID_FILL,BLACK);
    fillellipse(x2-dx/4 ,y1+dy/4 + 1,rad,rad);
    fillellipse(x1+dx/4 + 1 ,y2-dy/4 ,rad,rad);
}

void secondPositionDepart(int x1 , int y1 , int x2 , int y2)
{
    int dx = (x2 - x1);
    int dy = (y2 - y1);
    int midx  = x1 + dx/2;
    int midy = y1 + dy/2;
    int rad = dx/4 -1;
    setcolor(WHITE);
    setfillstyle(SOLID_FILL,GREEN);
    bar(x1,y1,x2,y2);
    setcolor(BLACK);
    rectangle(x1,y1,x2,y2); //for outline
    line(midx,y1,midx,y2);
    line(x1,midy,x2,midy);
    //white tokens

    setcolor(BLACK);
    setfillstyle(SOLID_FILL,WHITE);
    fillellipse(x1+dx/4 + 1 ,y2-dy/4 ,rad,rad);

    fillellipse(x2-dx/4 ,y2-dy/4 ,rad,rad);

    //black token

    setcolor(WHITE);
    setfillstyle(SOLID_FILL,BLACK);
    fillellipse(x2-dx/4 ,y1+dy/4 + 1,rad,rad);
    fillellipse(x1+dx/4 + 1,y1+dy/4 + 1,rad,rad);
}