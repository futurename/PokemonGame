
#include <iostream>
#include <ctime>

#include "Game.h"
#include "Pokemon.h"

int Pokemon::count = 0;


int main() {
    srand(time(0));
    Game game;
    map<int, Pokemon> map = game.getPokenmonType();
    for (pair<int, Pokemon> p: map) {
        p.second.printPokemon();
    }

    game.play();


    return 0;
}
