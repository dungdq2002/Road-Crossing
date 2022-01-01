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
        
    globalVolume = 4;
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
        if (idBG != -1) {
            auto color = backgroundTexts[idBG].getColor();
            backgroundTexts[idBG].setColor(sf::Color(color.r, color.g, color.b, 200));
            window.draw(backgroundTexts[idBG]);
        }
        menu.draw(window);
        window.display();
    }

    throw " oops ??";
    return -1;
}

void GameWorld::setting(int idBG) {
    window.clear(sf::Color(127, 127, 127));

    sf::Text sfx;
    sf::Font font;
    font.loadFromFile("asset\\font\\ARCADECLASSIC.TTF");
    sfx.setFont(font);
    auto color = sf::Color::Yellow;
    sfx.setFillColor(color);
    sfx.setString("SFX");
    sfx.setCharacterSize(25);
    sfx.setPosition(100, 200);

    sf::Text volume;
    volume.setFont(font);
    color = sf::Color::White;
    volume.setFillColor(color);
    volume.setCharacterSize(25);
    volume.setPosition(200, 200);

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
                case sf::Keyboard::Escape: return;
                case sf::Keyboard::Left: (globalVolume += 4) %= 5; break;
                case sf::Keyboard::Right: (++globalVolume) %= 5; break;
                default: break;
                }
            }
        }
        sf::Listener::setGlobalVolume(globalVolume * 25);
        volume.setString(to_string(globalVolume * 25));
        if (idBG != -1) {
            auto color = backgroundTexts[idBG].getColor();
            backgroundTexts[idBG].setColor(sf::Color(color.r, color.g, color.b, 200));
            window.draw(backgroundTexts[idBG]);
        }
        window.draw(sfx);
        window.draw(volume);
        window.display();
    }
}

void GameWorld::welcome() {
    sf::Music musicBG;
    musicBG.openFromFile("./asset/sound/Athletic Theme - Yoshi's Island.wav");

    musicBG.setLoop(true);

	int idBG = rand() % NUM_BACKGROUND;

    cout << "menu " << idBG << '\n';

	Menu menu(4, "asset\\font\\ARCADECLASSIC.TTF");

	menu.add("New Game");
	menu.add("Load Game");
    menu.add("Setting");
	menu.add("Exit");
    
    musicBG.play();

    while (window.isOpen()) {
        //window.draw(backgroundTexts[idBG]);
        //sf::Listener::setGlobalVolume(globalVolume * 25);
        int t = menuAllInOne(menu, idBG);
        switch (t) {
        case 0:
            std::cout << "go to new game\n";
            musicBG.stop();
            runLevel(0);
            musicBG.play();
            break;
        case 1: {
            cout << " load game \n";
            Menu data(5, "asset\\font\\CONSOLAB.TTF");

            auto zeroPadding = [&](string& s, int sz = 2) {
                while (s.size() < sz) s.insert(s.begin(), '0');
                return s;
            };

            map <int, int> m;
            for (int i = 0; i < 5; i++) {
                ifstream inp("./log/" + to_string(i) + ".txt");
                if (!inp) {
                    cout << "file " << i << " is not existed\n";
                    data.add(to_string(i + 1) + ". ==============");
                }
                else {
                    int LV; inp >> LV; 
                    m[i] = LV;
                    LV++;
                    string lv = to_string(LV);
                    string day, month, year; inp >> day >> month >> year;
                    data.add(to_string(i + 1) + ". L" + zeroPadding(lv) + " " + zeroPadding(day) + "-" + zeroPadding(month) + "-" + zeroPadding(year, 4));
                }
                inp.close();
            }

            
            int t = menuAllInOne(data, idBG);
            cout << t << '\n';
            if (t == -1) break;
            musicBG.stop();
            if (m.count(t)) {
                runLevel(m[t]);
            }
            else runLevel(0);  
            musicBG.play();
            break;
        }
        case 2: {
            cout << "sound setting\n";
            setting(idBG);
            break;
        }
        case 3:
            isRunning = false;
            break;
        }
        
        if (!isRunning) {
            musicBG.stop();
            break;
        }
    }
}

