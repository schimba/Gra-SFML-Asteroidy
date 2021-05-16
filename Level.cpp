//
// Created by Piotrek on 2018-06-15.
//

#include "Level.h"

Level::Level(int count, int newpoints, int newlives) {
    points=newpoints;
    lives=newlives;
    for (int i=0; i < count; i++) {     //ilosc startowych asteroidów 0wego poziomu
        Asteroid a(0,ship.getPosition());
        asteroids.push_back(a);
    }
}

Level::~Level() {
}

void Level::onEvent(const sf::Event& event) {
    ship.onEvent(event);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        Bullet bullet(ship.getPosition(), ship.getRotation());
        bullets.push_back(bullet);
    }
}

void Level::update(float czas) {                        //wyświetlanie opisane iteratorami kul i asteroid
    ship.update(czas);
    std::vector<Bullet>::iterator start_bullets = bullets.begin();  //wyświetlanie kull i zabicie na podstawie czasu
    while (start_bullets != bullets.end()) {
        if (start_bullets->isAlive()) {
            start_bullets->update(czas);
            ++start_bullets;
        } else
            start_bullets = bullets.erase(start_bullets);
    }

    std::vector<Asteroid>::iterator start_asteroids = asteroids.begin();    // wyświetlanie asteroid w kolejności po Vectorze i zabicie jeżeli isAlive false tzn lvl > 3
    while (start_asteroids != asteroids.end()) { //sprawdzenie czy ostatnia
        if (start_asteroids->isAlive()) {
            start_asteroids->update(czas);
            ++start_asteroids;
        } else
            start_asteroids = asteroids.erase(start_asteroids); //usuniecie ostatniego martwego elementu
    }

    std::vector<Asteroid> new_asteroids;
    start_asteroids = asteroids.begin();

    while (start_asteroids != asteroids.end()) {
        start_bullets = bullets.begin();
        while (start_bullets != bullets.end()) {
            if (!start_bullets->isAlive()) {
                ++start_bullets;
                continue;
            }

            if (start_asteroids->checkPoint(
                    start_bullets->getPosition())) { //sprawdzenie czy bullet wchodzi w asteroide
                start_bullets->kill();
                start_asteroids->breakDown();
                points++;

                if (start_asteroids->isAlive()) {
                    sf::Vector2f position = start_asteroids->getPosition();
                    float angle = rand() % 360;
                    Asteroid a(position, angle, start_asteroids->getLevel());
                    new_asteroids.push_back(
                            a); //przypisanie wart początkowej astroidzie, pozycje kąt oraz level o stopien wyzszy od poprzedniego
                }
                break;
            }
            ++start_bullets;
        }
        ++start_asteroids;
    }
    asteroids.insert(asteroids.end(), new_asteroids.begin(),
                     new_asteroids.end()); //insert(const_iterator __position, _InputIterator __first,_InputIterator __last)

}

void Level::show(sf::RenderTarget& target) {

    //WYNIK i zycia
    sf::Font font;
    font.loadFromFile("impact.ttf");
    sf::Text wynik, zycia;
    std::string napis = std::to_string(points);
    wynik.setFont(font);
    zycia.setFont(font);
    wynik.setCharacterSize(30);
    wynik.setString(napis);
    wynik.setFillColor(sf::Color::Black);
    wynik.setOutlineColor(sf::Color::Yellow);
    wynik.setOutlineThickness(2);
    wynik.setPosition(10,10);
    std::string napis2 = std::to_string(lives);
    zycia.setCharacterSize(30);
    zycia.setString(napis2);
    zycia.setFillColor(sf::Color::Black);
    zycia.setOutlineColor(sf::Color::Red);
    zycia.setOutlineThickness(2);
    zycia.setPosition(10,560);



    target.draw(ship);
    target.draw(wynik);
    target.draw(zycia);
    for(std::vector<Bullet>::iterator it = bullets.begin(); it != bullets.end(); ++it) //petle rysujące wszystkie kule oraz wszystkie asteroidy.
        target.draw(*it);

    for(std::vector<Asteroid>::iterator it = asteroids.begin(); it != asteroids.end(); ++it)
        target.draw(*it);
}

void Level::start() {
}

bool Level::zeroAsteroids() {
    return asteroids.empty();
}

bool Level::death() {
    std::vector<Asteroid>::iterator start_asteroids = asteroids.begin();
    while (start_asteroids != asteroids.end()) {

        if (start_asteroids->checkPoint(ship.getPosition())) { //sprawdzenie czy bullet wchodzi w asteroide
            return true;

        }
        ++start_asteroids;
    }
    return false;
}

int Level::countPoints() {
    return points;
}

void Level::drawScore(int punkty) {
    //points=points+level.countPoints();

}
