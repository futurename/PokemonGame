
#include "Pokemon.h"

#include <iostream>
#include <iomanip>

using namespace std;


Pokemon::Pokemon(string &name, int bloodPoints, int attackValue, string &type, string &symbol) {
    this->name = name;
    this->bloodPoints = bloodPoints;
    this->attackValue = attackValue;
    this->type = type;
    this->symbol = symbol;
    this->experiencePoints = 0;
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
         << setw(typeWidth) << type << endl;

    cout << symbol << endl;
}