void GameWorld::runLevel(int idLevel) {
    // instruction
    if (idLevel == 0)
        temporaryMessage("Press Arrow keys\n\tto move", 1.5, true, SCREEN_WIDTH / 2, 200, 25, "asset\\font\\CONSOLAB.TTF");
    else if (idLevel == 1)
        temporaryMessage("Press Z - Invisible\n\nPress X - Frozen", 2.0, true, SCREEN_WIDTH / 2, 200, 25, "asset\\font\\CONSOLAB.TTF");

    sf::Font font; font.loadFromFile("asset\\font\\CONSOLAB.TTF");
    sf::Text levelLogo;

    levelLogo.setFont(font);
    levelLogo.setString("LEVEL " + to_string(idLevel + 1));
    levelLogo.setPosition(10, 670);
    levelLogo.setCharacterSize(15);

    // count item duration
    //frozen
    bool countDown1 = false;
    sf::Clock clock1;
    sf::Time time1;
    //invisible
    bool countDown2 = false;
    sf::Clock clock2;
    sf::Time time2;
    //green light duration
    bool countDown3 = false;
    sf::Clock clock3;
    sf::Time time3;
    // red light duration
    bool countDown4 = false;
    sf::Clock clock4;
    sf::Time time4;

    int idBG = rand() % NUM_BACKGROUND;
    cout << idBG << '\n';

    objects = LevelInfo::levels[idLevel].objs;
	items = LevelInfo::levels[idLevel].items;

    person.Reset();

    // Flags for key pressed
    bool upFlag = false;
    bool downFlag = false;
    bool leftFlag = false;
    bool rightFlag = false;
    int test = 0;

    bool winGame = false;
    bool loseGame = false;
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
                    // If P is pressed, pause game
                case sf::Keyboard::P: {
                    Menu pauseScr(3, "asset\\font\\ARCADECLASSIC.TTF");
                    
                    pauseScr.add("Continue");
                    pauseScr.add("Save");
                    pauseScr.add("Quit");

                    switch (menuAllInOne(pauseScr, idBG)) {
                    case 0:
                        std::cout << "continue\n";
                        break;
                    case 1: {
                        // save game
                        Menu data(5, "asset\\font\\CONSOLAB.TTF");

                        auto zeroPadding = [&](string& s, int sz = 2) {
                            while (s.size() < sz) s.insert(s.begin(), '0');
                            return s;
                        };

                        map <int, int> m;
                        for (int i = 0; i < 5; i++) {
                            ifstream inp("./log/" + to_string(i) + ".txt");
                            if (!inp) {
                                cout << "file " << i << " is not existed\n";
                                data.add(to_string(i + 1) + ". ==============");
                            }
                            else {
                                int LV; inp >> LV;
                                m[i] = LV;
                                LV++;
                                string lv = to_string(LV);
                                string day, month, year; inp >> day >> month >> year;
                                data.add(to_string(i + 1) + ". L" + zeroPadding(lv) + " " + zeroPadding(day) + "-" + zeroPadding(month) + "-" + zeroPadding(year, 4));
                            }
                            inp.close();
                        }

                        int t = menuAllInOne(data, idBG);
                        if (t == -1) break;

                        ofstream out("./log/" + to_string(t) + ".txt");

                        time_t timeObj = time(nullptr);
                        tm aTime;
                        localtime_s(&aTime, &timeObj);

                        out << idLevel << ' ' << aTime.tm_mday << ' ' << 1 + aTime.tm_mon << ' ' << 1900 + aTime.tm_year << '\n';
                        cout << "save game\n";
                        break;
                    }
                    case 2:
                        return;
                    }
                    break;
                }
                case sf::Keyboard::X: {
                    //cout << "press X";
                    if (!countDown2 && person.isAbleFrozen()){
                        person.eraseItemFrozen();
                        for (auto& obj : objects) {
                            obj->stop();
                        }
                        temporaryMessage("FROZEN", 0.3, false, 175.0f, 350.0f, 24);
                        clock1.restart();
                        countDown1 = true;
                    }
                    break;
                }
                case sf::Keyboard::Z:
                {
                    if (!countDown1 && person.isAbleInvisible()){
                        person.eraseItemInvisible();
                        person.Transparent();
                        temporaryMessage("INVISIBLE", 0.3, false, 175.0f, 350.0f, 24);
                        clock2.restart();
                        countDown2 = true;
                    }
                    break;
                }
                    // Process the up, down, left and right keys
                case sf::Keyboard::W:
                case sf::Keyboard::Up: {
                    upFlag = true; 
                    person.sound1();
                    break;

                }
                case sf::Keyboard::S:
                case sf::Keyboard::Down:    downFlag = true; person.sound1(); break;

                case sf::Keyboard::A:
                case sf::Keyboard::Left:    leftFlag = true; person.sound1(); break;

                case sf::Keyboard::D:
                case sf::Keyboard::Right:   rightFlag = true; person.sound1(); break;
                default: break;
                }
            }

            // If a key is released
            if (event.type == sf::Event::KeyReleased)
            {
                switch (event.key.code)
                {
                    // Process the up, down, left and right keys
                case sf::Keyboard::W:
                case sf::Keyboard::Up:     upFlag = false; break;
                case sf::Keyboard::S:
                case sf::Keyboard::Down:    downFlag = false; break;
                case sf::Keyboard::A:
                case sf::Keyboard::Left:    leftFlag = false; break;
                case sf::Keyboard::D:
                case sf::Keyboard::Right:   rightFlag = false; break;
                default: break;
                }
            }

        //if (!person.listItem.empty()) {

        //    if (event.type == sf::Event::KeyPressed)
        //    {
        //        switch (event.key.code)
        //        {
        //            // If P is pressed, pause game
        //        
        //        default:break;
        //        }

        //    }
        //}
        }
        if (!countDown3 && !countDown4) {
            countDown3 = true;
            clock3.restart();
            for (auto& obj : objects) {
                obj->continueRun();
            }

        }
        if (countDown3 && clock3.getElapsedTime().asSeconds() > GREEN_LIGHT) {
            countDown3 = false;
            clock4.restart();
            for (auto& obj : objects) {
                obj->stop();
            }
            for (auto& obj : objects) {
                obj->changeState();
            }
            countDown4 = true;
        }
       
        if (countDown4 && clock4.getElapsedTime().asSeconds() > RED_LIGHT) {
            countDown4 = false;
            clock3.restart();
            for (auto& obj : objects) {
                obj->continueRun();
            }
            for (auto& obj : objects) {
                obj->changeState();
            }
            countDown3 = true;
        }

        // time for item
        if (countDown1) {
            time1 = clock1.getElapsedTime();
            if (time1.asSeconds() > ACTIVATE_FROZEN_TIME) {
                countDown1 = false;
                for (auto& obj : objects) {
                    obj->continueRun();
                }
            }
        }
        if (countDown2) {
            time2 = clock2.getElapsedTime();
            if (time2.asSeconds() > ACTIVATE_INVISIBLE_TIME) {
                countDown2 = false;
                person.unTransparent();
            }
        }


        //
        if (leftFlag) {
            cout << "left\n"; 
            person.SetDirection(DirectionPlayer::Left);
            person.Move();
        } 
        if (rightFlag) {
            cout << "right\n";  
            person.SetDirection(DirectionPlayer::Right);
            person.Move();
        }
        if (upFlag) {
            cout << "up\n";  
            person.SetDirection(DirectionPlayer::Up);
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

/*
    If reach GOAL, check idLevel vs NUM_LEVEL (in constant.h)
*/

        // Move Object
        for (auto& obj : objects) obj->move();

        // Draw Background, Player and Objects
        window.draw(backgroundTexts[idBG]);
        window.draw(levelLogo);
        for (auto& obj : objects) obj->render(window);
        person.Render(window);
        
        for (auto& item : items) {
            if (item->isFrozen() || item->isInvisible())
                item->falling(0.5);
            item->render(window);
        }

        sf::Texture __frozen__; __frozen__.loadFromFile("./asset/image/frozen/frozen.png");
        sf::Sprite __frozen; __frozen.setTexture(__frozen__); 
        auto __szfrozen = __frozen.getGlobalBounds();
        __frozen.setScale(25 / __szfrozen.width, 25 / __szfrozen.height);
        __frozen.setOrigin(__szfrozen.width / 2, __szfrozen.height / 2);
        __frozen.setPosition(280, 680);
        if (person.isAbleFrozen()) {
            window.draw(__frozen);
        }

        sf::Texture __invisible__; __invisible__.loadFromFile("./asset/image/invisible/invisible.png");
        sf::Sprite __invisible; __invisible.setTexture(__invisible__);
        auto __szinvisible = __invisible.getGlobalBounds();
        __invisible.setScale(25 / __szinvisible.width, 25 / __szinvisible.height);
        __invisible.setOrigin(__szinvisible.width / 2, __szinvisible.height / 2);
        __invisible.setPosition(320, 680);
        if (person.isAbleInvisible()) {
            window.draw(__invisible);
        }

        // reach goal
        // first element is goal, second element is item
        if (person.isImpact(items[0])) {
            winGame = true;
            break;
        }
        // catch item
        for (int i = 1; i < items.size(); i++) {
            if (person.isImpact(items[i])) {
                /*sf::SoundBuffer bufferTem;
                sf::Sound soundTem;
                bufferTem.loadFromFile("./asset/sound/collision.wav");
                soundTem.setBuffer(bufferTem);
                soundTem.play();*/
                person.sound();
                //sf::sleep(sf::seconds(0.1));
                person.addItem(*items[i]);              
                items.erase(items.begin() + i, items.begin() + i + 1);
            }
        }
        // use item
        /*
            Use item was implemented when receive event above
        */


        // Collide with the objects
        for (auto& obj : objects) if (!countDown2 && person.isImpact(obj)) {
            sf::SoundBuffer bufferTem;
            sf::Sound soundTem;
            bufferTem.loadFromFile("./asset/sound/collision.wav");
            soundTem.setBuffer(bufferTem);
            soundTem.play();
            cout << "Game over\n";
            
            temporaryMessage("GAME OVER");
            loseGame = true;
            break;
        }
        if (loseGame) break;
        
        // Rotate and draw the sprite
        window.display();
    }

    if (winGame) {
        if (idLevel == NUM_LEVEL - 1) {
            cout << "game clear";
            temporaryMessage("GAME CLEAR");
        }
        else {
            temporaryMessage("Pass", 1.0);
            runLevel(idLevel + 1);
        }
    }
    else if (loseGame) runLevel(idLevel);
}
