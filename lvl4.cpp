#include "Board.h"
#include "lvl4.h"

lvl4::lvl4(Board &b) : board(b) {
    rendermap();
}

void lvl4::rendermap() {
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

for(int i=0;i<7;i++){
    board.change(i+8, 1, 0);
    board.change(i+8, 3, 0);

}



//ustawienie blokad
    board.change(13, 2, 14);
    board.change(12, 2, 12);
    board.change(11, 2, 10);
    board.change(10, 2, 8);





    //ustawienie odbiorników lasera
    board.change(6, 13, 6);
    board.change(6, 15, 16);
    board.change(8, 13, 18);
    board.change(8, 15, 20);

    //postać
    board.change(4, 5, 4);

    //lasery

    board.change(2, 3, 23);
    board.change(2, 7, 5);
    board.change(6, 3, 24);
    board.change(6, 7, 25);

    //skrzynie

    for(int i=0;i<3;i++) {
        board.change(i+6, 12, 27);
        board.change(i+6, 16, 27);
        board.change(5, i+13, 27);
        board.change(9, i+13, 27);
    }
//wyjscie
    board.change(14, 2, 26);
}
