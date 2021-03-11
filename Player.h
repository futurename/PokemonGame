#pragma once

#include <iostream>
#include <vector>
#include "Pokemon.h"

using namespace std;

class Player {
private:
    string name;
    vector<Pokemon> playerPokemons;
    int playerScore;

public:
    Player(string name);
    string getName() const;
    vector<Pokemon> getPokemons();
    int getPlayerScore();
    void setPlayerScore(int score);
    void addPokenmon(Pokemon pokemon);
    bool removePokemon(Pokemon pokemon);
    void recoverBloodPoints(double ratio);

};

