#pragma once

#include <vector>
#include <string>
#include "ACS.h"
#include "Character.h"
#include "Damage.h"
#include "ACS.h"

using std::string;
using std::vector;

class Talent {
public:
    string name = string("no talent");
    int energyPerTurn = 0;
    BaseType north, south, east, west;
    Talent(string name_, int energyPerTurn_, BaseType n,BaseType s,BaseType e,BaseType w);
    string toString() {
        return name;
    }
};
