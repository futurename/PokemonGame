#pragma once

#include <vector>
#include <iostream>
#include <map>

#include "Player.h"
#include "Pokemon.h"
#include "Type.h"

using namespace std;

class Game {
private:
    vector<Player> players;
    vector<Pokemon> pokenmonModels;
    vector<Pokemon> activePokenmons;
    void readPokenmonModelsFromFile(string& filename = const_cast<string &>(FILE_NAME));
    static const string FILE_NAME;
    static const int INIT_ACTIVE_POKEMONS = 3;
    static const int INIT_PLAYER_POKEMONS = 2;

public:
    Game();
    ~Game();
    vector<Player> getPlayers() ;
    vector<Pokemon> getPokenmonType();
    void initPlayer(int numOfPlayers);
    void play(int roundLimit = INT_MAX);

    static int getValidInputNumber();

    void playByPlayer(Player &player);

    void initActivePokemons();

    int getRandomNum(int i, const int pokemons);
};
