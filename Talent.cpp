#include "Talent.h"

Talent::Talent(std::string name_, int energyPerTurn_, BaseType n,BaseType s,BaseType e,BaseType w) {
    north = n;
    south = s;
    east = e;
    west = w;
    name = name_;
    energyPerTurn = energyPerTurn_;
    
}