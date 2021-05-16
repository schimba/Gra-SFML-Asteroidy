//
// Created by Piotrek on 2018-06-12.
//
#include "Menu.h"
#include "Game.h"
#include "Level.h"
#include "ParametryOkna.h"



Game::Game():
        running(true), lives(3),gameLevel(2){
points=0;
}

Game::~Game() {
    window.close();
}

int Game::run() {

    createWindow(window);


    Level level(gameLevel, points, lives);
    sf::Clock clock;

    //level.start();
    while (running) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                return EXIT_SUCCESS;
            }
            level.onEvent(event);

        }
        if(level.zeroAsteroids()){
            gameLevel++;
            window.close();
            points=points+level.countPoints();
           // std::cout<<"punkty to: "<<points<<std::endl;
            run();
            return EXIT_SUCCESS;
        }
        if(level.death() && lives > 0){
            lives--;
            window.close();
           // points=points+level.countPoints();
           // std::cout<<"punkty to: "<<points<<std::endl;
            run();
            return EXIT_SUCCESS;
        }
        else if (level.death() && lives == 0){
            window.close();
            //points=points+level.countPoints();
            End();
           // std::cout<<"punkty to: "<<points<<std::endl;
            return EXIT_SUCCESS;

        }

        window.clear();
        level.update(clock.restart().asMilliseconds());
        level.show(window);
        window.display();

    }
    return EXIT_SUCCESS;
}

void Game::createWindow(sf::RenderWindow& okno) {
    if (okno.isOpen())
        okno.close();

    okno.create(sf::VideoMode(APP_WIDTH, APP_HEIGHT), APP_TITLE, sf::Style::Close);
    okno.setKeyRepeatEnabled(true);
    okno.setFramerateLimit(APP_FPS);
}


int Game::startMenu() {
    createWindow(menu);
    sf::RectangleShape Startowa(sf::Vector2f(800.0f,600.0f));
    sf::Texture  startWindow, startWindowActive;
    startWindow.loadFromFile("bg1.png");
    startWindowActive.loadFromFile("bg2.png");
    Startowa.setTexture(&startWindow);
    Menu Glowne;
    sf::Clock clock;

    while (running) {
        sf::Vector2i kursor2 = sf::Mouse::getPosition(menu);
        sf::Event eventMenu;
        while (menu.pollEvent(eventMenu)) {

            if (eventMenu.type == sf::Event::Closed) {
                menu.close();
                return EXIT_SUCCESS;
            }
            if (eventMenu.type == sf::Event::MouseButtonPressed) {
                if (eventMenu.key.code == sf::Mouse::Left) {
                    if(kursor2.x > 246 && kursor2.x < 546 && kursor2.y > 288 && kursor2.y < 388 ){
                        menu.close();
                        run();
                        return EXIT_SUCCESS;
                    }
                }
            }
        }

        if(kursor2.x > 246 && kursor2.x < 546 && kursor2.y > 288 && kursor2.y < 388 ){
            Startowa.setTexture(&startWindowActive);
        }
        else{
            Startowa.setTexture(&startWindow);
        }

        menu.clear();
        Glowne.update(clock.restart().asMilliseconds());
        Glowne.show(menu);
        menu.draw(Startowa);
        menu.display();
    }
    return EXIT_SUCCESS;
}

int Game::End() {
    createWindow(gameOver);

    //Napisy
    sf::RectangleShape Koncowa(sf::Vector2f(800.0f,600.0f));
    sf::Texture  ending;
    ending.loadFromFile("bg3.png");
    Koncowa.setTexture(&ending);

    //WYNIK
    //WYNIK i zycia
    sf::Font font;
    font.loadFromFile("impact.ttf");
    sf::Text wynik;
    std::string napis = std::to_string(points);
    wynik.setFont(font);
    wynik.setCharacterSize(100);
    wynik.setString(napis);
    wynik.setFillColor(sf::Color::Black);
    wynik.setOutlineColor(sf::Color::Yellow);
    wynik.setOutlineThickness(2);
    wynik.setPosition(370,400);




    Menu finish;
    sf::Clock clock;

    while (running) {
        // sf::Vector2i kursor2 = sf::Mouse::getPosition(menu);
        sf::Event eventEnd;
        while (gameOver.pollEvent(eventEnd)) {

            if (eventEnd.type == sf::Event::Closed) {
                menu.close();
                return EXIT_SUCCESS;
            }

        }
        gameOver.clear();
        finish.update(clock.restart().asMilliseconds());
        finish.show(gameOver);
        gameOver.draw(Koncowa);
       // gameOver.draw(wynik);                           //wyświetlenie wyniku? xd
        gameOver.display();
    }
    return EXIT_SUCCESS;
}

