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