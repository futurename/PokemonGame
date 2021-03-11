
#include <iostream>
#include <ctime>

#include "Game.h"
#include "Pokemon.h"

int Pokemon::count = 0;


int main() {
    srand(time(nullptr));
    Game game;

    for(Pokemon& p : game.getPokenmonType()){
        p.printPokemon();
    }

    game.play();


    return 0;
}
