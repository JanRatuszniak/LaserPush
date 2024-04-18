#include "View.h"
#include "Board.h"
#include "SFML/Graphics.hpp"

View::View(Board &b) : board(b) {
    initComponents();
}

void View::initComponents() {
    initTextures();
    initSprites();
}

void View::initTextures() {
    for (int i = 0; i < 28; i++) {
        textures[i].loadFromFile("/Users/HP/CLionProjects/LaserPush_JR/textures/texture" + std::to_string(i) + ".png");

    }

}

void View::initSprites() {
    int wys_planszy = board.getBoardHeight();
    int szer_planszy = board.getBoardWidth();

    sprites.resize(wys_planszy);
    for (int i = 0; i < wys_planszy; i++) {
        sprites[i].resize(szer_planszy);
    }

    for (int wiersz = 0; wiersz < wys_planszy; wiersz++) {
        for (int kolumna = 0; kolumna < szer_planszy; kolumna++) {
            int x, y;
            x = 55 + 25 * kolumna;
            y = 55 + 25 * wiersz;
            sprites[wiersz][kolumna].setPosition(x, y);
        }
    }

}

void View::updateField(int wiersz, int kolumna) {
    int stan_pola = board.getFieldInfo(wiersz, kolumna);
    switch (stan_pola) {
        case 3:
            sprites[wiersz][kolumna].setTexture(textures[3]);
            break;
        case 2:
            sprites[wiersz][kolumna].setTexture(textures[2]);
            break;
        case 0:
            sprites[wiersz][kolumna].setTexture(textures[0]);
            break;
        case 1:
            sprites[wiersz][kolumna].setTexture(textures[1]);
            break;
        case 4:
            sprites[wiersz][kolumna].setTexture(textures[4]);
            break;
        case 5:
            sprites[wiersz][kolumna].setTexture(textures[5]);
            break;
        case 6:
            sprites[wiersz][kolumna].setTexture(textures[6]);
            break;
        case 7:
            sprites[wiersz][kolumna].setTexture(textures[7]);
            break;
        case 8:
            sprites[wiersz][kolumna].setTexture(textures[8]);
            break;
        case 9:
            sprites[wiersz][kolumna].setTexture(textures[9]);
            break;
        case 10:
            sprites[wiersz][kolumna].setTexture(textures[10]);
            break;
        case 11:
            sprites[wiersz][kolumna].setTexture(textures[11]);
            break;
        case 12:
            sprites[wiersz][kolumna].setTexture(textures[12]);
            break;
        case 13:
            sprites[wiersz][kolumna].setTexture(textures[13]);
            break;
        case 14:
            sprites[wiersz][kolumna].setTexture(textures[14]);
            break;
        case 15:
            sprites[wiersz][kolumna].setTexture(textures[15]);
            break;
        case 16:
            sprites[wiersz][kolumna].setTexture(textures[16]);
            break;
        case 17:
            sprites[wiersz][kolumna].setTexture(textures[17]);
            break;
        case 18:
            sprites[wiersz][kolumna].setTexture(textures[18]);
            break;
        case 19:
            sprites[wiersz][kolumna].setTexture(textures[19]);
            break;
        case 20:
            sprites[wiersz][kolumna].setTexture(textures[20]);
            break;
        case 21:
            sprites[wiersz][kolumna].setTexture(textures[21]);
            break;
        case 22:
            sprites[wiersz][kolumna].setTexture(textures[22]);
            break;
        case 23:
            sprites[wiersz][kolumna].setTexture(textures[23]);
            break;
        case 24:
            sprites[wiersz][kolumna].setTexture(textures[24]);
            break;
        case 25:
            sprites[wiersz][kolumna].setTexture(textures[25]);
            break;
        case 26:
            sprites[wiersz][kolumna].setTexture(textures[26]);
            break;
        case 27:
            sprites[wiersz][kolumna].setTexture(textures[27]);
            break;
        default:
            return;

    }
}

void View::draw(sf::RenderWindow &win) {


        for (int wiersz = 0; wiersz < board.getBoardHeight(); wiersz++) {
            for (int kolumna = 0; kolumna < board.getBoardWidth(); kolumna++) {
                updateField(wiersz, kolumna);
                win.draw(sprites[wiersz][kolumna]);
            }
        }
    }


