
#include <iostream>
#include <ctime>

#include "Game.h"
#include "Pokemon.h"

int Pokemon::count = 0;


int main() {
    srand(time(nullptr));
    Game game;

    game.play();


    return 0;
}
