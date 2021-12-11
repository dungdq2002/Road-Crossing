//#include <SFML/Graphics.hpp>
//#include <iostream>
//#include "player.h"
//
//
///*void main(int argc, char** argv[]) {
//	sf::RenderWindow window(sf::VideoMode(350, 720),
//		"First window!");
//	sf::Texture playerTexture;
//	if (!playerTexture.loadFromFile("./asset/image/spaceShip0.png")) {
//		std::cout << "Wrong";
//		exit(0);
//	}
//	
//	sf::Sprite player(playerTexture);
//	player.setScale(0.3f, 0.3f);
//	sf::Vector2u size = playerTexture.getSize();
//	std::cout << size.x;
//	player.setOrigin(size.x / 2, size.y / 2);
//	sf::Vector2f increment(0.4f, 0.4f);
//
//	while (window.isOpen()) {
//		sf::Event event;
//		while (window.pollEvent(event)) {
//			if (event.type == sf::Event::Closed) {
//				// Close window button clicked.
//				window.close();
//			}
//		}
//
//		//Drawing here
//		sf::RectangleShape rectangle(sf::Vector2f(128.0f, 128.0f));
//		rectangle.setFillColor(sf::Color::Red);
//		rectangle.setOrigin(64.0f, 64.0f);
//		rectangle.setPosition(320, 240);
//
//		//clear
//		window.clear(sf::Color(16,16,16,255));
//		player.setPosition(175, 720 - 0.3f*size.y/2);
//		window.draw(player);
//
//		window.display();
//	}
//}*/

#include "gameworld.h"

int main() {
	GameWorld game;
	game.welcome();
}