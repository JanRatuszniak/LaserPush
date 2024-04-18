
#ifndef MAIN_CPP_LVL5_H
#define MAIN_CPP_LVL5_H
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "Board.h"
#include <array>
#include <vector>
#include "windows.h"


class lvl5 {
    Board &board;
public:

    explicit lvl5(Board &b);

    void rendermap();

};



#endif //MAIN_CPP_LVL3_H
