#include "funcs.h"
#include <random>

using namespace std;

const int S4_MAXDEPTH = 12;
const int S6_MAXDEPTH = 6;
const int S8_MAXDEPTH = 6;

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

void printBoard(const gameState &gs) {
    // Print column numbers
    cout << "  ";
    for (int j = 0; j < gs.n; j++)
        cout << j << " ";
    cout << endl;

    // Print board rows
    for (int i = 0; i < gs.n; i++) {
        cout << i << " "; // row number

        for (int j = 0; j < gs.n; j++) {
            if (checkCell(gs, i, j, -1))
                cout << ". ";   // empty
            else if (checkCell(gs, i, j, 0))
                cout << "B ";   // black
            else if (checkCell(gs, i, j, 1))
                cout << "W ";   // white
        }

        cout << endl;
    }

    cout << endl;
}

int evaluateState(const gameState &gs) {
    return gs.nbP[true] - gs.nbP[false];
}


int minimax(const gameState &gs, int level, int depth,int alpha ,int beta, int &row, int &col) {

    if (isGameOver(gs) || level >= depth)
        return evaluateState(gs);

    if (gs.legal.n == 0) {
        gameState gsCopy = gs;
        gsCopy.currentPlayer = !gsCopy.currentPlayer;
        calculateLegalMoves(gsCopy);

        return minimax(gsCopy, level + 1, depth,alpha,beta, row, col);
    }
    if (gs.currentPlayer) {
        int value = -1000, tValue, j=0;

        int Trow, Tcol;
        gameState gsCopy;
        int i =0;
        while(i<gs.legal.n && alpha < beta) {
            gsCopy = gs;
            Trow = gs.legal.legals[i].row;
            Tcol = gs.legal.legals[i].col;
            playMove(gsCopy, Trow, Tcol);
            calculateLegalMoves(gsCopy);
            tValue = minimax(gsCopy, level + 1, depth,alpha,beta, row, col);
            if (tValue > value) {
                j = i;
                value = tValue;
            }
            if(alpha < value)
                alpha =value;
            i++;
        }
        row = gs.legal.legals[j].row;
        col = gs.legal.legals[j].col;
        return value;
    } else {
        int value = 1000, tValue, j = 0;
        int Trow, Tcol;
        gameState gsCopy;
        int i = 0;
        while(i<gs.legal.n && beta>alpha) {
            gsCopy = gs;
            Trow = gs.legal.legals[i].row;
            Tcol = gs.legal.legals[i].col;
            playMove(gsCopy, Trow, Tcol);
            calculateLegalMoves(gsCopy);
            tValue = minimax(gsCopy, level + 1, depth,alpha,beta, row, col);
            if (tValue < value) {
                j = i;
                value = tValue;
            }
            if(beta > value)
                beta =value;
            i++;
        }
        row = gs.legal.legals[j].row;
        col = gs.legal.legals[j].col;
        return value;
    }
}

void botLogic(const gameState &gs, int difficulty, int &row, int &col) {
    if (difficulty == 0) {
        int i = rand() % gs.legal.n;
        row = gs.legal.legals[i].row;
        col = gs.legal.legals[i].col;
    } else
        cout << "value : " << minimax(gs, 0, difficulty,-1000,1000, row, col) << endl;
}

void playConsoleGameVSPlayer() {
    gameState gs;
    int input1, input2;
    cout << "entrez votre choix de la taile: ";
    cin >> input1;
    cout << "entrez votre choix de la position depart: ";
    cin >> input2;
    initGame(gs, input1, input2);
    calculateLegalMoves(gs);
    while (!isGameOver(gs)) {
        printBoard(gs);
        int row, col;
        if (gs.legal.n == 0)
            gs.currentPlayer = !gs.currentPlayer;
        else {
            if (gs.currentPlayer) {
                do {
                    cout << "entrez le choix de la ligne du blanc: ";
                    cin >> row;
                    cout << "entrez le choix de la colonne du blanc: ";
                    cin >> col;
                } while (!playMove(gs, row, col));

            } else {
                do {
                    cout << "entrez le blanc de la ligne du blanc: ";
                    cin >> row;
                    cout << "entrez le b de la colonne du blanc: ";
                    cin >> col;
                } while (!playMove(gs, row, col));
            }
        }
        calculateLegalMoves(gs);
    }
    printBoard(gs);


    if (gs.nbP[false] > gs.nbP[true])
        cout << "NOIR A GAGNE";
    else if (gs.nbP[false] < gs.nbP[true])
        cout << "BLANC A GAGNE";
    else
        cout << "PERSONNE A GAGNE";
}

void playConsoleGameVSBot() {
    gameState gs;
    int input1, input2, playerTurn;
    cout << "entrez votre choix de la taile: ";
    cin >> input1;
    cout << "entrez votre choix de la position depart: ";
    cin >> input2;
    cout << "Entrez votre coleur prefere: ";
    cin >> playerTurn;
    initGame(gs, input1, input2);
    calculateLegalMoves(gs);
    while (!isGameOver(gs)) {
        printBoard(gs);
        int row, col;
        if (gs.legal.n == 0)
            gs.currentPlayer = !gs.currentPlayer;
        else {
            if (gs.currentPlayer == playerTurn) {
                do {
                    cout << "entrez le choix de la ligne: ";
                    cin >> row;
                    cout << "entrez le choix de la colonne: ";
                    cin >> col;
                } while (!playMove(gs, row, col));
            } else {
                botLogic(gs, S6_MAXDEPTH, row, col);
                playMove(gs, row, col);
            }
        }
        calculateLegalMoves(gs);
    }
    printBoard(gs);
    if (gs.nbP[false] > gs.nbP[true])
        cout << "NOIR A GAGNE! ";
    else if (gs.nbP[false] < gs.nbP[true])
        cout << "BLANC A GAGNE! ";
    else
        cout << " EGALITE! ";


}

void playBotVSBot()
{
    gameState gs;
    int input1, input2, playerTurn;
    cout << "entrez votre choix de la taile: ";
    cin >> input1;
    cout << "entrez votre choix de la position depart: ";
    cin >> input2;
    initGame(gs, input1, input2);
    calculateLegalMoves(gs);
    while (!isGameOver(gs)) {
        printBoard(gs);
        int row, col;
        if (gs.legal.n == 0)
            gs.currentPlayer = !gs.currentPlayer;
        else {
                botLogic(gs, S8_MAXDEPTH, row, col);
                playMove(gs, row, col);
        }
        calculateLegalMoves(gs);
    }
    printBoard(gs);
    if (gs.nbP[false] > gs.nbP[true])
        cout << "NOIR A GAGNE! ";
    else if (gs.nbP[false] < gs.nbP[true])
        cout << "BLANC A GAGNE! ";
    else
        cout << " EGALITE! ";
}

int main() {
    playBotVSBot();
}