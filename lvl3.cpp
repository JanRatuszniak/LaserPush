#include "Board.h"
#include "lvl3.h"

lvl3::lvl3(Board &b) : board(b) {
    rendermap();
}

void lvl3::rendermap() {
    int height=board.getBoardHeight();
    int width =board.getBoardWidth();
    for (int wiersz = 0; wiersz < height; wiersz++) {           //zerowanie planszy
        for (int kolumna = 0; kolumna < width; kolumna++) {
            board.change(wiersz, kolumna, 2);

        }
    }
    for (int wiersz = 0; wiersz < height; wiersz++) {       //ustawienie ramki ścian
        for (int kolumna = 0; kolumna < width; kolumna++) {
            if (wiersz == 0 || wiersz == height - 1 || kolumna == 0 || kolumna == width - 1)
                board.change(wiersz, kolumna, 0);
        }
    }

    //ustawienie ścian na planszy
    board.change(2, 1, 0);
    board.change(2, 2, 0);
    board.change(2, 3, 0);
    board.change(2, 4, 0);
    board.change(2, 5, 0);
    board.change(3, 16, 0);
    board.change(3, 18, 0);

    board.change(6, 2, 0);
    board.change(6, 3, 0);
    board.change(6, 8, 0);
    board.change(6, 10, 0);
    board.change(6, 17, 0);

    board.change(7, 11, 0);
    board.change(7, 7, 0);

    board.change(8, 2, 0);
    board.change(8, 3, 0);

    board.change(9, 7, 0);
    board.change(9, 11, 0);
    board.change(9, 17, 0);
    board.change(9, 15, 0);

    board.change(10, 1, 0);
    board.change(10, 3, 0);
    board.change(10, 8, 0);
    board.change(10, 10, 0);
    board.change(10, 15, 0);

    board.change(11, 17, 0);
    board.change(12, 1, 0);
    board.change(12, 2, 0);
    board.change(12, 3, 0);
    board.change(12, 18, 0);
    board.change(12, 17, 0);
    board.change(12, 15, 0);
    board.change(12, 16, 0);

//ustawienie blokad i wyjścia
    board.change(1, 1, 26);
    board.change(1, 2, 14);
    board.change(1, 3, 12);
    board.change(1, 4, 10);
    board.change(1, 5, 8);

    board.change(7, 3, 8);
    board.change(9, 3, 12);
    board.change(11, 3, 10);

    //board.change(10, 17, 23);
    board.change(9, 18, 12);
    board.change(9, 16, 14);


    //ustawienie odbiorników lasera
    board.change(7, 8, 6);
    board.change(7, 10, 16);
    board.change(9, 8, 18);
    board.change(9, 10, 20);

    //postać
    board.change(8, 9, 4);

    //lasery

    board.change(3, 17, 5);
    board.change(10, 17, 23);
    board.change(10, 2, 24);
    board.change(7, 2, 25);

}
