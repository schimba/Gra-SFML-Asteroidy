//
// Created by Piotrek on 2018-06-19.
//

#ifndef ASTEROIDY_MENU_H
#define ASTEROIDY_MENU_H
#include "Asteroid.h"
#include <iostream>
#include <SFML/Graphics.hpp>

class Menu {
    std::vector<Asteroid> asteroidy;
    int points;
public:
    Menu();
    ~Menu();
    void update(float czas);
    void show(sf::RenderTarget& target);
};


#endif //ASTEROIDY_MENU_H
