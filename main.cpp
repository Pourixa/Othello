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
    monJeu.pendingBotMove = false;
    bool hasLegal = true;

    while (monUI.pageID != -1 && !monJeu.isGameOver) {

        if (reDraw) {
            if (ID == -1)
                cleardevice();
            dessinPage(monUI, monJeu, ID, hasLegal);
            setvisualpage(1 - page_courante);
            page_courante = 1 - page_courante;
        }
        reDraw = false;

        if (monUI.pageID == 4 && monJeu.pendingBotMove) {
            monJeu.pendingBotMove = false;
            runBotCascade(monUI, monJeu, ID);
            reDraw = true;
        }

        else if (monJeu.bot && !hasLegal) {
            monJeu.isGameOver = isGameOver(monJeu);
            reDraw = true;
        }
        else {
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