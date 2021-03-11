
#include <iostream>

#include "Game.h"
#include "Pokemon.h"

int Pokemon::count = 0;


int main() {
    Game game;
    map<string, Pokemon> map = game.getPokenmonType();
    for (pair<string, Pokemon> p: map) {
        p.second.printPokemon();
    }

    game.play();
    game.play();


    return 0;
}
