#include <string>
#include "graphics.h"
using namespace std;


int main()
{
opengraphsize(200,200);
    button(40,40,140,70,DEFAULT_FONT,1,RED,WHITE,"Jouer");
    button(40,72,140,122,DEFAULT_FONT,1,RED,WHITE,"Fermer");
    button(40,124,140,174,DEFAULT_FONT,1,RED,WHITE,"Ouvrir");
getch();
}