#include "graphics.h"
#include "data.h"
#include "interface.h"
#include <cstring>
#include "funcs.h"
using namespace std;

char statutTexte[100] = "Les noirs commencent.";
int statutColor = YELLOW;
int popupActive = 0;


void button(int x1 , int y1 , int x2 , int y2 ,int font ,int fontSize ,const char * text)
{
    int midx = x1 + (x2-x1)/2;
    int midy = y1 + (y2-y1)/2;
    setcolor(BUTTON_COLOR_SECOND);
    setfillstyle(SOLID_FILL,BUTTON_COLOR_SECOND);
    bar(x1-OFFSET,y1-OFFSET,x2+OFFSET,y2+OFFSET);
    setfillstyle(SOLID_FILL,BUTTON_COLOR_MAIN);
    setcolor(BUTTON_COLOR_MAIN);
    bar(x1,y1,x2,y2);

    setbkcolor( BUTTON_COLOR_MAIN );
    setcolor(BUTTON_COLOR_TEXT);

    settextjustify(CENTER_TEXT, CENTER_TEXT);
    settextstyle(font,0,fontSize);
    outtextxy(midx,midy,text);

    outtextxy(midx,midy,text);

    setcolor(WHITE);
    setbkcolor(BLACK);
}

void firstPositionBoard(int x1 ,int y1 , int x2 , int y2 ,int boardSize)
{
    int dy = (y2-y1)/boardSize;
    int dx = (x2-x1)/boardSize;
    int rad = dx/2 - boardSize/4;
    setfillstyle(SOLID_FILL,BOARD_COLOR_SECOND);
    bar(x1-OFFSET,y1-OFFSET,x2+OFFSET,y2+OFFSET);
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

    setcolor(WHITE);
    setfillstyle(SOLID_FILL,WHITE);
    fillellipse(cX1,cY1 ,rad,rad);
    fillellipse(cX2 ,cY2 ,rad,rad);

    //black token

    setcolor(BLACK);
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
    bar(x1-OFFSET,y1-OFFSET,x2+OFFSET,y2+OFFSET);
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

    setcolor(WHITE);
    setfillstyle(SOLID_FILL,WHITE);
    fillellipse(cX2 ,cY2 ,rad,rad);
    fillellipse(cX1 ,cY2,rad,rad);


    //black token

    setcolor(BLACK);
    setfillstyle(SOLID_FILL,BLACK);

    fillellipse(cX1,cY1 ,rad,rad);
    fillellipse(cX2 ,cY1 ,rad,rad);
}

void box(int x1 , int y1 , int x2 , int y2 )
{
    setcolor(BOX_COLOR_SECOND);
    setfillstyle(SOLID_FILL,BOX_COLOR_SECOND);
    bar(x1-OFFSET,y1-OFFSET,x2+OFFSET,y2+OFFSET);

    setcolor(BOX_COLOR_MAIN);
    setfillstyle(SOLID_FILL,BOX_COLOR_MAIN);
    bar(x1,y1,x2,y2);
}


