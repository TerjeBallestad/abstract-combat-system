#pragma once

#include <string>
#include "acs.h"

class Talent {
public:
    std::string name = std::string("no talent");
    float energyPerTurn = 0;
    bool hidden = false;
    BaseType north, south, east, west;
    Talent(std::string name_, float energyPerTurn_, BaseType n,BaseType e,BaseType s,BaseType w);
    Talent(std::string name_, BaseType n,BaseType e,BaseType s,BaseType w);
    std::string ToString() {
        return name;
    }
};
