#include "interface.h"

using namespace std;




int main() {
    opengraphsize(1580, 920);

    UI monUI;
    gameState monJeu;
    bool reDraw = true;
    mesPages(monUI);
    monUI.pageID = 0;
    int ID = -1;
    int page_courante = 0;
    monJeu.isGameOver = false;
    bool hasLegal = true;
    while (monUI.pageID != -1 && !monJeu.isGameOver) {
        // 1. On dit à l'ordinateur de dessiner sur la page INVISIBLE (en arrière-plan)
        if(reDraw) {
            //setactivepage(1 - page_courante); for optimization of drawing when clinking on selectable button
            if(ID == -1)
                cleardevice();
            dessinPage(monUI, monJeu,ID,hasLegal);

            // 4. On switch ! La page qu'on vient de terminer devient VISIBLE d'un coup sec
            setvisualpage(1 - page_courante);

            // 5. On change l'index de page pour le prochain tour de boucle
            page_courante = 1 - page_courante;
        }
        reDraw = false;
        if(monJeu.bot && hasLegal ) {
            if (buttonhit()) {
                int x, y;
                getmouse(x, y);
                if (unCLic(monUI, x, y, monJeu, ID))
                    reDraw = true;
            }
        }
        else if ( monJeu.bot && !hasLegal )
        {
            monJeu.isGameOver = isGameOver(monJeu);
            reDraw = true;
        }
        else if (!monJeu.bot)
        {
            if (buttonhit()) {
                int x, y;
                getmouse(x, y);
                if (unCLic(monUI, x, y, monJeu, ID))
                    reDraw = true;
            }
        }


        delay(20);
    }


    closegraph();
    return 0;
}