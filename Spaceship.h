//
// Created by Piotrek on 2018-06-12.
//

#ifndef ASTEROIDY_SPACESHIP_H
#define ASTEROIDY_SPACESHIP_H


#include <math.h>
#include <SFML/Graphics.hpp>
#include "ParametryOkna.h"

class Spaceship: public sf::Drawable, public sf::Transformable {
    static const float acceleration;
    static const float max_speed;
    static const float rotation_speed;

public:
    Spaceship();
    ~Spaceship();

    void reset();
    void update(float frametime);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void onEvent(const sf::Event& event);
    sf::Vector2f spacePoint();
private:
    bool is_alive;
    sf::Vector2f speed;
    sf::ConvexShape shape;
    int turn, v_move;
};

#endif //ASTEROIDY_SPACESHIP_H
