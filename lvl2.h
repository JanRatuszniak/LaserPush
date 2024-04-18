
#ifndef BOARD_CPP_LVL2_H
#define BOARD_CPP_LVL2_H

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "Board.h"
#include <array>
#include <vector>
#include "windows.h"

class lvl2 {
    Board &board;
public:
    explicit lvl2(Board &b);
    void zeruj_plansze();
    void rendermap();
    void start();
};



#endif //BOARD_CPP_LVL2_H
