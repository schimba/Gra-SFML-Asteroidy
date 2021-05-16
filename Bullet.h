//
// Created by Piotrek on 2018-06-19.
//

#ifndef ASTEROIDY_BULLET_H
#define ASTEROIDY_BULLET_H

#include <math.h>
#include <SFML/Graphics.hpp>
#include "ParametryOkna.h"

class Bullet: public sf::Drawable, public sf::Transformable {
    static const float lifetime;
    static const float speed;

public:
    Bullet(sf::Vector2f position, float angle);
    ~Bullet();

    bool isAlive();
    void kill();
    void update(float frametime);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
    bool is_alive;
    float remaining_life;
    sf::Vector2f direction;
};

#endif //ASTEROIDY_BULLET_H
