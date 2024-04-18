#include "Board.h"
#include "lvl1.h"

lvl1::lvl1(Board &b) : board(b) {
rendermap();
}


void lvl1::welcomeMap() {
    int height=board.getBoardHeight();
    int width =board.getBoardWidth();

    for (int wiersz = 0; wiersz < height; wiersz++) {       //ustawienie ramki ścian
        for (int kolumna = 0; kolumna < width; kolumna++) {
            board.change(wiersz, kolumna, 2);

            }
        }
///ustawienie napisu

for(int i=0;i<5;i++){

    board.change(i+3, 1, 0);
    board.change(i+3, 4, 0);
    board.change(i+3, 6, 0);
    board.change(i+3, 12, 0);
    board.change(i+3, 13, 0);
    board.change(i+3, 15, 0);
    board.change(i+3, 17, 0);

    board.change(i+10, 4, 0);
    board.change(i+10, 8, 0);
    board.change(i+10, 10, 0);
    board.change(i+10, 16, 0);
    board.change(i+10, 18, 0);


}
   //   board.change(, , );
    board.change(7, 2, 0);
    board.change(3,4 , 2);
    board.change(3, 6, 2);
    board.change(3, 5, 0);
    board.change(5, 5, 0);
    board.change(3, 9, 0);
    board.change(3, 10, 0);
    board.change(4, 8, 0);
    board.change(5, 9, 0);
    board.change(6, 10, 0);
    board.change(7, 8, 0);
    board.change(7, 9, 0);
    board.change(4, 13,2);
    board.change(6, 13, 2);
    board.change(3, 16, 0);
    board.change(5, 16, 0);
    board.change(3, 17, 2);
    board.change(5, 17, 2);


    board.change(10, 5, 0);
    board.change(12, 5, 0);
    board.change(11, 6, 0);
    board.change(14, 8, 2);
    board.change(14, 10, 2);
    board.change(14, 9, 0);

    board.change(10, 13, 0);
    board.change(10, 14, 0);
    board.change(11, 12, 0);
    board.change(12, 13, 0);
    board.change(13, 14, 0);
    board.change(14, 13, 0);
    board.change(14, 12, 0);
    board.change(12, 17, 0);







}

void lvl1::rendermap() {
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

   for(int i=0; i<16;i++) {
       board.change(i, 4, 0);
   }

    for(int i=0; i<13;i++) {
        board.change(i, 14, 0);
    }

    for(int i=12; i<20;i++) {
        board.change(9, i, 0);
        board.change(13, i, 0);

    }



    board.change(7, 5, 0);
    board.change(7, 6, 0);
    board.change(7, 12, 0);
    board.change(7, 13, 0);
    board.change(9, 5, 0);
    board.change(9, 6, 0);
    board.change(14, 12, 0);
    board.change(4, 2, 0);
////ustawienie blokad i wyjścia
    board.change(11, 4, 8);

    board.change(11, 14, 10);



    //ustawienie odbiorników lasera
    board.change(8, 5, 6);
    board.change(8, 13, 16);


    //postać
    board.change(8, 9, 4);

    //lasery

    board.change(3, 2, 23);
    board.change(5, 12, 25);
    board.change(5, 8, 5);
    board.change(5, 10, 24);


    //wyjście
    board.change(11, 18, 26);
}
