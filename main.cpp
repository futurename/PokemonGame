
#include <iostream>
#include <ctime>

#include "Game.h"
#include "Pokemon.h"

int Pokemon::count = 0;


int main() {
    srand(time(nullptr));
    Game game;
    vector<Pokemon> map = game.getPokenmonType();
    for (Pokemon& p: map) {
        p.printPokemon();
    }

    game.play();


    return 0;
}
