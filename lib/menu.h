#ifndef MENU_H
#define MENU_H

#include "SFML/Graphics.hpp"
#include <string>
#include <vector>

class Menu {
public:
    Menu(int numItem, std::string srcFont);
    Menu(std::vector <std::string> list, std::string srcFont);
    void add(std::string s);
    void draw(sf::RenderWindow &window);
    void moveUp();
    void moveDown();
    int select();
private:
    int numItem;
    int cursor;
    sf::Font font;
    std::vector <sf::Text> menu;
};

#endif