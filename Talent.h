#pragma once

#include <string>
#include "ACS.h"

class Talent {
public:
    std::string name = std::string("no talent");
    float energyPerTurn = 0;
    bool hidden = false;
    BaseType north, south, east, west;
    Talent(std::string name_, int energyPerTurn_, BaseType n,BaseType s,BaseType e,BaseType w, bool hidden);
    std::string ToString() {
        return name;
    }
};
