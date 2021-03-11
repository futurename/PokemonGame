#pragma  once

enum Type{GRASS, POISON, ROCK}; // not complete

static Type getTypeFromNumber(int typeNum){
    switch (typeNum) {
        case 0:
            return GRASS;
            break;
        case 1:
            return POISON;
            break;
        case 2:
            return ROCK;
            break;
        default:
            cout << "No such type number: " + to_string(typeNum) << endl;
            break;
    }
}