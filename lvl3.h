
#ifndef MAIN_CPP_LVL3_H
#define MAIN_CPP_LVL3_H
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "Board.h"
#include <array>
#include <vector>
#include "windows.h"


class lvl3 {
    Board &board;
public:

    explicit lvl3(Board &b);

    void rendermap();

};



#endif //MAIN_CPP_LVL3_H
