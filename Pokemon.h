#pragma  once

#include <iostream>

using namespace std;

class Pokemon {
private:
    string name;
    int bloodPoints;
    int attackValue;
    int experiencePoints;
    string type;
    string symbol;

public:
    Pokemon(string& name, int bloodPoints, int attackValue, string& type, string& symbol);

    void printPokemon() const;
};



