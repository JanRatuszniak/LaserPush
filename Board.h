#ifndef Board_H_
#define Board_H_


struct Field {
    int pole;

};


class Board {
    Field board[100][100];
    int width;
    int height;

public:

    Board(int height, int width);

    int getBoardWidth() const;

    int getBoardHeight() const;

    int getFieldInfo(int row, int col) const;

    void move(char z);

    void change(int wiersz, int kolumna, int wartosc);
    int lvl = 0;
    int previousLvl=-1;

    void win();

};

#endif
