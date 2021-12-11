#include "menu.h"

Menu::Menu(int numItem, std::string srcFont) {
    if (!font.loadFromFile(srcFont)) throw "Font not found!";
    this->numItem = numItem;
    cursor = 0;
}

Menu::Menu(std::vector <std::string> list, std::string srcFont) {
    if (!font.loadFromFile(srcFont)) throw "Font not found!";
    this->numItem = numItem;
    for (auto& it : list) add(it);
    cursor = 0;
}

void Menu::add(std::string s) {
    if (menu.size() == numItem) throw "Exceed number of items!";

    int id = menu.size();
    sf::Text current;
    current.setFont(font);
    auto color = (id == 0 ? sf::Color::Yellow : sf::Color::White);
    current.setCharacterSize(35);
    current.setFillColor(color);
    current.setString(s);
    current.setPosition(sf::Vector2f(100, 200 + 100 * id));

    menu.push_back(current);
}

void Menu::moveUp() {
    menu[cursor].setFillColor(sf::Color::White);
    cursor = (cursor == 0 ? numItem - 1 : cursor - 1);
    menu[cursor].setFillColor(sf::Color::Yellow);
}

void Menu::moveDown() {
    menu[cursor].setFillColor(sf::Color::White);
    cursor = (cursor == numItem - 1 ? 0 : cursor + 1);
    menu[cursor].setFillColor(sf::Color::Yellow);
}

int Menu::select() {
    return cursor;
}

void Menu::draw(sf::RenderWindow& window) {
    for (auto& it : menu) window.draw(it);
}
