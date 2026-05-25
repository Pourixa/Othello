#include "funcs.h"
<<<<<<< HEAD
#include "interface.h"
=======
#include <random>

>>>>>>> 66e0b7c50c9be66831b5ca9d09dcaf2d0e8ee73f
using namespace std;


bool test_initGame() {

    /* there was a problem with center initializations
     * since the center is hardcoded the logic for showing the board
     * breaks so we must initialize the center dynamically
     * there was also no need for gameover variable so we removed it
     */
    gameState gs;
    initGame(gs, 8, 0);
    bool flag = gs.n == 8;
    flag = flag && gs.b[3][3].color == 1;
    flag = flag && gs.b[3][4].color == 0;
    flag = flag && gs.b[4][3].color == 0;
    flag = flag && gs.b[4][4].color == 1;
    flag = flag && gs.ec.n == 12;
    int i = 0;
    int row, col;
    while (flag && i < gs.ec.n) {
        row = gs.ec.ec[i].row;
        col = gs.ec.ec[i].col;
        flag = flag && gs.b[row][col].color == -1;
        flag = flag && gs.b[row][col].id == i;
        i++;
    }
    flag = flag && gs.nbP[0] == 2;
    flag = flag && gs.nbP[1] == 2;
    flag = flag && gs.currentPlayer == 0;
    cout<<"DIFF 4X4 : " << gs.diffs[0]<<" DIFF 6X6 : "  <<gs.diffs[1]<<" DIFF 8X8 : "   << gs.diffs[2]<<endl;
    if (flag) {
        cout << "test_initGame passed! " << endl;
        return true;
    }
    cout << "test_initGame failed!" << endl;
    return false;
}

bool test_checkCell() {
    gameState gs;
    initGame(gs, 8, 0);
    bool flag = checkCell(gs, 3, 3, 1);
    flag = flag && checkCell(gs, 3, 4, 0);
    flag = flag && checkCell(gs, 0, 0, -1);

    if (flag) {
        cout << "test_checkCell passed! " << endl;
        return true;
    }
    cout << "test_checkCell failed!" << endl;
    return false;
}

bool test_isEmptyCellLegalOneDirection() {
    /* there was a logical bug in this function this function
     * reutruned true when the neighboour pion was the same
     * color as current player event tough there was no pions and
     * it didn't change anything but in the end it retruned true
     * so added an counter to prevent that*/
    gameState gs;
    initGame(gs, 4, 0);
    legalMove lm;
    lm.flipCount = 0;
    bool flag = isEmptyCellLegalOneDirection(gs, lm, gs.ec.ec[gs.b[0][1].id], 1, 0);
    flag = flag &&
           isEmptyCellLegalOneDirection(gs, lm, gs.ec.ec[gs.b[0][0].id], 1, 1) == false &&
           lm.flipCount == 1;
    if (flag) {
        cout << "test_isEmptyCellLegalOneDirection passed! " << endl;
        return true;
    }
    cout << "test_isEmptyCellLegalOneDirection failed!" << endl;
    return false;
}

bool test_isEmptyCellLegal() {
    gameState gs;
    initGame(gs, 8, 0);
    legalMove lm;
    lm.flipCount = 0;
    bool flag = isEmptyCellLegal(gs, lm, gs.ec.ec[gs.b[2][3].id]);
    flag = flag &&
           isEmptyCellLegal(gs, lm, gs.ec.ec[gs.b[2][2].id]) == false;
    if (flag) {
        cout << "test_isEmptyCellLegal passed! " << endl;
        return true;
    }
    cout << "test_isEmptyCellLegal failed!" << endl;
    return false;
}

