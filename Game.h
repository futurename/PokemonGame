#pragma once

#include <vector>
#include <iostream>
#include <map>

#include "Player.h"
#include "Pokemon.h"

using namespace std;

static const string FILE_NAME = "../pokemons.txt";

class Game {
private:
    vector<Player> players;
    map<string, Pokemon> pokenmonModels;
    vector<Pokemon> activePokenmons;
    void readPokenmonsFromFile(string filename = FILE_NAME);

public:
    Game(int numOfPlayers);
    ~Game();
    vector<Player> getPlayers() ;
    map<string, Pokemon> getPokenmonType();

};
