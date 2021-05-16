//
// Created by Piotrek on 2018-06-15.
//

#ifndef ASTEROIDY_LEVEL_H
#define ASTEROIDY_LEVEL_H


#include "Bullet.h"
#include "Asteroid.h"
#include "Spaceship.h"
#include <SFML/Graphics.hpp>

class Level {
public:
    Level(int count, int newpoints, int newlives);
    ~Level();
    void onEvent(const sf::Event& event);
    void update(float czas);
    void show(sf::RenderTarget& target);
    void start();
    bool zeroAsteroids();
    bool death();
    int countPoints();
    void drawScore(int punkty);

private:
    int count, points, lives;
    Spaceship ship;
    std::vector<Bullet> bullets;
    std::vector<Asteroid> asteroids;
};

#endif //ASTEROIDY_LEVEL_H