bool test_calculateLegalMoves() {
    /* there was problem with this function since
     * I have put return for the functions
     * the first  true or will return and the rest
     * of the functions will not run so I used a
     * bool variable and used or between function
     * first then the flag then I returned the flag value*/

    gameState gs;
    initGame(gs, 8, 0);
    bool flag = true;
    calculateLegalMoves(gs);
    flag = flag && gs.legal.n == 4;
    flag = flag && gs.legal.legals[0].row == 2 && gs.legal.legals[0].col == 3;
    flag = flag && gs.legal.legals[1].row == 5 && gs.legal.legals[1].col == 4;
    flag = flag && gs.legal.legals[1].flipCount == 1;
    if (flag) {
        cout << "test_calculateLegalMoves passed! " << endl;
        return true;
    }
    cout << "test_calculateLegalMoves failed!" << endl;
    return false;
}

bool test_isClickLegal() {
    gameState gs;
    initGame(gs, 8, 0);
    int id;

    bool flag = isClickLegal(gs, 5, 4, id);
    flag = id == 1 && flag;
    flag = gs.legal.legals[id].row == 5 && gs.legal.legals[id].col == 4 && flag;
    if (flag) {
        cout << "test_calculateLegalMoves passed! " << endl;
        return true;
    }
    cout << "test_calculateLegalMoves failed!" << endl;
    return false;
}

bool test_playLegal() {
    /* there was a problem with updating the number of pions
     * we added one less cause we didn't add the pion that was placed
      so we write flipcount + 1
      */
    gameState gs;
    initGame(gs, 8, 0);
    calculateLegalMoves(gs);
    playLegal(gs, 1);
    int row = gs.legal.legals[1].row, col = gs.legal.legals[1].col;
    bool flag = gs.b[row][col].color == false &&
                gs.b[row][col].id == -1;
    flag = flag && gs.ec.n == 11;
    flag = flag && gs.b[row - 1][col].color == false;
    flag = flag && gs.b[row - 2][col].color == false;
    flag = flag && gs.nbP[false] == 4;
    flag = flag && gs.currentPlayer == true;

    if (flag) {
        cout << "test_playLegal passed! " << endl;
        return true;
    }
    cout << "test_playLegal failed!" << endl;
    return false;
}

bool test_addEmptyCellAllDirections() {
    gameState gs;
    initGame(gs, 8, 0);
    addEmptyCellAllDirections(gs, 5, 4);
    bool flag = gs.b[6][5].id == 12;
    flag = flag && gs.b[6][4].id == 13;
    flag = flag && gs.ec.n == 15;
    if (flag) {
        cout << "test_addEmptyCellAllDirections passed! " << endl;
        return true;
    }
    cout << "test_addEmptyCellAllDirections failed!" << endl;
    return false;
}

void globalTest() {
    bool flag =
            (test_initGame() &&
             test_checkCell() &&
             test_isEmptyCellLegalOneDirection() &&
             test_isEmptyCellLegal() &&
             test_calculateLegalMoves() &&
             test_isClickLegal() &&
             test_playLegal() &&
             test_addEmptyCellAllDirections());
    if (flag) {
        cout << "all tests passed! " << endl;
        int a;
        cin >> a;
    }
    cout << "tests failed!" << endl;
    int a;
    cin >> a;
}


int main(){
//playConsoleGameVSPlayer();
    opengraphsize(1580, 920);

    UI monUI;
    gameState monJeu;

    mesPages(monUI);
    monUI.pageID = 0; 
    monJeu.gameOver = false;

    int page_courante = 0; 

    while (monUI.pageID != -1 && !monJeu.gameOver)
    {
        // 1. On dit à l'ordinateur de dessiner sur la page INVISIBLE (en arrière-plan)
        setactivepage(1 - page_courante);

        cleardevice();

        dessinPage(monUI, monJeu);

        // 4. On switch ! La page qu'on vient de terminer devient VISIBLE d'un coup sec
        setvisualpage(1 - page_courante);

        // 5. On change l'index de page pour le prochain tour de boucle
        page_courante = 1 - page_courante;

        if (buttonhit())
        {
            int x, y;
            getmouse(x, y);
            unCLic(monUI, x, y, monJeu);
        }

        delay(20);
    }

    closegraph();
    return 0;

int main() {
    playConsoleBotVSBot();
}