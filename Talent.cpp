#include "Talent.h"

Talent::Talent(std::string name_, float energyPerTurn_, BaseType n,BaseType e,BaseType s,BaseType w, bool hidden_) {
    north = n;
    east = e;
    south = s;
    west = w;
    name = name_;
    energyPerTurn = energyPerTurn_;
    hidden = hidden_;    
}