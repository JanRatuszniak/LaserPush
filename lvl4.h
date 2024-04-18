
#ifndef MAIN_CPP_LVL4_H
#define MAIN_CPP_LVL4_H
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "Board.h"
#include <array>
#include <vector>
#include "windows.h"


class lvl4 {
    Board &board;
public:

    explicit lvl4(Board &b);

    void rendermap();

};



#endif //MAIN_CPP_LVL3_H
