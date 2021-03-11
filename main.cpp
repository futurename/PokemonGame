
#include <iostream>

#include "Game.h"

int main() {
    Game game;
    map<string, Pokemon> map = game.getPokenmonType();
    for (pair<string, Pokemon> p: map) {
        p.second.printPokemon();
    }

    game.play();


    return 0;
}
