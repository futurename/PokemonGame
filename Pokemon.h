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

    Pokemon();

    Pokemon(string &name, int bloodPoints, int attackValue, Type &type, string &symbol, int id = -1);

    //copy constructor
    Pokemon(Pokemon const &pokemon);

    void printPokemon() const;

    // getter
    string getName() const;

    int getBloodPoints();

    int getAttackValue();

    int getExperiencePoints();

    Type getType();

    string getSymbol();

    int getId();

    // setter
    void setName(string pname);

    void setBloodPoints(int point);

    void setAttackValue(int aValue);

    void setExperiencePoints(int exPoints);

    void setType(Type ptype);

    void setSymbol(string pSymbol);

    void setId(int pid);


};



