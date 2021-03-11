// the move will be downloaded from the website 
// https://pokemondb.net/move/all

#pragma  once

#include <string>
#include "Type.h"
#include "Category.h"

using namespace std;


class Move{
    public: // we can make them private and instore getter setter after
        string name;
        Type type ;
        Category category;
        int power;
        string info; // description of the move


};
