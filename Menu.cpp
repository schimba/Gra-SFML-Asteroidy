//
// Created by Piotrek on 2018-06-19.
//

#include "Menu.h"

Menu::Menu() {
    for (int i=0; i < 10; i++) {
        Asteroid a(0);
        asteroidy.push_back(a);
    }
}

Menu::~Menu() {

}

void Menu::update(float czas) {
    std::vector<Asteroid>::iterator start_asteroids = asteroidy.begin();
    while (start_asteroids != asteroidy.end()) {
        if (start_asteroids->isAlive()) {
            start_asteroids->update(czas);
            ++start_asteroids;
        } else
            start_asteroids = asteroidy.erase(start_asteroids);
    }

    std::vector<Asteroid> new_asteroids;
    start_asteroids = asteroidy.begin();
}

void Menu::show(sf::RenderTarget &target) {

    for(std::vector<Asteroid>::iterator it = asteroidy.begin(); it != asteroidy.end(); ++it)
        target.draw(*it);
}
