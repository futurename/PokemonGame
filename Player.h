#pragma once

#include <iostream>
#include <vector>
#include "Pokemon.h"

using namespace std;

class Player {
private:
    string name;
    vector<Pokemon> playerPokemons;


public:
    Player(string name);

    string getName() const;

    vector<Pokemon> getPokemons();

    void addPokenmon(Pokemon pokemon);

    bool removePokemon(Pokemon pokemon);

    void recoverBloodPoints(double ratio);

    void setPokenmons(vector<Pokemon> pokemons);
};

