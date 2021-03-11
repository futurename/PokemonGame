#pragma  once

#include <iostream>
#include "Type.h"

using namespace std;

class Pokemon {
private:
    string name;
    int bloodPoints; // same as HP
    int attackValue;
    int experiencePoints;
    Type type;
    string symbol;
    int id;

public:
    static int count; // increment with each pokemon created, used to create a unique ID.

    Pokemon(string& name, int bloodPoints, int attackValue, Type& type, string& symbol);

    void printPokemon() const;

    // getter





    // setter









};



