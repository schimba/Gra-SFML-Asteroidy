//
// Created by Piotrek on 2018-06-12.
//

#ifndef ASTEROIDY_ASTEROID_H
#define ASTEROIDY_ASTEROID_H

#include <math.h>
#include <SFML/Graphics.hpp>
#include "ParametryOkna.h"


class Asteroid: public sf::Drawable, public sf::Transformable {
    static const float speed[3];
    static const float radius[3];

public:
    Asteroid(int level,sf::Vector2f spaceshipPosition);
    Asteroid(int level);
    Asteroid(sf::Vector2f position, float angle, int level);
    ~Asteroid();

    bool isAlive();
    int getLevel();
    bool checkPoint(sf::Vector2f point);
    void breakDown();
    void update(float frametime);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
    int level;
    bool is_alive;
    sf::Vector2f direction;
    sf::CircleShape shape;
};


#endif //ASTEROIDY_ASTEROID_H
