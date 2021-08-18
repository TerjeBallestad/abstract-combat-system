#include "Talent.h"

Talent::Talent(std::string name_, float energyPerTurn_, BaseType n,BaseType e,BaseType s,BaseType w) {
    north = n;
    east = e;
    south = s;
    west = w;
    name = name_;
    energyPerTurn = energyPerTurn_;
    hidden = false;
}

Talent::Talent(std::string name_, BaseType n,BaseType e,BaseType s,BaseType w) {
    north = n;
    east = e;
    south = s;
    west = w;
    name = name_;
    energyPerTurn = 0;
    hidden = true;    
}