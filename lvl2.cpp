#include "Board.h"
#include "lvl2.h"

lvl2::lvl2(Board &b) : board(b) {
    zeruj_plansze();

}

void lvl2::zeruj_plansze() {
    int height = board.getBoardHeight();
    int width = board.getBoardWidth();

    for (int wiersz = 0; wiersz < height; wiersz++) {
        for (int kolumna = 0; kolumna < width; kolumna++) {
            board.change(wiersz, kolumna, 2);

        }
    }
    rendermap();
}

void lvl2::rendermap() {

    int height = board.getBoardHeight();
    int width = board.getBoardWidth();

    for (int wiersz = 0; wiersz < height; wiersz++) {
        for (int kolumna = 0; kolumna < width; kolumna++) {
            board.change(wiersz, kolumna, 2);
        }
    }


    for (int wiersz = 0; wiersz < height; wiersz++) {
        for (int kolumna = 0; kolumna < width; kolumna++) {
            if (wiersz == 0 || wiersz == height - 1 || kolumna == 0 || kolumna == width - 1)
                board.change(wiersz, kolumna, 0);
        }
    }


    //ustawienie ścian na planszy

    for(int i=0;i<8;i++){
        board.change(7+i, 1, 0);
    }
    board.change(1, 3, 0);
    for(int i=0;i<4;i++){
        board.change(i+9, 2, 0);
        board.change(i+4, 3, 0);
        board.change(i+11, 3, 0);
        board.change(i+11, 17, 0);


    }
    board.change(2, 3, 0);
    board.change(13, 5, 0);
    board.change(14, 5, 0);
    board.change(2, 1, 0);
    board.change(14, 18, 0);
    board.change(12, 15, 0);
    board.change(13, 15, 0);
    board.change(1, 18, 0);
    board.change(2, 18, 0);
    board.change(2, 15, 0);
    board.change(2, 16, 0);

//ustawienie blokad i wyjścia

    board.change(14, 2, 14);
    board.change(14, 3, 12);//ŻYD
    board.change(14, 4, 10);
    board.change(13, 4, 8);
    board.change(12, 16, 8);
    board.change(1, 3, 14);
    board.change(7, 2, 10);
    board.change(11, 18, 10);
    board.change(12, 18, 12);
    board.change(13, 4, 8);
    board.change(13, 18, 14);
    board.change(1, 16, 8);
    board.change(1, 17, 12);


    //ustawienie odbiorników lasera
   board.change(7, 6, 6);
    board.change(7, 8, 16);
    board.change(7, 10, 18);
    board.change(7, 12, 20);



//    //postać
    board.change(8, 9, 4);


    //lasery
    board.change(2, 17, 5);
    board.change(13, 17, 23);
    board.change(2, 2, 25);
    board.change(8, 15, 24);
    //wyjście
    board.change(13, 2, 26);
}




