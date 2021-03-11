#pragma once

#include <iostream>

using namespace std;

class Player {
private:
    string name;

public:
    Player(string name);
    string getName() const;
};

