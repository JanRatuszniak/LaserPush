
#ifndef MAIN_CPP_LVL1_H
#define MAIN_CPP_LVL1_H
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "Board.h"
#include <array>
#include <vector>
#include "windows.h"


class lvl1 {
    Board &board;
public:

    explicit lvl1(Board &b);

    void rendermap();
    void welcomeMap();

};



#endif //MAIN_CPP_LVL1_H
