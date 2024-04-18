
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "View.h"
#include "Board.h"
#include <string>

#include "lvl1.h"
#include "lvl2.h"
#include "lvl3.h"
#include "lvl4.h"
#include "lvl5.h"

#include "LaserEngine.h"
#include <iostream>

using namespace std;

int main() {

    char znak = 'd';

    Board board(16, 20);
    View view(board);
    LaserEngine laserEngine(board);
    lvl1 lvl1(board);

    sf::RenderWindow window(sf::VideoMode(610, 600), "LaserPush");

    window.setVerticalSyncEnabled(false);
    window.setFramerateLimit(60);
    sf::Font font;
    font.loadFromFile("/Users/HP/CLionProjects/Snake_JR/Wanted M54.ttf");
    sf::Text textstart("Press any key  or  move mouse on board ", font, 25);
    textstart.setPosition(30, 30);
    window.clear(sf::Color::Blue);
    window.draw(textstart);
    window.display();


    int lastLvl=5;

    reapet:

    board.lvl=0;
    bool flagaRuchu = 0;
    bool flagaStartu = 0;
    bool flagaRenderuMapy = 0;

    while (window.isOpen()) {

        sf::Event event{};

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();


            while (flagaStartu == 0) {

                lvl1.welcomeMap();

                sf::Font font;
                font.loadFromFile("/Users/HP/CLionProjects/Snake_JR/Wanted M54.ttf");
                window.clear(sf::Color::Black);
                sf::Text textstart("Press key       -F1-  Play         -Detele-  exit       ", font, 18);
                window.draw(textstart);
                view.draw(window);
                window.display();

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1)) {
                    lvl1.rendermap();
                    flagaStartu = !flagaStartu;
                    window.clear();
                    window.display();
                    window.clear(sf::Color::Black);
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Delete)) {
                    exit(3);
                }
            }


            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                flagaRuchu = !flagaRuchu;
                znak = 'a';

            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                flagaRuchu = !flagaRuchu;
                znak = 'd';

            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                flagaRuchu = !flagaRuchu;
                znak = 'w';

            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                flagaRuchu = !flagaRuchu;
                znak = 's';

            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Delete)) {
                exit(1235);

            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F5)) {

                if(board.lvl==0){

                }else if (board.lvl == 1) {
                    board.lvl = board.lvl - 1;
                    lvl1.rendermap();
                    znak = ' ';   //pusty klawisz by pętla się dokończyła

            } else {
                    flagaRuchu = !flagaRuchu;
                    board.lvl = board.lvl - 1;
                }


            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F6)) {

                if (board.lvl==lastLvl-1){}
                else {
                    board.lvl = board.lvl + 1;
                    flagaRuchu = !flagaRuchu;
                }



            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F3)) {
                goto reapet;

            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F4)) {
                flagaRuchu = !flagaRuchu;

                if (board.lvl == 0) {
                    lvl1.rendermap();
                    znak = ' ';   //pusty klawisz by pętla się dokończyła
                } else {
                    flagaRenderuMapy = !flagaRenderuMapy;
                }

            }


            if (flagaRuchu) {
                board.move(znak);
                while (board.lvl == 1 && !flagaRenderuMapy) {

                    lvl2 lvl2(board);
                    lvl2.rendermap();
                    flagaRenderuMapy = !flagaRenderuMapy;
                }


                while (board.lvl == 2 && flagaRenderuMapy) {
                    lvl3 lvl3(board);
                    lvl3.rendermap();
                    flagaRenderuMapy = !flagaRenderuMapy;

                }

                while (board.lvl == 3 && !flagaRenderuMapy) {
                    lvl4 lvl4(board);
                    lvl4.rendermap();
                    flagaRenderuMapy = !flagaRenderuMapy;
                }

                while (board.lvl == 4 && flagaRenderuMapy) {
                    lvl5 lvl5(board);
                    lvl5.rendermap();
                    flagaRenderuMapy = !flagaRenderuMapy;
                }


                laserEngine.lasery();
                flagaRuchu = !flagaRuchu;
            }

            sf::Text textgame(" -Detele- exit      -F3- restart game     -F4- restart lvl  ", font, 18);
            sf::Text textgame2(" -F5- lvl down     -F6- lvl up  ", font, 18);
            textgame.setPosition(30, 0);
            textgame2.setPosition(150, 25);
            window.draw(textgame);
            window.draw(textgame2);
            view.draw(window);


            while (board.lvl == lastLvl) {    //ekran koncowy

                window.clear(sf::Color::Black);;
                sf::Text textf1("Press    -F1-    key to play again", font, 18);
                sf::Text textdelete("Press    -Detele-   key to exit", font, 18);
                textf1.setPosition(0, 0);
                textdelete.setPosition(0, 30);
                window.draw(textf1);
                window.draw(textdelete);
                window.display();

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1)) {
                    Sleep(500);
                    goto reapet;
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Delete)) {
                    exit(0);
                }
            }


            window.display();
        }
    }

    return 0;
}

