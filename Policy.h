/*
 Created by Wei Wang on 3/11/2021 011.
*/

#ifndef POKEMONGAME_POLICY_H
#define POKEMONGAME_POLICY_H


#include <iostream>

using namespace std;

class Policy {
public:
    virtual int modifyBloodPoints() = 0;

    virtual int modifyAttackPoints() = 0;
};


#endif //POKEMONGAME_POLICY_H
