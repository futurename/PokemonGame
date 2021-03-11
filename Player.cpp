
#include "Player.h"

#include <iostream>

using namespace std;


Player::Player(string name) : name(name) {}

string Player::getName() const {
    return name;
}
