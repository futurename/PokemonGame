
#include <iostream>

#include "Game.h"

int main() {
    Game game(3);

    map<string, Pokemon> map = game.getPokenmonType();

    cout << map.size() << endl;

    for (pair<string, Pokemon> p: map) {
        p.second.printPokemon();
    }


    return 0;
}