void mesPages(UI &ui)
{
    page &p0 = ui.pl[0];

    p0.bgBox.x1 = 0;
    p0.bgBox.y1 = 0;
    p0.bgBox.x2 = 1580;
    p0.bgBox.y2 = 920;

    p0.nbTexts = 6;
    p0.nbNavigZones = 1;
    p0.nbSelectableZones = 1;
    p0.nbClickableZones = 0;

    // --- TEXTES PAGE 0 ---
    p0.tl[0].x = 750;
    p0.tl[0].y = 400;
    p0.tl[0].t = (char*)"Othello";
    p0.tl[0].font = 1;
    p0.tl[0].fontSize = 16;

    p0.tl[1].x = 80;
    p0.tl[1].y = 60;
    p0.tl[1].t = (char*)"Choix du mode de";
    p0.tl[1].font = 0;
    p0.tl[1].fontSize = 3;

    p0.tl[2].x = 220;
    p0.tl[2].y = 90;
    p0.tl[2].t = (char*)"jeu";
    p0.tl[2].font = 0;
    p0.tl[2].fontSize = 3;

    p0.tl[3].x = 120;
    p0.tl[3].y = 260;
    p0.tl[3].t = (char*)"Jouer en 1 vs 1";
    p0.tl[3].font = 0;
    p0.tl[3].fontSize = 3;

    p0.tl[4].x = 100;
    p0.tl[4].y = 500;
    p0.tl[4].t = (char*)"Jouer contre un";
    p0.tl[4].font = 0;
    p0.tl[4].fontSize = 3;

    p0.tl[5].x = 150;
    p0.tl[5].y = 530;
    p0.tl[5].t = (char*)"ordinateur";
    p0.tl[5].font = 0;
    p0.tl[5].fontSize = 3;

    // --- NAVIGATIONS PAGE 0 ---
    navigZone &zoneNav = p0.nl[0];
    zoneNav.n = 4;

    zoneNav.bs[0].b.x1 = 1400;
    zoneNav.bs[0].b.y1 = 30;
    zoneNav.bs[0].b.x2 = 1540;
    zoneNav.bs[0].b.y2 = 100;
    zoneNav.bs[0].b.id = 101;
    zoneNav.bs[0].b.t.t = (char*)"Regle";
    zoneNav.bs[0].b.t.font = 0;
    zoneNav.bs[0].b.t.fontSize = 3;
    zoneNav.bs[0].toPage = 1;

    zoneNav.bs[1].b.x1 = 1380;
    zoneNav.bs[1].b.y1 = 820;
    zoneNav.bs[1].b.x2 = 1540;
    zoneNav.bs[1].b.y2 = 890;
    zoneNav.bs[1].b.id = 102;
    zoneNav.bs[1].b.t.t = (char*)"Sortie";
    zoneNav.bs[1].b.t.font = 0;
    zoneNav.bs[1].b.t.fontSize = 3;
    zoneNav.bs[1].toPage = -1;

    zoneNav.bs[2].b.x1 = 220;
    zoneNav.bs[2].b.y1 = 340;
    zoneNav.bs[2].b.x2 = 360;
    zoneNav.bs[2].b.y2 = 420;
    zoneNav.bs[2].b.id = 103;
    zoneNav.bs[2].b.t.t = (char*)"Jouer";
    zoneNav.bs[2].b.t.font = 0;
    zoneNav.bs[2].b.t.fontSize = 3;
    zoneNav.bs[2].toPage = 3;

    zoneNav.bs[3].b.x1 = 220;
    zoneNav.bs[3].b.y1 = 790;
    zoneNav.bs[3].b.x2 = 360;
    zoneNav.bs[3].b.y2 = 870;
    zoneNav.bs[3].b.id = 104;
    zoneNav.bs[3].b.t.t = (char*)"Jouer";
    zoneNav.bs[3].b.t.font = 0;
    zoneNav.bs[3].b.t.fontSize = 3;
    zoneNav.bs[3].toPage = 3;

    // --- SELECTIONS PAGE 0 ---
    selectableZone &zoneCouleur = p0.sl[0];
    zoneCouleur.n = 2;

    zoneCouleur.bl[0].b.x1 = 100;
    zoneCouleur.bl[0].b.y1 = 630;
    zoneCouleur.bl[0].b.x2 = 230;
    zoneCouleur.bl[0].b.y2 = 700;
    zoneCouleur.bl[0].b.id = 201;
    zoneCouleur.bl[0].b.t.t = (char*)"Noir";
    zoneCouleur.bl[0].b.t.font = 0;
    zoneCouleur.bl[0].b.t.fontSize = 3;
    zoneCouleur.bl[0].selected = true;

    zoneCouleur.bl[1].b.x1 = 340;
    zoneCouleur.bl[1].b.y1 = 630;
    zoneCouleur.bl[1].b.x2 = 470;
    zoneCouleur.bl[1].b.y2 = 700;
    zoneCouleur.bl[1].b.id = 202;
    zoneCouleur.bl[1].b.t.t = (char*)"Blanc";
    zoneCouleur.bl[1].b.t.font = 0;
    zoneCouleur.bl[1].b.t.fontSize = 3;
    zoneCouleur.bl[1].selected = false;

    // PAGE 1 : LES RÈGLES
    page &pageRegles = ui.pl[1];
    pageRegles.bgBox.x1 = 0;
    pageRegles.bgBox.y1 = 0;
    pageRegles.bgBox.x2 = 1580;
    pageRegles.bgBox.y2 = 920;

    pageRegles.nbTexts = 24;
    pageRegles.nbNavigZones = 1;
    pageRegles.nbClickableZones = 0;
    pageRegles.nbSelectableZones = 0;

    pageRegles.tl[0].x = 200;
    pageRegles.tl[0].y = 40;
    pageRegles.tl[0].t = (char*)"Les regles du jeu d'othello";
    pageRegles.tl[0].font = 1;
    pageRegles.tl[0].fontSize = 7;

    pageRegles.tl[1].x = 20;
    pageRegles.tl[1].y = 150;
    pageRegles.tl[1].t = (char*)"Le commencement de la partie :";
    pageRegles.tl[1].font = 1;
    pageRegles.tl[1].fontSize = 1;

    pageRegles.tl[2].x = 20;
    pageRegles.tl[2].y = 170;
    pageRegles.tl[2].t = (char*)"Vous avez le choix entre deux positions de departs:";
    pageRegles.tl[2].font = 1;
    pageRegles.tl[2].fontSize = 1;

    pageRegles.tl[3].x = 20;
    pageRegles.tl[3].y = 190;
    pageRegles.tl[3].t = (char*)"Vous pouvez les poser au centre du terrain a la diagonale, premiere ligne centrale blanc noir et la suivante noir blanc.";
    pageRegles.tl[3].font = 1;
    pageRegles.tl[3].fontSize = 1;

    pageRegles.tl[4].x = 20;
    pageRegles.tl[4].y = 210;
    pageRegles.tl[4].t = (char*)"Soit les poser au centre du terrain en ligne de la meme couleur, premiere ligne noir noir et la suivante blanc blanc.";
    pageRegles.tl[4].font = 1;
    pageRegles.tl[4].fontSize = 1;

    pageRegles.tl[5].x = 20;
    pageRegles.tl[5].y = 230;
    pageRegles.tl[5].t = (char*)"Ensuite les noirs commencent la partie obligatoirement.";
    pageRegles.tl[5].font = 1;
    pageRegles.tl[5].fontSize = 1;

    pageRegles.tl[6].x = 20;
    pageRegles.tl[6].y = 270;
    pageRegles.tl[6].t = (char*)"Mecanisme de capture :";
    pageRegles.tl[6].font = 1;
    pageRegles.tl[6].fontSize = 1;

    pageRegles.tl[7].x = 20;
    pageRegles.tl[7].y = 290;
    pageRegles.tl[7].t = (char*)"Un jeton est capture lorsqu'il est entoure (pris en sandwich) par deux jetons de la couleur adverse.";
    pageRegles.tl[7].font = 1;
    pageRegles.tl[7].fontSize = 1;

    pageRegles.tl[8].x = 20;
    pageRegles.tl[8].y = 310;
    pageRegles.tl[8].t = (char*)"La capture peut se faire a l'horizontale, a la verticale et sur les deux diagonales.";
    pageRegles.tl[8].font = 1;
    pageRegles.tl[8].fontSize = 1;

    pageRegles.tl[9].x = 20;
    pageRegles.tl[9].y = 330;
    pageRegles.tl[9].t = (char*)"Le jeton capture prend alors la couleur de celui qui l'entoure.";
    pageRegles.tl[9].font = 1;
    pageRegles.tl[9].fontSize = 1;

    pageRegles.tl[10].x = 20;
    pageRegles.tl[10].y = 370;
    pageRegles.tl[10].t = (char*)"Regle pour poser un pion :";
    pageRegles.tl[10].font = 1;
    pageRegles.tl[10].fontSize = 1;

    pageRegles.tl[11].x = 20;
    pageRegles.tl[11].y = 390;
    pageRegles.tl[11].t = (char*)"Pour pouvoir poser un jeton, le joueur doit obligatoirement effectuer au moins une capture.";
    pageRegles.tl[11].font = 1;
    pageRegles.tl[11].fontSize = 1;

    pageRegles.tl[12].x = 20;
    pageRegles.tl[12].y = 410;
    pageRegles.tl[12].t = (char*)"S'il ne peut capturer aucun jeton ennemi, il doit passer son tour et laisser son adversaire jouer.";
    pageRegles.tl[12].font = 1;
    pageRegles.tl[12].fontSize = 1;

    pageRegles.tl[13].x = 20;
    pageRegles.tl[13].y = 430;
    pageRegles.tl[13].t = (char*)"La partie s'arrete si aucun des deux joueurs ne peut plus jouer (meme si le plateau n'est pas plein = Cas 3).";
    pageRegles.tl[13].font = 1;
    pageRegles.tl[13].fontSize = 1;

    pageRegles.tl[14].x = 20;
    pageRegles.tl[14].y = 470;
    pageRegles.tl[14].t = (char*)"Mecanisme de capture multiple :";
    pageRegles.tl[14].font = 1;
    pageRegles.tl[14].fontSize = 1;

    pageRegles.tl[15].x = 20;
    pageRegles.tl[15].y = 490;
    pageRegles.tl[15].t = (char*)"Un seul jeton pose peut capturer plusieurs jetons adverses dans differentes directions simultanement.";
    pageRegles.tl[15].font = 1;
    pageRegles.tl[15].fontSize = 1;

    pageRegles.tl[16].x = 20;
    pageRegles.tl[16].y = 530;
    pageRegles.tl[16].t = (char*)"Regle subtile de capture :";
    pageRegles.tl[16].font = 1;
    pageRegles.tl[16].fontSize = 1;

    pageRegles.tl[17].x = 20;
    pageRegles.tl[17].y = 550;
    pageRegles.tl[17].t = (char*)"La capture ne fonctionne que si les jetons adverses forment une ligne continue (sans case vide) entre le jeton pose et un";
    pageRegles.tl[17].font = 1;
    pageRegles.tl[17].fontSize = 1;

    pageRegles.tl[18].x = 20;
    pageRegles.tl[18].y = 570;
    pageRegles.tl[18].t = (char*)"autre jeton de votre couleur deja present.";
    pageRegles.tl[18].font = 1;
    pageRegles.tl[18].fontSize = 1;

    pageRegles.tl[19].x = 20;
    pageRegles.tl[19].y = 630;
    pageRegles.tl[19].t = (char*)"Fin de partie :";
    pageRegles.tl[19].font = 1;
    pageRegles.tl[19].fontSize = 1;

    pageRegles.tl[20].x = 20;
    pageRegles.tl[20].y = 650;
    pageRegles.tl[20].t = (char*)"Quand la partie se finit plus aucun joueurs peut poder de jetons sur le plateau:";
    pageRegles.tl[20].font = 1;
    pageRegles.tl[20].fontSize = 1;

    pageRegles.tl[21].x = 20;
    pageRegles.tl[21].y = 670;
    pageRegles.tl[21].t = (char*)"Cas 1: Il ne reste plus qu'une seule couleur sur le plateau.";
    pageRegles.tl[21].font = 1;
    pageRegles.tl[21].fontSize = 1;

    pageRegles.tl[22].x = 20;
    pageRegles.tl[22].y = 690;
    pageRegles.tl[22].t = (char*)"Cas 2: Le plateau est rempli. On compte alors les jetons: celui qui en possede le plus a gagne.";
    pageRegles.tl[22].font = 1;
    pageRegles.tl[22].fontSize = 1;

    pageRegles.tl[23].x = 20;
    pageRegles.tl[23].y = 710;
    pageRegles.tl[23].t = (char*)"Cas 3: plus aucune pause n'est possible. On compte alors les jetons: celui qui en possede le plus a gagne.";
    pageRegles.tl[23].font = 1;
    pageRegles.tl[23].fontSize = 1;

    navigZone &zoneRetour = pageRegles.nl[0];
    zoneRetour.n = 1;
    navigButton &btnRetour = zoneRetour.bs[0];
    btnRetour.b.x1 = 1350;
    btnRetour.b.y1 = 800;
    btnRetour.b.x2 = 1500;
    btnRetour.b.y2 = 870;
    btnRetour.b.id = 105;
    btnRetour.b.t.t = (char*)"RETOUR";
    btnRetour.b.t.font = 0;
    btnRetour.b.t.fontSize = 3;
    btnRetour.toPage = 0;

    // PAGE 3 : LES CHOIX
    page &p3 = ui.pl[3];

    p3.bgBox.x1 = 0;
    p3.bgBox.y1 = 0;
    p3.bgBox.x2 = 1580;
    p3.bgBox.y2 = 920;

    p3.nbTexts = 3;
    p3.nbSelectableZones = 3;
    p3.nbNavigZones = 2;
    p3.nbClickableZones = 0;

    p3.tl[0].x = 540;
    p3.tl[0].y = 120;
    p3.tl[0].t = (char*)"Position de depart :";
    p3.tl[0].font = 0;
    p3.tl[0].fontSize = 3;

    p3.tl[1].x = 540;
    p3.tl[1].y = 420;
    p3.tl[1].t = (char*)"Taille du terrain :";
    p3.tl[1].font = 0;
    p3.tl[1].fontSize = 3;

    p3.tl[2].x = 580;
    p3.tl[2].y = 620;
    p3.tl[2].t = (char*)"Aide visuelle ?";
    p3.tl[2].font = 0;
    p3.tl[2].fontSize = 3;

    // ZONE 0 : Position de départ
    selectableZone &zonePos = p3.sl[0];
    zonePos.n = 2;

    zonePos.bl[0].b.x1 = 380;
    zonePos.bl[0].b.y1 = 260;
    zonePos.bl[0].b.x2 = 600;
    zonePos.bl[0].b.y2 = 320;
    zonePos.bl[0].b.id = 301;
    zonePos.bl[0].b.t.t = (char*)"Selectionner";
    zonePos.bl[0].b.t.font = 0;
    zonePos.bl[0].b.t.fontSize = 2;
    zonePos.bl[0].selected = true;

    zonePos.bl[1].b.x1 = 1000;
    zonePos.bl[1].b.y1 = 260;
    zonePos.bl[1].b.x2 = 1220;
    zonePos.bl[1].b.y2 = 320;
    zonePos.bl[1].b.id = 302;
    zonePos.bl[1].b.t.t = (char*)"Selectionner";
    zonePos.bl[1].b.t.font = 0;
    zonePos.bl[1].b.t.fontSize = 2;
    zonePos.bl[1].selected = false;

    selectableZone &zoneGrille = p3.sl[1];
    zoneGrille.n = 3;

    zoneGrille.bl[0].b.x1 = 280;
    zoneGrille.bl[0].b.y1 = 500;
    zoneGrille.bl[0].b.x2 = 500;
    zoneGrille.bl[0].b.y2 = 560;
    zoneGrille.bl[0].b.id = 8;
    zoneGrille.bl[0].b.t.t = (char*)"Selectionner";
    zoneGrille.bl[0].b.t.font = 0;
    zoneGrille.bl[0].b.t.fontSize = 2;
    zoneGrille.bl[0].selected = true;

    zoneGrille.bl[1].b.x1 = 700;
    zoneGrille.bl[1].b.y1 = 500;
    zoneGrille.bl[1].b.x2 = 920;
    zoneGrille.bl[1].b.y2 = 560;
    zoneGrille.bl[1].b.id = 6;
    zoneGrille.bl[1].b.t.t = (char*)"Selectionner";
    zoneGrille.bl[1].b.t.font = 0;
    zoneGrille.bl[1].b.t.fontSize = 2;
    zoneGrille.bl[1].selected = false;

    zoneGrille.bl[2].b.x1 = 1100;
    zoneGrille.bl[2].b.y1 = 500;
    zoneGrille.bl[2].b.x2 = 1320;
    zoneGrille.bl[2].b.y2 = 560;
    zoneGrille.bl[2].b.id = 4;
    zoneGrille.bl[2].b.t.t = (char*)"Selectionner";
    zoneGrille.bl[2].b.t.font = 0;
    zoneGrille.bl[2].b.t.fontSize = 2;
    zoneGrille.bl[2].selected = false;

    selectableZone &zoneAide = p3.sl[2];
    zoneAide.n = 2;

    zoneAide.bl[0].b.x1 = 400;
    zoneAide.bl[0].b.y1 = 700;
    zoneAide.bl[0].b.x2 = 620;
    zoneAide.bl[0].b.y2 = 760;
    zoneAide.bl[0].b.id = 303;
    zoneAide.bl[0].b.t.t = (char*)"Oui";
    zoneAide.bl[0].b.t.font = DEFAULT_FONT;
    zoneAide.bl[0].b.t.fontSize = 2;
    zoneAide.bl[0].selected = true;

    zoneAide.bl[1].b.x1 = 1000;
    zoneAide.bl[1].b.y1 = 700;
    zoneAide.bl[1].b.x2 = 1220;
    zoneAide.bl[1].b.y2 = 760;
    zoneAide.bl[1].b.id = 304;
    zoneAide.bl[1].b.t.t = (char*)"Non";
    zoneAide.bl[1].b.t.font = DEFAULT_FONT;
    zoneAide.bl[1].b.t.fontSize = 2;
    zoneAide.bl[1].selected = false;

    p3.nl[0].n = 1;
    p3.nl[0].bs[0].b.x1 = 30;
    p3.nl[0].bs[0].b.y1 = 30;
    p3.nl[0].bs[0].b.x2 = 150;
    p3.nl[0].bs[0].b.y2 = 80;
    p3.nl[0].bs[0].b.id = 305;
    p3.nl[0].bs[0].b.t.t = (char*)"Fermer";
    p3.nl[0].bs[0].b.t.font = 0;
    p3.nl[0].bs[0].b.t.fontSize = 2;
    p3.nl[0].bs[0].toPage = 0;

    p3.nl[1].n = 1;
    p3.nl[1].bs[0].b.x1 = 690;
    p3.nl[1].bs[0].b.y1 = 790;
    p3.nl[1].bs[0].b.x2 = 890;
    p3.nl[1].bs[0].b.y2 = 840;
    p3.nl[1].bs[0].b.id = 306;
    p3.nl[1].bs[0].b.t.t = (char*)"Valider";
    p3.nl[1].bs[0].b.t.font = 0;
    p3.nl[1].bs[0].b.t.fontSize = 3;
    p3.nl[1].bs[0].toPage = 4;


    //j'initialise la page
    page &p4 = ui.pl[4];
    p4.bgBox.x1 = 0; p4.bgBox.y1 = 0; p4.bgBox.x2 = 1580; p4.bgBox.y2 = 920;
    p4.nbTexts = 0;
    p4.nbSelectableZones = 0;
    p4.nbClickableZones = 0;

    // Ajout des 2 boutons de droite (Réinitialiser et Accueil)
    p4.nbNavigZones = 1;
    navigZone &navP4 = p4.nl[0];
    navP4.n = 2;

    // Bouton 1 : Réinitialiser (En haut à droite)
    navP4.bs[0].b.x1 = 1150; navP4.bs[0].b.y1 = 150;
    navP4.bs[0].b.x2 = 1450; navP4.bs[0].b.y2 = 250;
    navP4.bs[0].b.id = 401; // ID unique
    navP4.bs[0].b.t.t = (char*)"Reinitialiser";
    navP4.bs[0].b.t.font = DEFAULT_FONT;
    navP4.bs[0].b.t.fontSize = 2;
    navP4.bs[0].toPage = 4;

    // Bouton 2 : Accueil (En bas à droite)
    navP4.bs[1].b.x1 = 1150; navP4.bs[1].b.y1 = 650;
    navP4.bs[1].b.x2 = 1450; navP4.bs[1].b.y2 = 750;
    navP4.bs[1].b.id = 402; // ID unique
    navP4.bs[1].b.t.t = (char*)"Accueil";
    navP4.bs[1].b.t.font = DEFAULT_FONT;
    navP4.bs[1].b.t.fontSize = 2;
    navP4.bs[1].toPage = 4;

    //Page 5;
    page &p5 = ui.pl[5];
    p5.bgBox.x1 = 0; p5.bgBox.y1 = 0; p5.bgBox.x2 = 1580; p5.bgBox.y2 = 920;
    p5.nbTexts = 0;
    p5.nbSelectableZones = 0;
    p5.nbClickableZones = 0;

    p5.nbNavigZones = 1;
    navigZone &navP5 = p5.nl[0];
    navP5.n = 2; // Il y a 2 boutons

    // Bouton 1 : Accueil (En haut à gauche comme sur ton image)
    navP5.bs[0].b.x1 = 30; navP5.bs[0].b.y1 = 30;
    navP5.bs[0].b.x2 = 200; navP5.bs[0].b.y2 = 100;
    navP5.bs[0].b.id = 501;
    navP5.bs[0].b.t.t = (char*)"Accueil";
    navP5.bs[0].b.t.font = DEFAULT_FONT;
    navP5.bs[0].b.t.fontSize = 2;
    navP5.bs[0].toPage = 0; // Renvoie à la page 0 (Accueil)

    // Bouton 2 : Recommencer (En bas au centre de la boîte cyan)
    navP5.bs[1].b.x1 = 600; navP5.bs[1].b.y1 = 700;
    navP5.bs[1].b.x2 = 980; navP5.bs[1].b.y2 = 800;
    navP5.bs[1].b.id = 502;
    navP5.bs[1].b.t.t = (char*)"Recommencer";
    navP5.bs[1].b.t.font = DEFAULT_FONT;
    navP5.bs[1].b.t.fontSize = 3;
    navP5.bs[1].toPage = 3; // Renvoie à la page 3 (Choix des paramètres)
}

