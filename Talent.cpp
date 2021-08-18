#include "Talent.h"

Talent::Talent(std::string name_, int energyPerTurn_, BaseType n,BaseType s,BaseType e,BaseType w, bool hidden_) {
    north = n;
    south = s;
    east = e;
    west = w;
    name = name_;
    energyPerTurn = energyPerTurn_;
    hidden = hidden_;    
}