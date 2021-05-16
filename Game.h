//
// Created by Piotrek on 2018-06-12.
//

#ifndef ASTEROIDY_GAME_H
#define ASTEROIDY_GAME_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

class Game {
public:
    Game();
    ~Game();
    int run();
    int startMenu();
    void quit();

private:
    void createWindow(sf::RenderWindow &okno);
    int End();
    sf::RenderWindow window;
    sf::RenderWindow menu;
    sf::RenderWindow gameOver;
    bool running;
    int lives;
    int gameLevel, points;
};

#endif //ASTEROIDY_GAME_H
