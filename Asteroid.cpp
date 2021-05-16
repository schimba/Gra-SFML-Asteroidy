//
// Created by Piotrek on 2018-06-12.
//

#include "Asteroid.h"



const float Asteroid::speed[3] = {0.03f, 0.05f, 0.07f};
const float Asteroid::radius[3] = {40.0f, 20.0f, 10.0f};

Asteroid::Asteroid(int level,sf::Vector2f spaceshipPosition):
        is_alive(true),
        level(level) {
    int angle = rand() % 360;
    direction = sf::Vector2f(cos(angle * DEG2RAD), sin(angle * DEG2RAD));  //randomowe kierunki z fkcji cos i sin

    do {

        int x = rand() % APP_WIDTH;  //randomowe polozenie z szer i wys okna
        int y = rand() % APP_HEIGHT;
        sf::Vector2f position(x,y);
        setPosition(position);
    }while(checkPoint(spaceshipPosition));



    shape.setPointCount(8); //kola
    shape.setRadius(radius[level]);
    shape.setFillColor(sf::Color::Black);
    shape.setOutlineColor(sf::Color::Yellow);
    shape.setOutlineThickness(3-level);
    shape.setOrigin(radius[level], radius[level]);
}

Asteroid::Asteroid(int level):
        is_alive(true),
        level(level) {
    int angle = rand() % 360;
    direction = sf::Vector2f(cos(angle * DEG2RAD), sin(angle * DEG2RAD));  //randomowe kierunki z fkcji cos i sin
        int x = rand() % APP_WIDTH;  //randomowe polozenie z szer i wys okna
        int y = rand() % APP_HEIGHT;
        sf::Vector2f position(x, y);
        setPosition(position);
    shape.setPointCount(8); //kola
    shape.setRadius(radius[level]);
    shape.setFillColor(sf::Color::Black);
    shape.setOutlineColor(sf::Color::Yellow);
    shape.setOutlineThickness(3-level);
    shape.setOrigin(radius[level], radius[level]);
}
Asteroid::Asteroid(sf::Vector2f position, float angle, int level):  //Asteroida potomna po rozbiciu
        is_alive(true),
        level(level) {
    direction = sf::Vector2f(cos(angle * DEG2RAD), sin(angle * DEG2RAD));   //Nowy kierunek

    setPosition(position);
    shape.setPointCount(8); //koła
    shape.setRadius(radius[level]);
    shape.setFillColor(sf::Color::Black);
    shape.setOutlineColor(sf::Color::Yellow);
    shape.setOutlineThickness(3-level);
    shape.setOrigin(radius[level], radius[level]);
}

Asteroid::~Asteroid() {
}

bool Asteroid::isAlive() {
    return is_alive;
}

void Asteroid::update(float frametime) {     //Update przechodzenia asteroidow przez krawędzie
    if (!is_alive) return;

    sf::Vector2f distance = direction * speed[level] * frametime;
    move(distance);

    sf::Vector2f position = getPosition();

    if (position.x < -radius[level])
        position.x = APP_WIDTH;
    else if (position.x > APP_WIDTH)
        position.x = 0.0f;

    if (position.y < -radius[level])
        position.y = APP_HEIGHT;
    else if (position.y > APP_HEIGHT)
        position.y = 0.0f;
    setPosition(position);
}

void Asteroid::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(shape, states);
}

int Asteroid::getLevel() {
    return level;
}

void Asteroid::breakDown() { //rozbicie do max 2 razy //potem zrobić naliczanie punktów
    level++;

    if (level > 2) {        //
        is_alive = false;
        return;
    }

    shape.setRadius(radius[level]);
    shape.setOutlineThickness(3-level);     //określenie kształtu na podstawie levelu
    shape.setOrigin(radius[level], radius[level]);
    float angle = rand() % 360;
    direction = sf::Vector2f(cos(angle * DEG2RAD), sin(angle * DEG2RAD));
}

bool Asteroid::checkPoint(sf::Vector2f point) {
    float ax = getPosition().x;
    float ay = getPosition().y;

    float px = point.x;
    float py = point.y;

    float sqrDistance = ((ax - px) * (ax - px)) + ((ay - py) * (ay - py));
    float sqrRadius = radius[level] * radius[level];

    return (sqrDistance <= sqrRadius);
}



