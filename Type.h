#pragma  once

#include <iostream>

using namespace std;

enum Type {
    GRASS, POISON, ROCK
}; // not complete

static Type getTypeFromNumber(int typeNum) {
    switch (typeNum) {
        case 0:
            return GRASS;
        case 1:
            return POISON;
        case 2:
            return ROCK;
        default:
            cout << "No such type number: " + to_string(typeNum) << endl;
            break;
    }
}

static string getTypeString(Type type) {
    switch (type) {
        case GRASS:
            return "GRASS";
        case POISON:
            return "POISON";
        case ROCK:
            return "ROCK";
        default:
            cout << "No such type: " + to_string(type) << endl;
            break;
    }
}