void coordonneePlateau(int boardSize, int& x1, int& y1, int& x2, int& y2) {
    int taille_case = 80;
    int largeur_plateau = boardSize * taille_case;

    x1 = (1580 - largeur_plateau) / 2;
    x2 = x1 + largeur_plateau;
    y1 = (920 - largeur_plateau) / 2;
    y2 = y1 + largeur_plateau;
}

void showLegaMove(bool turn,int midx , int midy , int boardSize)
{
    int BOARD_X1, BOARD_Y1, BOARD_X2, BOARD_Y2;
    coordonneePlateau(boardSize, BOARD_X1, BOARD_Y1, BOARD_X2, BOARD_Y2);

    int dx = (BOARD_X2 - BOARD_X1)/boardSize;
    int rad = dx/2 - boardSize/4;
    if(turn)
        setcolor(WHITE);
    else
        setcolor(BLACK);
    circle(midx,midy,rad);
}



void convertToXY(int row , int col , int& x , int& y, int boardSize)
{
    int BOARD_X1, BOARD_Y1, BOARD_X2, BOARD_Y2;
    coordonneePlateau(boardSize, BOARD_X1, BOARD_Y1, BOARD_X2, BOARD_Y2);

    int dx = (BOARD_X2 - BOARD_X1)/boardSize;
    int dy = (BOARD_Y2 - BOARD_Y1)/boardSize;
    int cX0 = BOARD_X1 + dx/2;
    int cY0 = BOARD_Y1 + dy/2;

    x = cX0 + col * dx;
    y = cY0 + row * dy;
}

