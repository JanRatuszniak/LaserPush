#include "Board.h"
#include "lvl5.h"

lvl5::lvl5(Board &b) : board(b) {
    rendermap();
}

void lvl5::rendermap() {
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

    for(int i = 0; i<10;i++){
        board.change(3, i, 0);
        board.change(7, i, 0);
    }

    for(int i = 0; i<5;i++){
        board.change(13, i+14, 0);
        board.change(14, i+14, 0);
        board.change(i+3, 9, 0);

    }
for(int i=0;i<4;i++) {
    board.change(11, i+15, 0);
}
    board.change(12, 18, 0);

//ustawienie blokad i wyjścia
    board.change(3, 7, 8);
    board.change(7, 4, 8);
    board.change(12, 15, 8);
    board.change(12, 16, 10);



    //ustawienie odbiorników lasera
    board.change(5, 9, 6);
    board.change(2, 16, 16);

    //postać
    board.change(5, 2, 4);

    //lasery

    board.change(1, 7, 5);
    board.change(5, 4, 23);
    board.change(11, 5, 24);
    board.change(5, 14, 25);
//wyjście
    board.change(12, 17, 26);

//skrzynie

for(int i=0;i<3;i++) {
    board.change(i+4, 6, 27);
}
    board.change(5, 10, 27);

}
