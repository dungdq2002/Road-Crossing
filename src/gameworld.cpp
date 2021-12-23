#include "../lib/gameworld.h"

//lane 1,light
// 120,50
//lane 2,light
// 270,200
// lane 3,light
// 420,350
//lane 4,light
//570,500


namespace LevelInfo {
    vector <SLevelInfo> levels;
    void LevelInfo::init() {
        {
            // level 1
            SLevelInfo level1;
            level1.id = 1;

            Object* ship1 = new Spawner("./asset/image/spaceship/spaceship3.png", "", 100, 80, 1.5f, 200, 120, false);
            level1.objs.push_back(ship1);
            Object* light1 = new light("./asset/image/light.png", 10, 10,20,50);
            level1.objs.push_back(light1);

            Object* ship2 = new Spawner("./asset/image/spaceship/spaceship3.png", "", 100, 80, 1.5f, 250, 270, true);
            level1.objs.push_back(ship2);
            /*Object* light2 = new light("light.png", 10, 10, 20, 200);
            level1.objs.push_back(light2);*/
            Object* ship3 = new Spawner("./asset/image/spaceship/spaceship3.png", "", 100, 80, 1.5f, 300, 420, false);
            level1.objs.push_back(ship3);
            /*Object* light3 = new light("light.png", 10, 10, 20, 350);
            level1.objs.push_back(light3);*/
            Object* ship4 = new Spawner("./asset/image/spaceship/spaceship3.png", "", 100, 80, 1.5f, 350, 570, true);
            level1.objs.push_back(ship4);
            /*Object* light4 = new light("light.png", 10, 10, 20, 500);
            level1.objs.push_back(light4);*/
            Item* goal1 = new Item("./asset/image/goal/goal.gif", 40, 40, GOAL);
            goal1->place(rand() % 300 + 50, 20);
            level1.items.push_back(goal1);


            levels.push_back(level1);

        }

        {
            // level 2
            SLevelInfo level2;
            level2.id = 2;

            Object* ship2_0= new Spawner("./asset/image/spaceship/spaceship3.png", "", 100, 80, 0.5f, 200, 350, false);
            level2.objs.push_back(ship2_0);
            Item* goal1 = new Item("./asset/image/goal/goal.gif", 40, 40, GOAL);
            goal1->place(rand() % 300 + 50, 20);
            level2.items.push_back(goal1);
            Item* item2_f = new Item("./asset/image/frozen/frozen.png", 40, 40, FROZEN);
            item2_f->place(300, 100);
            level2.items.push_back(item2_f);
            Item* item2_i = new Item("./asset/image/invisible/invisible.png", 40, 40, INVISIBLE);
            item2_i->place(200, 150);
            level2.items.push_back(item2_i);
            levels.push_back(level2);
        }

        {
            // level 3
            SLevelInfo level3;
            level3.id = 3;

            Object* ship1 = new Spawner("./asset/image/spaceship/spaceship3.png", "", 100, 80, 0.5f, 200, 350, false);
            level3.objs.push_back(ship1);

            Object* ship2 = new Spawner("./asset/image/spaceship/spaceship1.png", "", 100, 80, 1.5f, 200, 500, true);
            level3.objs.push_back(ship2);

            Object* planet1 = new Obstacle("./asset/image/planet/planet2.png", "", 50, 50);
            planet1->place(280, 200);
            level3.objs.push_back(planet1);

            Object* planet2 = new Obstacle("./asset/image/planet/planet2.png", "", 80, 80);
            planet2->place(100, 200);
            level3.objs.push_back(planet2);
            
            Item* goal1 = new Item("./asset/image/goal/goal.gif", 40, 40, GOAL);
            goal1->place(rand() % 300 + 50, 20);
            level3.items.push_back(goal1);
            
            levels.push_back(level3);
        }

        {
            //level 4
            SLevelInfo level4;
            level4.id = 4;

            Object* ship1 = new Spawner("./asset/image/spaceship/spaceship3.png", "", 100, 80, 0.5f, 200, 350, false);
            level4.objs.push_back(ship1);
            Object* ship5 = new Spawner("./asset/image/spaceship/spaceship3.png", "", 100, 80, 5.f, 400, 80, false);
            level4.objs.push_back(ship5);
            Object* ship2 = new Spawner("./asset/image/spaceship/spaceship1.png", "", 100, 80, 1.5f, 200, 500, true);
            level4.objs.push_back(ship2);
            Object* ship3 = new Spawner("./asset/image/spaceship/spaceship2.png", "", 90, 70, 3.f, 150, 80, true);
            level4.objs.push_back(ship3);
            Object* ship4 = new Spawner("./asset/image/spaceship/spaceship2.png", "", 90, 70, 3.f, 250, 80, true);
            level4.objs.push_back(ship4);
            Object* planet1 = new Obstacle("./asset/image/planet/planet2.png", "", 50, 50);
            planet1->place(280, 200);
            level4.objs.push_back(planet1);

            Object* planet2 = new Obstacle("./asset/image/planet/planet2.png", "", 80, 80);
            planet2->place(100, 200);
            level4.objs.push_back(planet2);
            Object* planet3 = new Obstacle("./asset/image/planet/planet1.png", "", 80, 80);
            planet3->place(170, 140);
            level4.objs.push_back(planet3);
            Item* goal1 = new Item("./asset/image/goal/goal.gif", 40, 40, GOAL);
            goal1->place(rand() % 300 + 50, 20);
            level4.items.push_back(goal1);

            levels.push_back(level4);
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
    window(sf::VideoMode(350, 700), "Road Crossing", sf::Style::Close),
    person("./asset/image/spaceShip0.png", 30, 30)
{
    srand(time(0));

    // Enable vertical sync. (vsync)
    window.setVerticalSyncEnabled(true);
    // When a key is pressed, sf::Event::KeyPressed will be true only once
    window.setKeyRepeatEnabled(false);

    LevelInfo::init();

    backgroundTexts.resize(NUM_BACKGROUND);
    backgroundTextures.resize(NUM_BACKGROUND);

    initBackground(0, "./asset/image/background1.jpg");
    initBackground(1, "./asset/image/background2.png");
    initBackground(2, "./asset/image/background3.jpg");
    initBackground(3, "./asset/image/background4.jpg");

    isRunning = true;
}
GameWorld::~GameWorld() {
    for (auto level : LevelInfo::levels) {
        for (auto& obj : level.objs) delete obj;
        for (auto& item : level.items) delete item;
    }
}

void GameWorld::temporaryMessage(string message, float delaySecond, bool cleanScreen, float coorX, float coorY, int sz, string srcFont) {
    if (cleanScreen)
        window.clear(sf::Color::Black);

    sf::Font font; font.loadFromFile(srcFont);
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(sz);
    text.setFillColor(sf::Color::White);
    text.setString(message);
    auto size = text.getGlobalBounds();
    text.setOrigin(size.width / 2, size.height / 2);
    text.setPosition(coorX, coorY);

    window.draw(text);
    window.display();

    sf::sleep(sf::seconds(delaySecond));

    return;
}
int GameWorld::menuAllInOne(Menu& menu, int idBG) {
    window.clear(sf::Color(127, 127, 127));

    while (true) {
        sf::Event event;
        while (window.pollEvent(event))
        {
            //Close the window if a key is pressed or if requested
            if (event.type == sf::Event::Closed) {
                isRunning = false;
                window.close();
            }

            //If a key is released
            if (event.type == sf::Event::KeyReleased)
            {
                switch (event.key.code)
                {
                    //Process the up, down, left and right keys
                case sf::Keyboard::Escape: return -1;
                case sf::Keyboard::Up: menu.moveUp(); break;
                case sf::Keyboard::Down: menu.moveDown(); break;
                case sf::Keyboard::Return: return menu.select();

                default: break;
                }
            }
        }
        if (idBG != -1) window.draw(backgroundTexts[idBG]);
        menu.draw(window);
        window.display();
    }

    throw " oops ??";
    return -1;
}