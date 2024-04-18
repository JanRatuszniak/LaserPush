
#ifndef BOARD_H_LASER2_H
#define BOARD_H_LASER2_H

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "Board.h"
#include <array>
#include <vector>
#include "windows.h"
using namespace std;
#include <vector>

class LaserEngine {
    Board &board;
public:
    explicit LaserEngine(Board &b);

    void lasery();

    bool gowno=false;

    vector<int> gatesA;
    vector<int> gatesB;
    vector<int> gatesC;
    vector<int> gatesD;

//
//    vector<int> reciversA;
//    vector<int> reciversB;
//    vector<int> reciversC;
//    vector<int> reciversD;


    bool gatesFlag=false;
    int zmiennaOdIlosciBlokad{};

};


#endif //BOARD_H_LASER2_H