void showLegalMoves(const gameState& gs)
{
    int x,y;
    for(int i = 0 ; i<gs.legal.n ; i++)
    {
        convertToXY(gs.legal.legals[i].row,gs.legal.legals[i].col,x,y,gs.n);
        showLegaMove(gs.currentPlayer,x,y,gs.n);
    }

}

void putToken(bool turn,int row , int col,int boardSize)
{
    int BOARD_X1, BOARD_Y1, BOARD_X2, BOARD_Y2;
    coordonneePlateau(boardSize, BOARD_X1, BOARD_Y1, BOARD_X2, BOARD_Y2);

    int x ,y;
    int dx = (BOARD_X2 - BOARD_X1)/boardSize;
    int rad = dx/2 - boardSize/4;
    convertToXY(row,col,x,y,boardSize);
    if(turn)
    {
        setcolor(WHITE);
        setfillstyle(SOLID_FILL,WHITE);
        fillellipse(x,y,rad,rad);
    }
    else
    {
        setfillstyle(SOLID_FILL,BLACK);
        setcolor(BLACK);
        fillellipse(x ,y ,rad,rad);
    }
}

void turnTokens(bool turn,const legalMove& lm,int boardSize)
{
    for(int i = 0 ; i<lm.flipCount ; i++)
    {
        putToken(turn , lm.toFlip[i].row ,lm.toFlip[i].col,boardSize);
    }
}
void cleanCell(int x , int y,int boardSize)
{
    int BOARD_X1, BOARD_Y1, BOARD_X2, BOARD_Y2;
    coordonneePlateau(boardSize, BOARD_X1, BOARD_Y1, BOARD_X2, BOARD_Y2);

    int dx = (BOARD_X2 - BOARD_X1)/boardSize;
    int rad = dx/2 - boardSize/4;
    setcolor(GREEN);
    circle(x,y,rad);
}
void playLegalInterface(const gameState& gs , int legalID)
{
    int x,y;
    for(int i = 0 ; i<gs.legal.n ;i++)
    {
        convertToXY(gs.legal.legals[i].row,gs.legal.legals[i].col,x,y,gs.n);
        cleanCell(x,y,gs.n);
    }
    putToken(!gs.currentPlayer,gs.legal.legals[legalID].row,gs.legal.legals[legalID].col,gs.n);
    turnTokens(!gs.currentPlayer,gs.legal.legals[legalID],gs.n);
}

