
#include <iostream>
#include "Policy.h"

using namespace std;

class EasyPolicy : public Policy{
public:
    int modifyBloodPoints() override;

    int modifyAttackPoints() override;
};

