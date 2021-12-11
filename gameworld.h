#ifndef GAMEWORLD_H
#define GAMEWORLD_H

#include "SFML/Graphics.hpp"

#include "constant.h"
#include "player.h"
#include "object.h"
#include "item.h"
#include "menu.h"

#include <vector>
#include <string>

using namespace std;

namespace LevelInfo {
	struct SLevelInfo { // information about objects
		int id; // level id
		std::vector <Object*> objs;
	};

	extern vector <SLevelInfo> levels;

    void init(); // Initiate all level
}

class GameWorld {
public:
    GameWorld();
    void welcome();
    void runLevel(int idLevel);

private:
    bool isRunning;

    void initBackground(int id, string src);

    sf::RenderWindow window;

    Player person;
    vector <Object*> objects;

    int numLevel;

    int numBG;
    vector <sf::Texture> backgroundTextures;
    vector <sf::Sprite> backgroundTexts;
};

#endif