void dessinPage(UI &ui, gameState &game, int selectableZoneID, bool &hasLegal)
{
    const page& p = ui.pl[ui.pageID];

    if(selectableZoneID == -1) {
        setbkcolor(BLACK);
        setfillstyle(SOLID_FILL, BLACK);
        setcolor(BLACK);
        bar(p.bgBox.x1, p.bgBox.y1, p.bgBox.x2, p.bgBox.y2);

        if (ui.pageID == 0) {
            box(30, 30, 550, 890);
        }

        if (ui.pageID == 3) {
            box(60, 100, 1520, 860);
            firstPositionBoard(200, 180, 350, 330, 2);
            secondPositionBoard(800, 180, 950, 330, 2);
        }

        for (int i = 0; i < p.nbTexts; i++) {
            const text &t = p.tl[i];
            settextjustify(LEFT_TEXT, TOP_TEXT);
            settextstyle(t.font, HORIZ_DIR, t.fontSize);

            if (ui.pageID == 0)
                if (i == 0) setcolor(CYAN), setbkcolor(BLACK);
                else setcolor(WHITE), setbkcolor(BOX_COLOR_MAIN);
            else if (ui.pageID == 1)
                if (i == 0) setcolor(LIGHTBLUE), setbkcolor(BLACK);
                else setcolor(WHITE), setbkcolor(BLACK);
            else if (ui.pageID == 3) {
                setcolor(WHITE);
                setbkcolor(BOX_COLOR_MAIN);
            } else {
                setcolor(WHITE);
                setbkcolor(BLACK);
            }

            outtextxy(t.x, t.y, t.t);
        }

        if (ui.pageID == 3) {
            settextjustify(CENTER_TEXT, CENTER_TEXT);
            setbkcolor(BOX_COLOR_MAIN);
            setcolor(WHITE);
            settextstyle(DEFAULT_FONT, HORIZ_DIR, 5);
            outtextxy(200, 530, (char *) "8X8");
            outtextxy(600, 530, (char *) "6X6");
            outtextxy(1000, 530, (char *) "4X4");
        }

        for (int i = 0; i < p.nbSelectableZones; i++) {
            const selectableZone &sz = p.sl[i];
            for (int j = 0; j < sz.n; j++) {
                const selectableButton &sb = sz.bl[j];

                if (sb.selected) {
                    int midx = sb.b.x1 + (sb.b.x2 - sb.b.x1) / 2;
                    int midy = sb.b.y1 + (sb.b.y2 - sb.b.y1) / 2;

                    setcolor(BUTTON_COLOR_SECOND);
                    setfillstyle(SOLID_FILL, BUTTON_COLOR_SECOND);
                    bar(sb.b.x1 - OFFSET, sb.b.y1 - OFFSET, sb.b.x2 + OFFSET, sb.b.y2 + OFFSET);

                    setfillstyle(SOLID_FILL, LIGHTBLUE);
                    setcolor(LIGHTBLUE);
                    bar(sb.b.x1, sb.b.y1, sb.b.x2, sb.b.y2);

                    setbkcolor(LIGHTBLUE);
                    setcolor(BUTTON_COLOR_TEXT);
                    settextjustify(CENTER_TEXT, CENTER_TEXT);
                    settextstyle(sb.b.t.font, HORIZ_DIR, sb.b.t.fontSize);
                    outtextxy(midx, midy, sb.b.t.t);

                    setbkcolor(BLACK);
                } else {
                    button(sb.b.x1, sb.b.y1, sb.b.x2, sb.b.y2, sb.b.t.font, sb.b.t.fontSize, sb.b.t.t);
                }
            }
        }

        for (int i = 0; i < p.nbClickableZones; i++) {
            const clickableZone &cz = p.cl[i];
            for (int j = 0; j < cz.n; j++) {
                const clickableButton &cb = cz.bl[j];
                button(cb.x1, cb.y1, cb.x2, cb.y2, cb.t.font, cb.t.fontSize, cb.t.t);
            }
        }

        for (int i = 0; i < p.nbNavigZones; i++) {
            const navigZone &nz = p.nl[i];
            for (int j = 0; j < nz.n; j++) {
                const navigButton &nb = nz.bs[j];
                button(nb.b.x1, nb.b.y1, nb.b.x2, nb.b.y2, nb.b.t.font, nb.b.t.fontSize, nb.b.t.t);
            }
        }
    }
    else {
        const selectableZone &sz = p.sl[selectableZoneID];
        for (int j = 0; j < sz.n; j++) {
            const selectableButton &sb = sz.bl[j];
            if (sb.selected) {
                int midx = sb.b.x1 + (sb.b.x2 - sb.b.x1) / 2;
                int midy = sb.b.y1 + (sb.b.y2 - sb.b.y1) / 2;
                setcolor(BUTTON_COLOR_SECOND);
                setfillstyle(SOLID_FILL, BUTTON_COLOR_SECOND);
                bar(sb.b.x1 - OFFSET, sb.b.y1 - OFFSET, sb.b.x2 + OFFSET, sb.b.y2 + OFFSET);
                setfillstyle(SOLID_FILL, LIGHTBLUE);
                setcolor(LIGHTBLUE);
                bar(sb.b.x1, sb.b.y1, sb.b.x2, sb.b.y2);
                setbkcolor(LIGHTBLUE);
                setcolor(BUTTON_COLOR_TEXT);
                settextjustify(CENTER_TEXT, CENTER_TEXT);
                settextstyle(sb.b.t.font, HORIZ_DIR, sb.b.t.fontSize);
                outtextxy(midx, midy, sb.b.t.t);
                setbkcolor(BLACK);
            } else {
                button(sb.b.x1, sb.b.y1, sb.b.x2, sb.b.y2, sb.b.t.font, sb.b.t.fontSize, sb.b.t.t);
            }
        }
    }

    if (ui.pageID == 5) {
        if (selectableZoneID == -1) {
            setbkcolor(BLACK);
            setfillstyle(SOLID_FILL, BLACK);
            bar(0, 0, 1580, 920);
            box(250, 100, 1330, 850);
        }

        setbkcolor(BOX_COLOR_MAIN);
        setcolor(WHITE);
        settextjustify(CENTER_TEXT, CENTER_TEXT);

        char textFinale[100];
        settextstyle(DEFAULT_FONT, HORIZ_DIR, 4);
        if (game.nbP[1] > game.nbP[0]) {
            outtextxy(1580 / 2, 200, (char*)"Les gagnants sont les blancs.");
        } else if (game.nbP[0] > game.nbP[1]) {
            outtextxy(1580 / 2, 200, (char*)"Les gagnants sont les noirs.");
        } else {
            outtextxy(1580 / 2, 200, (char*)"Match nul !");
        }

        settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
        sprintf(textFinale, "Noir : pions en sa possession %d.", game.nbP[0]);
        outtextxy(1580 / 2, 400, textFinale);

        sprintf(textFinale, "Blanc : pions en sa possession %d.", game.nbP[1]);
        outtextxy(1580 / 2, 550, textFinale);

        for (int i = 0; i < p.nbNavigZones; i++) {
            for (int j = 0; j < p.nl[i].n; j++) {
                button(p.nl[i].bs[j].b.x1, p.nl[i].bs[j].b.y1, p.nl[i].bs[j].b.x2, p.nl[i].bs[j].b.y2, p.nl[i].bs[j].b.t.font, p.nl[i].bs[j].b.t.fontSize, p.nl[i].bs[j].b.t.t);
            }
        }
        setcolor(WHITE);
        setbkcolor(BLACK);
        initGame(game);
    }
    else if (ui.pageID == 4) {
        int BOARD_X1, BOARD_Y1, BOARD_X2, BOARD_Y2;
        coordonneePlateau(game.n, BOARD_X1, BOARD_Y1, BOARD_X2, BOARD_Y2);

        if (selectableZoneID == -1) {
            setbkcolor(BLACK);
            setfillstyle(SOLID_FILL, BLACK);
            bar(0, 0, 1580, 920);
        }

        setfillstyle(SOLID_FILL, BLACK);
        bar(600, 0, 1000, 60);
        bar(600, 850, 1000, 920);

        char scoreTexte[50];
        settextjustify(CENTER_TEXT, CENTER_TEXT);
        settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
        setbkcolor(BLACK);

        setcolor(game.currentPlayer == 0 ? CYAN : WHITE);
        sprintf(scoreTexte, "Joueur 1 : %d pions.", game.nbP[0]);
        outtextxy(1580 / 2, 50, scoreTexte);

        setcolor(game.currentPlayer == 1 ? CYAN : WHITE);
        if(game.bot) sprintf(scoreTexte, "Ordinateur : %d pions.", game.nbP[1]);
        else sprintf(scoreTexte, "Joueur 2 : %d pions.", game.nbP[1]);
        outtextxy(1580 / 2, 870, scoreTexte);
        //message
        int box_x1 = 10, box_y1 = 350, box_x2 = 450, box_y2 = 550;
        setcolor(WHITE);
        setfillstyle(SOLID_FILL, BOX_COLOR_MAIN);
        bar(box_x1, box_y1, box_x2, box_y2);
        rectangle(box_x1, box_y1, box_x2, box_y2);

        setbkcolor(BOX_COLOR_MAIN);
        setcolor(statutColor);
        settextjustify(CENTER_TEXT, CENTER_TEXT);
        settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
        outtextxy((box_x1 + box_x2) / 2, (box_y1 + box_y2) / 2, statutTexte);
        setcolor(WHITE);
        setbkcolor(BLACK);

        for (int i = 0; i < p.nbNavigZones; i++) {
            for (int j = 0; j < p.nl[i].n; j++) {
                button(p.nl[i].bs[j].b.x1, p.nl[i].bs[j].b.y1, p.nl[i].bs[j].b.x2, p.nl[i].bs[j].b.y2, p.nl[i].bs[j].b.t.font, p.nl[i].bs[j].b.t.fontSize, p.nl[i].bs[j].b.t.t);
            }
        }
        setcolor(WHITE);

        if (popupActive != 0) {
            int pop_x1 = 1150, pop_y1 = 350, pop_x2 = 1500, pop_y2 = 550;
            setcolor(WHITE);
            setfillstyle(SOLID_FILL, BOX_COLOR_MAIN);
            bar(pop_x1, pop_y1, pop_x2, pop_y2);
            rectangle(pop_x1, pop_y1, pop_x2, pop_y2);

            setbkcolor(BOX_COLOR_MAIN);
            setcolor(WHITE);
            settextjustify(CENTER_TEXT, CENTER_TEXT);
            settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);

            if (popupActive == 1) outtextxy((pop_x1 + pop_x2) / 2, pop_y1 + 50, (char*)"Reinitialiser ?");
            else if (popupActive == 2) outtextxy((pop_x1 + pop_x2) / 2, pop_y1 + 50, (char*)"Aller a l'accueil ?");

            button(pop_x1 + 30, pop_y2 - 80, pop_x1 + 130, pop_y2 - 30, DEFAULT_FONT, 2, "Oui");
            button(pop_x2 - 130, pop_y2 - 80, pop_x2 - 30, pop_y2 - 30, DEFAULT_FONT, 2, "Non");
            setbkcolor(BLACK);
        }

        // Clean UI drawing context
        if (popupActive == 0) {
            if (selectableZoneID == -1) {
                if (game.posInit == 0) firstPositionBoard(BOARD_X1, BOARD_Y1, BOARD_X2, BOARD_Y2, game.n);
                else secondPositionBoard(BOARD_X1, BOARD_Y1, BOARD_X2, BOARD_Y2, game.n);

                if (game.help && (!game.bot || game.currentPlayer == game.color)) {
                    showLegalMoves(game);
                }
            }
            else if ( game.help && (!game.bot || game.currentPlayer == game.color)) {
                showLegalMoves(game);
            }
        }
    }
}

