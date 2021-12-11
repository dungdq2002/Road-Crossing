#include "gameworld.h"

namespace LevelInfo {
    vector <SLevelInfo> levels;
    void LevelInfo::init() {
        {
            // level 1
            SLevelInfo level1;
            level1.id = 1;

            Spawner ship1("spaceship1.png", "", 80, 40, 0.2f, 30, 40, false);
            level1.objs.push_back(&ship1);


            levels.push_back(level1);
        }
    }
}

void GameWorld::initBackground(int id, string src) {
	backgroundTextures[id].loadFromFile(src);
	backgroundTexts[id].setTexture(backgroundTextures[id]);
	auto sz = backgroundTexts[id].getGlobalBounds();
	backgroundTexts[id].setScale(SCREEN_WIDTH / sz.width, SCREEN_HEIGHT / sz.height);
}

GameWorld::GameWorld() :
	window(sf::VideoMode(350, 700), "Road Crossing"),
	person("./asset/image/spaceShip0.png", 30, 30) 
{
	// Enable vertical sync. (vsync)
	window.setVerticalSyncEnabled(true);
	// When a key is pressed, sf::Event::KeyPressed will be true only once
	window.setKeyRepeatEnabled(false);

	LevelInfo::init();

    numLevel = 1; // number of levels

	numBG = 4; // number of available backgrounds
	backgroundTexts.resize(numBG);
	backgroundTextures.resize(numBG);

	initBackground(0, "./asset/image/background1.jpg");
	initBackground(1, "./asset/image/background2.png");
	initBackground(2, "./asset/image/background3.jpg");
	initBackground(3, "./asset/image/background4.jpg");

    isRunning = true;
}

void GameWorld::welcome() {
	int idBG = rand() % numBG;

	Menu menu(3, "asset\\font\\ARCADECLASSIC.TTF");

	menu.add("New Game");
	menu.add("Load Game");
	menu.add("Exit");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close the window if a key is pressed or if requested
            if (event.type == sf::Event::Closed) window.close();

            // If a key is released
            if (event.type == sf::Event::KeyReleased)
            {
                switch (event.key.code)
                {
                    // Process the up, down, left and right keys
                case sf::Keyboard::Up:    menu.moveUp(); break;
                case sf::Keyboard::Down:  menu.moveDown(); break;
                case sf::Keyboard::Return:
                    switch (menu.select()) {
                    case 0:
                        std::cout << "go to game\n";
                        runLevel(0);
                        break;
                    default: break;

                    }
                default: break;
                }
            }
        }

        if (!isRunning) break;

        window.draw(backgroundTexts[idBG]);
        menu.draw(window);
        window.display();
    }
}

void GameWorld::runLevel(int idLevel) {
    int idBG = rand() % numBG;

    person.Reset();

    // Flags for key pressed
    bool upFlag = false;
    bool downFlag = false;
    bool leftFlag = false;
    bool rightFlag = false;
    int test = 0;
    // Process events
    while (true) {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close the window if a key is pressed or if requested
            if (event.type == sf::Event::Closed) {
                window.close();
                isRunning = false;
                return;
            }

            // If a key is pressed
            if (event.type == sf::Event::KeyPressed)
            {
                switch (event.key.code)
                {
                    // If escape is pressed, close the application
                case  sf::Keyboard::Escape: window.close(); break;

                    // Process the up, down, left and right keys
                case sf::Keyboard::Up:     upFlag = true; break;
                case sf::Keyboard::Down:    downFlag = true; break;
                case sf::Keyboard::Left:    leftFlag = true; break;
                case sf::Keyboard::Right:   rightFlag = true; break;
                default: break;
                }
            }

            // If a key is released
            if (event.type == sf::Event::KeyReleased)
            {
                switch (event.key.code)
                {
                    // Process the up, down, left and right keys
                case sf::Keyboard::Up:     upFlag = false; break;
                case sf::Keyboard::Down:    downFlag = false; break;
                case sf::Keyboard::Left:    leftFlag = false; break;
                case sf::Keyboard::Right:   rightFlag = false; break;
                default: break;
                }
            }
        }

        // Set direction for movement
        //if (leftFlag) person.SetDirection(DirectionPlayer::Left);
        //if (rightFlag) person.SetDirection(DirectionPlayer::Right);
        //if (upFlag) person.SetDirection(DirectionPlayer::Up);
        //if (downFlag) person.SetDirection(DirectionPlayer::Down);

        if (leftFlag) {
            cout << "left\n";  person.SetDirection(DirectionPlayer::Left);
            person.Move();
        }
        if (rightFlag) {
            cout << "right\n";  person.SetDirection(DirectionPlayer::Right);
            person.Move();
        }
        if (upFlag) {
            cout << "up\n";  person.SetDirection(DirectionPlayer::Up);
            person.Move();
        }
        if (downFlag) {
            cout << "down\n";
            person.SetDirection(DirectionPlayer::Down);
            person.Move();
        }

        // EXPLAIN THE ERRORS
        // Move inside the if, when it receive the button event, move directly
        // The problem of the previous is when up is pressing, and we press left, the if of Up is lower so the left will first set
        // as Direction Left but then go to up when be set as Up, results all UP
        // If we move Left lower than Up, the result will be all LEFT
         
        // Clear the window and apply grey background
        window.clear(sf::Color(127, 127, 127));

        window.draw(backgroundTexts[idBG]);

        // Rotate and draw the sprite
        person.Render(window);
        window.display();
    }
}