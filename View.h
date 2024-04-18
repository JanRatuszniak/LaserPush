#ifndef VIEW_H_
#define VIEW_H_

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "Board.h"
#include <array>
#include <vector>
#include "windows.h"

class View {
    Board &board;

    std::vector<std::vector<sf::Sprite>> sprites;
    std::array<sf::Texture, 28> textures;

    void initTextures();

    void initSprites();

    void initComponents();

    void updateField(int row, int col);

public:
    explicit View(Board &b);

    sf::Vector2i localPosition;

    void draw(sf::RenderWindow &win);
};

#endif
