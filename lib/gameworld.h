#ifndef GAMEWORLD_H
#define GAMEWORLD_H

#include "SFML/Graphics.hpp"

#include "constant.h"
#include "player.h"
#include "object.h"
#include "item.h"
#include "menu.h"

#include <map>
#include <ctime>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

namespace LevelInfo {
	struct SLevelInfo { // information about objects
		int id; // level id
		std::vector <Object*> objs;
		std::vector <Item*> items;
	};

	extern vector <SLevelInfo> levels;

    void init(); // Initiate all level
}

class GameWorld {
public:
    GameWorld();
    ~GameWorld();
    void welcome();
    void loading();

private:
    bool isRunning;
    int globalVolume;

    void runLevel(int idLevel);
    void setting(int idBG);
    int menuAllInOne(Menu& menu, int idBG = -1);

    void initBackground(int id, string src);
    void temporaryMessage(string message, float delaySecond = 3.0, bool cleanScreen = false, float coorX = SCREEN_WIDTH / 2, float coorY = SCREEN_HEIGHT / 2, int sz = 35, string srcFont = "asset\\font\\ARCADECLASSIC.TTF");
    //int pauseScreen();

    sf::RenderWindow window;

    Player person;
    vector <Object*> objects;
	vector <Item*> items;

    vector <sf::Texture> backgroundTextures;
    vector <sf::Sprite> backgroundTexts;
};

#endif