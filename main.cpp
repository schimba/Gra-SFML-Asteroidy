#include "Game.h"
#include "ParametryOkna.h"



int main(int, char const**) {
    srand(time(NULL));

    Game game;
    game.startMenu();
    return EXIT_SUCCESS;
}