bool unCLic(UI &ui, int x, int y, gameState &game, int& ID) {
    page &p = ui.pl[ui.pageID];

    if(ui.pageID != 4) {
        for (int i = 0; i < p.nbNavigZones; i++) {
            const navigZone &nz = p.nl[i];
            for (int j = 0; j < nz.n; j++) {
                const navigButton &nb = nz.bs[j];
                if (x >= nb.b.x1 && x <= nb.b.x2 && y >= nb.b.y1 && y <= nb.b.y2) {
                    ui.pageID = nb.toPage;
                    if(nb.b.id == 104) {
                        game.bot = true;
                        if(ui.pl[0].sl[0].bl[0].selected) game.color = 0; // Human is Black
                        else game.color = 1;                             // Human is White
                    }
                    if (nb.toPage == 4) {
                        initGame(game);
                        calculateLegalMoves(game);
                        strcpy(statutTexte, "Les noirs commencent.");
                        statutColor = YELLOW;

                        // BOT CASCADE ON START: If Bot is black (game.color == 1), it takes the first move immediately
                        while (game.bot && game.currentPlayer != game.color && ui.pageID == 4) {
                            int b_row, b_col, b_legalID;
                            botLogic(game, game.difficulty, b_row, b_col);
                            if (playMove(game, b_row, b_col, b_legalID)) {
                                playLegalInterface(game, b_legalID);
                                calculateLegalMoves(game);

                                if (game.ec.n == 0 || isGameOver(game)) {
                                    ui.pageID = 5;
                                    ID = -1;
                                    break;
                                }
                                if (game.legal.n == 0) {
                                    game.currentPlayer = !game.currentPlayer; // Return turn to human
                                    calculateLegalMoves(game);
                                    if (game.legal.n == 0 || isGameOver(game)) {
                                        ui.pageID = 5;
                                        ID = -1;
                                        break;
                                    } else {
                                        strcpy(statutTexte, game.currentPlayer == 1 ? "Tour impossible (Noirs)." : "Tour impossible (Blancs).");
                                        statutColor = RED;
                                    }
                                } else {
                                    strcpy(statutTexte, game.currentPlayer == 0 ? "Au tour des noirs." : "Au tour des blancs.");
                                    statutColor = YELLOW;
                                }
                            } else {
                                break;
                            }
                        }
                    }
                    ID = -1;
                    return true;
                }
            }
        }
        for (int i = 0; i < p.nbSelectableZones; i++) {
            selectableZone &sz = p.sl[i];
            for (int j = 0; j < sz.n; j++) {
                selectableButton &sb = sz.bl[j];
                if (x >= sb.b.x1 && x <= sb.b.x2 && y >= sb.b.y1 && y <= sb.b.y2) {
                    if (!sb.selected) {
                        for (int k = 0; k < sz.n; k++) {
                            sz.bl[k].selected = false;
                        }
                        sb.selected = true;

                        if (strcmp(sb.b.t.t, "6x6") == 0 || sb.b.id == 6) {
                            game.n = 6;
                        } else if (strcmp(sb.b.t.t, "8x8") == 0 || sb.b.id == 8) {
                            game.n = 8;
                        } else if (strcmp(sb.b.t.t, "4x4") == 0 || sb.b.id == 4) {
                            game.n = 4;
                        }
                        if (sb.b.id == 301) game.posInit = 0;
                        else if (sb.b.id == 302) game.posInit = 1;
                        if (sb.b.id == 303) game.help = true;
                        else if (sb.b.id == 304) game.help = false;
                    }
                    ID = i;
                    return true;
                }
            }
        }
    }
    else { // Gameplay Page 4
        if (popupActive != 0) {
            int pop_x1 = 1220, pop_y1 = 350, pop_x2 = 1570, pop_y2 = 550;

            if (x >= pop_x1 + 30 && x <= pop_x1 + 130 && y >= pop_y2 - 80 && y <= pop_y2 - 30) {
                if (popupActive == 1) { // Resetting Match
                    initGame(game);
                    calculateLegalMoves(game);
                    strcpy(statutTexte, "Les noirs commencent.");
                    statutColor = YELLOW;

                    // BOT CASCADE ON RESET
                    while (game.bot && game.currentPlayer != game.color && ui.pageID == 4) {
                        int b_row, b_col, b_legalID;
                        botLogic(game, game.difficulty, b_row, b_col);
                        if (playMove(game, b_row, b_col, b_legalID)) {
                            playLegalInterface(game, b_legalID);
                            calculateLegalMoves(game);
                            if (game.ec.n == 0 || isGameOver(game)) {
                                ui.pageID = 5;
                                ID = -1;
                                break;
                            }
                            if (game.legal.n == 0) {
                                game.currentPlayer = !game.currentPlayer;
                                calculateLegalMoves(game);
                                if (game.legal.n == 0 || isGameOver(game)) {
                                    ui.pageID = 5;
                                    ID = -1;
                                    break;
                                } else {
                                    strcpy(statutTexte, game.currentPlayer == 1 ? "Tour impossible (Noirs)." : "Tour impossible (Blancs).");
                                    statutColor = RED;
                                }
                            } else {
                                strcpy(statutTexte, game.currentPlayer == 0 ? "Au tour des noirs." : "Au tour des blancs.");
                                statutColor = YELLOW;
                            }
                        } else {
                            break;
                        }
                    }
                }
                else if (popupActive == 2) {
                    ui.pageID = 0;
                }
                popupActive = 0;
                ID = -1;
                return true;
            }
            else if (x >= pop_x2 - 130 && x <= pop_x2 - 30 && y >= pop_y2 - 80 && y <= pop_y2 - 30) {
                popupActive = 0;
                ID = 1;
                return true;
            }
            return false;
        }

        for (int i = 0; i < p.nbNavigZones; i++) {
            for (int j = 0; j < p.nl[i].n; j++) {
                const navigButton &nb = p.nl[i].bs[j];
                if (x >= nb.b.x1 && x <= nb.b.x2 && y >= nb.b.y1 && y <= nb.b.y2) {
                    if (nb.b.id == 401) popupActive = 1;
                    if (nb.b.id == 402) popupActive = 2;
                    ID = 1;
                    return true;
                }
            }
        }

        int row, col, legalID;
        if (verifyClick(game, x, y, row, col)) {
            // Human Turn Execution Block
            if (!game.bot || (game.bot && game.currentPlayer == game.color)) {
                if (playMove(game, row, col, legalID)) {
                    playLegalInterface(game, legalID);
                    calculateLegalMoves(game);

                    if (game.ec.n == 0 || isGameOver(game)) {
                        ui.pageID = 5;
                        ID = -1;
                        return true;
                    }

                    if (game.legal.n == 0) { // Next player has no moves
                        game.currentPlayer = !game.currentPlayer; // Pass back turn
                        calculateLegalMoves(game);

                        if (game.legal.n == 0 || isGameOver(game)) {
                            ui.pageID = 5;
                            ID = -1;
                            return true;
                        } else {

                            strcpy(statutTexte, game.currentPlayer == 1 ? "Tour impossible pour les noirs." : "Tour impossible pour les blancs.");
                            statutColor = RED;
                        }
                    } else {
                        strcpy(statutTexte, game.currentPlayer == 0 ? "Au tour des noirs." : "Au tour des blancs.");
                        statutColor = YELLOW;
                    }

                    // BOT CASCADE ON SUCCESSFUL HUMAN MOVE
                    while (game.bot && game.currentPlayer != game.color && ui.pageID == 4) {
                        int b_row, b_col, b_legalID;
                        botLogic(game, game.difficulty, b_row, b_col);
                        if (playMove(game, b_row, b_col, b_legalID)) {
                            playLegalInterface(game, b_legalID);
                            calculateLegalMoves(game);

                            if (game.ec.n == 0 || isGameOver(game)) {
                                ui.pageID = 5;
                                ID = -1;
                                break;
                            }

                            if (game.legal.n == 0) { // Human has no moves, Bot retains turn!
                                game.currentPlayer = !game.currentPlayer;
                                calculateLegalMoves(game);

                                if (game.legal.n == 0 || isGameOver(game)) {
                                    ui.pageID = 5;
                                    ID = -1;
                                    break;
                                } else {
                                    strcpy(statutTexte, game.currentPlayer == 1 ? "Tour impossible pour les noirs." : "Tour impossible pour les blancs.");
                                    statutColor = RED;
                                    ID = 1;
                                }
                            } else {
                                strcpy(statutTexte, game.currentPlayer == 0 ? "Au tour des noirs." : "Au tour des blancs.");
                                statutColor = YELLOW;
                                ID = 1;
                            }
                        } else {
                            break;
                        }
                    }
                    return true;
                }
                else {
                    strcpy(statutTexte, "Coup impossible.");
                    statutColor = RED;
                    ID = 1;
                    return false;
                }
            }
        }
    }
    return false;
}