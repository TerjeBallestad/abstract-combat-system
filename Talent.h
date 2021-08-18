#pragma once

#include <string>
#include "ACS.h"

class Talent {
public:
    std::string name = std::string("no talent");
    int energyPerTurn = 0;
    BaseType north, south, east, west;
    Talent(std::string name_, int energyPerTurn_, BaseType n,BaseType s,BaseType e,BaseType w);
    std::string toString() {
        return name;
    }
};
