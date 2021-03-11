
#include "Pokemon.h"

#include <iostream>
#include <iomanip>

using namespace std;


Pokemon::Pokemon(string &name, int bloodPoints, int attackValue, Type &type, string &symbol, int id) {
    this->name = name;
    this->bloodPoints = bloodPoints;
    this->attackValue = attackValue;
    this->type = type;
    this->symbol = symbol;
    this->experiencePoints = 0;
    this->id = id;
}

void Pokemon::printPokemon() const {
    const int nameWidth = 10;
    const int numberWidth = 4;
    const int numberHeaderWidth = 9;
    const int typeWidth = 8;
    const string delimitor = " | ";

    cout << setw(nameWidth) << "<Name>" << delimitor
         << setw(numberHeaderWidth) << "<Blood>" << delimitor
         << setw(numberHeaderWidth) << "<Attack>" << delimitor
         << setw(typeWidth) << "Type" << endl;

    cout << setw(nameWidth) << name << delimitor
         << setw(numberWidth + 2) << bloodPoints << setw(numberWidth - 1) << "" << delimitor
         << setw(numberWidth + 2) << attackValue << setw(numberWidth - 1) << "" << delimitor
         << setw(typeWidth) << getTypeString(type) << endl;

    cout << symbol << endl;
}

///////////////getters
string Pokemon::getName() const {
    return name;
}

int Pokemon::getBloodPoints() {
    return bloodPoints;
}

int Pokemon::getAttackValue() {
    return attackValue;
}

int Pokemon::getExperiencePoints() {
    return experiencePoints;
}

Type Pokemon::getType() {
    return type;
}

string Pokemon::getSymbol() {
    return symbol;
}

int Pokemon::getId() {
    return id;
}

/////////////setters
void Pokemon::setName(string pname) {
    name = pname;
}

void Pokemon::setBloodPoints(int points) {
    bloodPoints = points;
}

void Pokemon::setAttackValue(int aValue) {
    attackValue = aValue;
}

void Pokemon::setExperiencePoints(int exPoints) {
    experiencePoints = exPoints;
}

void Pokemon::setType(Type ptype) {
    type = ptype;
}

void Pokemon::setSymbol(string pSymbol) {
    symbol = pSymbol;
}

void Pokemon::setId(int pid) {
    id = pid;
}

//copy constructor
Pokemon::Pokemon(Pokemon const &pokemon) {
   this->name = pokemon.name;
   this->bloodPoints = pokemon.bloodPoints;
   this->attackValue = pokemon.attackValue;
   this->type = pokemon.type;
   this->symbol = pokemon.symbol;
   this->id = ++count;
}

Pokemon::Pokemon() {}


