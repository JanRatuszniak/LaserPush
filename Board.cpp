#include <cstdlib>
#include <ctime>
#include <chrono>
#include "Board.h"
#include <iostream>

using namespace std;


Board::Board(int height, int width) {
    this->width = width;
    this->height = height;

    srand(time(NULL));
    for (int wiersz = 0; wiersz < height; wiersz++) {
        for (int kolumna = 0; kolumna < width; kolumna++) {
            board[wiersz][kolumna].pole = 2;

        }
    }

}


void Board::move(char z) {
    int x, y, a, b;
    int wierszT, kolumnaT;
    for (int wiersz = 0; wiersz < height; wiersz++) {
        for (int kolumna = 0; kolumna < width; kolumna++) {
            if (board[wiersz][kolumna].pole == 4) {
                wierszT = wiersz;
                kolumnaT = kolumna;
            }
        }
    }

    if (z == 'w') {
        x = wierszT - 1;
        y = kolumnaT;
        a = wierszT - 2;
        b = kolumnaT;
    }        //x,y-o jedno pole w dal, a,b-o dwa pola w dal
    if (z == 'a') {
        x = wierszT;
        y = kolumnaT - 1;
        a = wierszT;
        b = kolumnaT - 2;
    }
    if (z == 's') {
        x = wierszT + 1;
        y = kolumnaT;
        a = wierszT + 2;
        b = kolumnaT;
    }
    if (z == 'd') {
        x = wierszT;        //x,y-jedno pole w przód,
        y = kolumnaT + 1;
        a = wierszT;        // a,b-dwa pola w przód
        b = kolumnaT + 2;
    }
    if (board[x][y].pole ==
        26) { win(); }      //następny ruch: wygrana                                                                  //kiedy następny: ruch wygrany
    else if (board[x][y].pole == 0) {           //              ściana
    } else if ((board[x][y].pole == 5 || board[x][y].pole == 23 || board[x][y].pole == 24 ||
                // następny ruch przesuwa rzutnik lasera
                board[x][y].pole == 25||board[x][y].pole == 27) &&
               (board[a][b].pole == 2 || board[a][b].pole == 1
                || board[a][b].pole == 3 || board[a][b].pole == 22 || board[a][b].pole == 9 ||
                board[a][b].pole == 11 || board[a][b].pole == 13 || board[a][b].pole == 15)) {
        int q = board[x][y].pole;
        board[x][y].pole = 4;
        board[wierszT][kolumnaT].pole = 2;
        board[a][b].pole = q;
    } else if (board[x][y].pole == 2 || board[x][y].pole == 1 ||//zwolniona blokada lub laser
               board[x][y].pole == 3
               || board[x][y].pole == 9 || board[x][y].pole == 11 || board[x][y].pole == 22 ||
               board[x][y].pole == 13 || board[x][y].pole == 15) {
        board[x][y].pole = 4;
        board[wierszT][kolumnaT].pole = 2;
    }


}

void Board::win() {
    std::cout << "wygrana\n";
    int x = lvl;
    lvl = x + 1;
    previousLvl=x;
    std::cout << lvl << "\n";
    for (int wiersz = 0; wiersz < height; wiersz++) {
        for (int kolumna = 0; kolumna < width; kolumna++) {
            board[wiersz][kolumna].pole = 2;

        }
    }

}


int Board::getFieldInfo(int wiersz, int kolumna) const {

    if (board[wiersz][kolumna].pole == 0)
        return 0;     //ściana

    if (board[wiersz][kolumna].pole == 3)
        return 3;         //laser pionowo

    if (board[wiersz][kolumna].pole == 2)
        return 2;         //pole

    if (board[wiersz][kolumna].pole == 1)
        return 1;           //laser poziomo

    if (board[wiersz][kolumna].pole == 4)
        return 4;           //postac
    if (board[wiersz][kolumna].pole == 5)
        return 5;           //laser1

    if (board[wiersz][kolumna].pole == 6)
        return 6;           //A reciver
    if (board[wiersz][kolumna].pole == 7)
        return 7;           //A reciver hit
    if (board[wiersz][kolumna].pole == 8)
        return 8;           //A block ON
    if (board[wiersz][kolumna].pole == 9)
        return 9;           //A block OFF

    if (board[wiersz][kolumna].pole == 10)
        return 10;           //B block ON

    if (board[wiersz][kolumna].pole == 11)
        return 11;           //B block OFF

    if (board[wiersz][kolumna].pole == 12)
        return 12;           //C block ON

    if (board[wiersz][kolumna].pole == 13)
        return 13;           //C block OFF

    if (board[wiersz][kolumna].pole == 14)
        return 14;           //D block ON

    if (board[wiersz][kolumna].pole == 15)
        return 15;           //D block OFF

    if (board[wiersz][kolumna].pole == 16)
        return 16;           //B reciver

    if (board[wiersz][kolumna].pole == 17)
        return 17;           //B reciver hit

    if (board[wiersz][kolumna].pole == 18)
        return 18;           //C reciver

    if (board[wiersz][kolumna].pole == 19)
        return 19;           //C reciver hit

    if (board[wiersz][kolumna].pole == 20)
        return 20;           //D reciver
    if (board[wiersz][kolumna].pole == 21)
        return 21;           //D reciver hit
    if (board[wiersz][kolumna].pole == 22)
        return 22;           //skrzyżowanie laserów
    if (board[wiersz][kolumna].pole == 23)
        return 23;           //laser2
    if (board[wiersz][kolumna].pole == 24)
        return 24;           //laser3
    if (board[wiersz][kolumna].pole == 25)
        return 25;           //laser4
    if (board[wiersz][kolumna].pole == 26)
        return 26;           //wyjscie
    if (board[wiersz][kolumna].pole == 27)
        return 27;           //skrzynia
}


int Board::getBoardWidth() const {
    return width;
}

int Board::getBoardHeight() const {
    return height;
}

void Board::change(int x, int y, int q) {
    board[x][y].pole = q;

}


