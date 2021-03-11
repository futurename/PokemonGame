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
    static const string FILE_NAME;
    static const int INIT_ACTIVE_POKEMONS = 3;
    static const int INIT_PLAYER_POKEMONS = 2;
    static const int DEFAULT_PLAYER_NUM = 2;

    void readPokenmonModelsFromFile(string &filename = const_cast<string &>(FILE_NAME));

    vector<Pokemon> createPokenmonVector(int pokemons);

public:
    Game();

    ~Game();

    vector<Player> getPlayers();

    vector<Pokemon> getPokenmonType();

    void initPlayer(int numOfPlayers = DEFAULT_PLAYER_NUM);

    void play(int roundLimit = INT_MAX);

    static int getValidInputNumber();

    static void playByPlayer(Player &player);

    void initActivePokemons();

    int getRandomNum(int i, int pokemons);


};
